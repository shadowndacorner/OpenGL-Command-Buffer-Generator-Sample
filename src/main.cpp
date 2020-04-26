#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <chrono>
#include <stdio.h>
#include <gl_command_buffer.hpp>
#include <gl_resource_manager.hpp>
#include <stb_image.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

SDL_GLContext g_Context;
void init_gl(SDL_Window* window)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	int r, g, b, d, s;
	SDL_GL_GetAttribute(SDL_GL_RED_SIZE, &r);
	SDL_GL_GetAttribute(SDL_GL_GREEN_SIZE, &g);
	SDL_GL_GetAttribute(SDL_GL_BLUE_SIZE, &b);
	SDL_GL_GetAttribute(SDL_GL_DEPTH_SIZE, &d);
	SDL_GL_GetAttribute(SDL_GL_STENCIL_SIZE, &s);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(0);
	g_Context = SDL_GL_CreateContext(window);
	
	int fail = gladLoadGLLoader(SDL_GL_GetProcAddress);
	if (fail == 0)
	{
		SDL_assert(false && "Failed to init OpenGL");
		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}
}

void sdlPumpEvents(bool& running)
{
	SDL_Event ev;
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			running = false;
			return;
		}
	}
}

static const char vertSource[] = R"(
#version 420 core
layout (location = 0) in vec3 pos;
layout (location = 4) in vec3 color0;
layout (location = 5) in vec2 uv0;

layout(binding = 0, std140) uniform FrameConstants
{
	mat4 view_matrix;
	mat4 projection_matrix;
};

layout(binding = 1, std140) uniform ObjectConstants
{
	mat4 model_matrix;
};

out vec3 fColor;
out vec2 fTexCoord;

void main()
{
    gl_Position = projection_matrix * view_matrix * model_matrix * vec4(pos.x, pos.y, pos.z, 1.0);
	fTexCoord = uv0;
	fColor = color0;
}
)";

static const char fragSource[] = R"(
#version 330 core
in vec3 fColor;
in vec2 fTexCoord;
out vec4 FragColor;

uniform sampler2D fragTexture;

void main()
{
    //FragColor = vec4(fTexCoord.r + fColor.r, fTexCoord.g + fColor.g, fColor.b, 1.0f);
	vec4 col = texture(fragTexture, fTexCoord);
	FragColor = vec4(col.rgb * col.a, col.a);
}
)";

namespace graphics
{
	namespace ValueTypeEnum
	{
		enum Enum : uint8_t
		{
			Int8,
			Int16,
			Int32,
			UInt8,
			UInt16,
			UInt32,
			Float16,
			Float32,

			Count,
			Invalid
		};
	};
	typedef ValueTypeEnum::Enum ValueType;

	struct vertex_layout_member
	{
		vertex_layout_member() = default;

		// If offset is 0, it will be automatically computed
		inline vertex_layout_member(uint32_t InputIndex, uint32_t BufferSlot, uint32_t NumComponents, ValueType Type, bool Normalized, uint32_t Offset = 0)
			:
			index(InputIndex),
			buffer_slot(BufferSlot),
			num_components(NumComponents),
			type(Type),
			normalized(Normalized),
			offset(Offset),
			total_size(0)
		{
		}

		inline vertex_layout_member& set_index(uint32_t v)
		{
			index = v;
			return *this;
		}

		inline vertex_layout_member& set_buffer_slot(uint32_t v)
		{
			buffer_slot = v;
			return *this;
		}

		inline vertex_layout_member& set_num_components(uint32_t v)
		{
			num_components = v;
			return *this;
		}

		inline vertex_layout_member& set_type(ValueType v)
		{
			type = v;
			return *this;
		}

		inline vertex_layout_member& set_normalized(bool v)
		{
			normalized = v;
			return *this;
		}

		inline vertex_layout_member& set_offset(uint32_t v)
		{
			offset = v;
			return *this;
		}

		uint32_t index;
		uint32_t buffer_slot;
		uint32_t num_components;
		ValueType type;
		bool normalized;
		uint32_t offset;

		// computed automatically
		uint32_t total_size;
	};

	struct vertex_layout_description
	{
		vertex_layout_description() = default;

		template<size_t count>
		inline vertex_layout_description(vertex_layout_member(&data)[count])
		{
			set_members(data);
			compute_offsets();
		}

		vertex_layout_member* members;
		size_t member_count;

		static inline uint32_t compute_value_size(ValueType type)
		{
			switch (type)
			{
			case ValueType::UInt8:
			case ValueType::Int8:
				return 1;
			case ValueType::Float16:
			case ValueType::UInt16:
			case ValueType::Int16:
				return 2;
			case ValueType::Float32:
			case ValueType::UInt32:
			case ValueType::Int32:
				return 4;
			}
			//BLADE_ERROR_IF(false, "Invalid value type specified");
			return 0;
		}

		template<size_t count>
		inline void set_members(vertex_layout_member(&data)[count])
		{
			members = data;
			member_count = count;
		}

		inline void compute_offsets()
		{
			if (member_count == 0) return;

			members[0].total_size = compute_value_size(members[0].type) * members[0].num_components;
			uint32_t offset = members[0].total_size;

			for (size_t i = 1; i < member_count; ++i)
			{
				auto& member = members[i];
				auto value_size = compute_value_size(member.type);
				member.total_size = value_size * member.num_components;
				if (member.offset == 0)
				{
					member.offset = offset;
					offset += member.total_size;
				}
			}
		}
	};

	struct static_vertex
	{
		static_vertex() = default;

		inline static_vertex(
			glm::vec3 pos,
			glm::vec3 normals = glm::vec3(0, 0, 0),
			glm::vec3 tangents = glm::vec3(0, 0, 0),
			glm::vec3 bitangents = glm::vec3(0, 0, 0),
			glm::vec3 color0 = glm::vec3(0, 0, 0),
			glm::vec2 uv0 = glm::vec2(0, 0)
		) :
			position(pos),
			normals(normals),
			tangents(tangents),
			bitangents(bitangents),
			color0(color0),
			uv0(uv0)
		{

		}

		inline static_vertex(
			glm::vec3 pos,
			glm::vec2 uv0 = glm::vec2(0, 0),
			glm::vec3 normals = glm::vec3(0, 0, 0),
			glm::vec3 tangents = glm::vec3(0, 0, 0),
			glm::vec3 bitangents = glm::vec3(0, 0, 0),
			glm::vec3 color0 = glm::vec3(0, 0, 0)
		) :
			position(pos),
			normals(normals),
			tangents(tangents),
			bitangents(bitangents),
			color0(color0),
			uv0(uv0)
		{

		}

		glm::vec3 position;
		glm::vec3 normals;
		glm::vec3 tangents;
		glm::vec3 bitangents;
		glm::vec3 color0;
		glm::vec2 uv0;

		inline static vertex_layout_description get_vertex_description()
		{
			static vertex_layout_member members[] = {
				// Pos
				vertex_layout_member(0, 0, 3, ValueType::Float32, false),
				// Normals
				vertex_layout_member(1, 0, 3, ValueType::Float32, false),
				// Tangents
				vertex_layout_member(2, 0, 3, ValueType::Float32, false),
				// Bitangents
				vertex_layout_member(3, 0, 3, ValueType::Float32, false),
				// Color0
				vertex_layout_member(4, 0, 3, ValueType::Float32, false),
				// UV0
				vertex_layout_member(5, 0, 2, ValueType::Float32, false),
			};

			return vertex_layout_description(members);
		}
	};

	inline GLenum enum_convert(ValueType val)
	{
		using namespace ValueTypeEnum;
		switch (val)
		{
		case Int8:
			return GL_BYTE;
		case Int16:
			return GL_SHORT;
		case Int32:
			return GL_INT;
		case UInt8:
			return GL_UNSIGNED_BYTE;
		case UInt16:
			return GL_UNSIGNED_SHORT;
		case UInt32:
			return GL_UNSIGNED_INT;
		case Float16:
			return GL_HALF_FLOAT;
		case Float32:
			return GL_FLOAT;
		}
		return 0;
	}

	static multigl::VertexArrayHandle createVertexArray(multigl::CommandBuffer& buffer, const vertex_layout_description& desc)
	{
		auto handle = buffer.CreateVertexArray();
		for (int i = 0; i < desc.member_count; ++i)
		{
			auto& member = desc.members[i];
			buffer.VertexArrayAttribFormat(handle, member.index, member.num_components, enum_convert(member.type), member.normalized ? GL_TRUE : GL_FALSE, member.offset);
			buffer.VertexArrayAttribBinding(handle, member.index, member.buffer_slot);
			buffer.EnableVertexArrayAttrib(handle, member.index);
		}
		return handle;
	}
}

namespace GPUConstants
{
	using namespace glm;
	struct Frame
	{
		mat4 view_matrix;
		mat4 projection_matrix;
	};

	struct Object
	{
		mat4 model_matrix;
	};
}

static GPUConstants::Frame GPU_FrameConstants;
static GPUConstants::Object GPU_ObjectConstants;

int main(int argc, char** argv)
{
	stbi_set_flip_vertically_on_load(true);

    SDL_Init(SDL_INIT_VIDEO);
    auto window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
	init_gl(window);

	using hr_clock = std::chrono::high_resolution_clock;
	
	auto start = hr_clock::now();
	bool running = true;
	
	multigl::ResourceManager resources;
	multigl::CommandBuffer commandBuffer(resources);

	graphics::static_vertex vertexBuffer[] = {
		graphics::static_vertex(glm::vec3(-1, -1, 0), glm::vec2(0, 0)),
		graphics::static_vertex(glm::vec3(-1, 1, 0), glm::vec2(0, 1)),
		graphics::static_vertex(glm::vec3(1, 1, 0), glm::vec2(1, 1)),
		graphics::static_vertex(glm::vec3(1, -1, 0), glm::vec2(1, 0)),
	};

	uint16_t indexBuffer[] = {
		0, 1, 2,
		0, 2, 3
	};

	auto vbo = commandBuffer.CreateBuffer();
	commandBuffer.NamedBufferStorage(vbo, sizeof(vertexBuffer), vertexBuffer, 0);

	auto ibo = commandBuffer.CreateBuffer();
	commandBuffer.NamedBufferStorage(ibo, sizeof(indexBuffer), indexBuffer, 0);

	auto frameUBO = commandBuffer.CreateBuffer();
	commandBuffer.NamedBufferStorage(frameUBO, sizeof(GPU_FrameConstants), 0, GL_DYNAMIC_STORAGE_BIT);

	auto objectUBO = commandBuffer.CreateBuffer();
	commandBuffer.NamedBufferStorage(objectUBO, sizeof(GPU_ObjectConstants), 0, GL_DYNAMIC_STORAGE_BIT);
	
	auto vertexArray = graphics::createVertexArray(commandBuffer, graphics::static_vertex::get_vertex_description());

	int width, height, channels;
	auto data = stbi_load("texture.png", &width, &height, &channels, 0);

	auto texture = commandBuffer.CreateTexture(GL_TEXTURE_2D);
	commandBuffer.TextureStorage2D(texture, 1, GL_RGBA8, width, height);
	commandBuffer.TextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	
	auto vertexShader = commandBuffer.CreateShader(GL_VERTEX_SHADER);
	commandBuffer.ShaderSource(vertexShader, vertSource, sizeof(vertSource) / sizeof(char));
	commandBuffer.CompileShader(vertexShader);

	auto fragShader = commandBuffer.CreateShader(GL_FRAGMENT_SHADER);
	commandBuffer.ShaderSource(fragShader, fragSource, sizeof(fragSource) / sizeof(char));
	commandBuffer.CompileShader(fragShader);

	auto program = commandBuffer.CreateProgram();
	commandBuffer.AttachShader(program, vertexShader);
	commandBuffer.AttachShader(program, fragShader);
	commandBuffer.LinkProgram(program);

	commandBuffer.DetachShader(program, vertexShader);
	commandBuffer.DetachShader(program, fragShader);

	commandBuffer.UniformBlockBinding(program, 0, 0);
	commandBuffer.UniformBlockBinding(program, 1, 1);

	commandBuffer.BindBufferBase(GL_UNIFORM_BUFFER, 0, frameUBO);
	commandBuffer.BindBufferBase(GL_UNIFORM_BUFFER, 1, objectUBO);

	commandBuffer.BindTextureUnit(0, texture);
	commandBuffer.ProgramUniform1i(program, 0, 0);

	while (running)
	{
		auto curTime = hr_clock::now();
		double timeSinceStart = std::chrono::duration<double>(curTime - start).count();

		sdlPumpEvents(running);

		int width, height;
		SDL_GetWindowSize(window, &width, &height);
		// TODO: Run this in another thread
		{
			GPU_FrameConstants.projection_matrix = glm::perspectiveFov<float>(glm::radians<float>(80.f), float(width), float(height), 0.01f, 1000.f);
			GPU_FrameConstants.view_matrix = glm::lookAt(glm::vec3(1, 1, -3), glm::vec3(0), glm::vec3(0, 1, 0));
			GPU_ObjectConstants.model_matrix = glm::mat4(1.0);

			commandBuffer.NamedBufferSubData(frameUBO, 0, sizeof(GPU_FrameConstants), &GPU_FrameConstants);
			commandBuffer.NamedBufferSubData(objectUBO, 0, sizeof(GPU_ObjectConstants), &GPU_ObjectConstants);

			commandBuffer.ClearColor(0, (sinf(float(timeSinceStart)) + 1.0f) / 2.0f, 0, 1);
			commandBuffer.Clear(GL_COLOR_BUFFER_BIT);
			commandBuffer.UseProgram(program);
			commandBuffer.BindVertexArray(vertexArray);
			commandBuffer.VertexArrayVertexBuffer(vertexArray, 0, vbo, 0, sizeof(graphics::static_vertex));
			commandBuffer.BindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
			commandBuffer.DrawElements(GL_TRIANGLES, sizeof(indexBuffer) / sizeof(uint16_t), GL_UNSIGNED_SHORT, 0);
		}

		commandBuffer.ProcessCommands();
		SDL_GL_SwapWindow(window);
	}

    return 0;
}