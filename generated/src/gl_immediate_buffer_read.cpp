#include <gl_immediate_buffer.hpp>
#include <gl_utilities.hpp>

using namespace multigl;
void ImmediateCommandBuffer::ProcessCommands()
{
	while(m_Buffer.has_commands())
	{
		auto cmd = m_Buffer.read_command();
		switch(cmd)
		{
			case CommandId::GetError:
			{
				GL_CHECK(glGetError());
				break;
			}
			case CommandId::GetString:
			{
				GLenum name = m_Buffer.read<GLenum>();
				GL_CHECK(glGetString(name));
				break;
			}
			case CommandId::IsEnabled:
			{
				GLenum cap = m_Buffer.read<GLenum>();
				GL_CHECK(glIsEnabled(cap));
				break;
			}
			case CommandId::GenTexture:
			{
				auto handle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(handle);
				glGenTextures(1, &texture);
				break;
			}
			case CommandId::IsTexture:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GL_CHECK(glIsTexture(texture));
				break;
			}
			case CommandId::IsQuery:
			{
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glIsQuery(id));
				break;
			}
			case CommandId::GenBuffer:
			{
				auto handle = m_Buffer.read<BufferHandle>();
				auto& target = *m_ResourceManager.Buffers.get(handle);
				glGenBuffers(1, &target);
				break;
			}
			case CommandId::IsBuffer:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glIsBuffer(buffer));
				break;
			}
			case CommandId::MapBuffer:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLenum access = m_Buffer.read<GLenum>();
				GL_CHECK(glMapBuffer(target, access));
				break;
			}
			case CommandId::UnmapBuffer:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GL_CHECK(glUnmapBuffer(target));
				break;
			}
			case CommandId::CreateProgram:
			{
				auto handle = m_Buffer.read<ShaderProgramHandle>();
				auto& target = *m_ResourceManager.ShaderPrograms.get(handle);
				target = glCreateProgram();
				break;
			}
			case CommandId::CreateShader:
			{
				auto handle = m_Buffer.read<ShaderHandle>();
				auto& target = *m_ResourceManager.Shaders.get(handle);
				GLenum type = m_Buffer.read<GLenum>();
				target = glCreateShader(type);
				break;
			}
			case CommandId::GetAttribLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetAttribLocation(program, name));
				break;
			}
			case CommandId::GetUniformLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetUniformLocation(program, name));
				break;
			}
			case CommandId::IsProgram:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glIsProgram(program));
				break;
			}
			case CommandId::IsShader:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GL_CHECK(glIsShader(shader));
				break;
			}
			case CommandId::IsEnabledi:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glIsEnabledi(target, index));
				break;
			}
			case CommandId::GetFragDataLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetFragDataLocation(program, name));
				break;
			}
			case CommandId::GetStringi:
			{
				GLenum name = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glGetStringi(name, index));
				break;
			}
			case CommandId::IsRenderbuffer:
			{
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				GL_CHECK(glIsRenderbuffer(renderbuffer));
				break;
			}
			case CommandId::GenRenderbuffer:
			{
				auto handle = m_Buffer.read<RenderbufferHandle>();
				auto& target = *m_ResourceManager.Renderbuffers.get(handle);
				glGenRenderbuffers(1, &target);
				break;
			}
			case CommandId::IsFramebuffer:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GL_CHECK(glIsFramebuffer(framebuffer));
				break;
			}
			case CommandId::GenFramebuffer:
			{
				auto handle = m_Buffer.read<FramebufferHandle>();
				auto& target = *m_ResourceManager.Framebuffers.get(handle);
				glGenFramebuffers(1, &target);
				break;
			}
			case CommandId::CheckFramebufferStatus:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GL_CHECK(glCheckFramebufferStatus(target));
				break;
			}
			case CommandId::MapBufferRange:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr length = m_Buffer.read<GLsizeiptr>();
				GLbitfield access = m_Buffer.read<GLbitfield>();
				GL_CHECK(glMapBufferRange(target, offset, length, access));
				break;
			}
			case CommandId::GenVertexArray:
			{
				auto handle = m_Buffer.read<VertexArrayHandle>();
				auto& target = *m_ResourceManager.VertexArrays.get(handle);
				glGenVertexArrays(1, &target);
				break;
			}
			case CommandId::IsVertexArray:
			{
				GLuint array = m_Buffer.read<GLuint>();
				GL_CHECK(glIsVertexArray(array));
				break;
			}
			case CommandId::GetUniformBlockIndex:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				const GLchar * uniformBlockName = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetUniformBlockIndex(program, uniformBlockName));
				break;
			}
			case CommandId::FenceSync:
			{
				GLenum condition = m_Buffer.read<GLenum>();
				GLbitfield flags = m_Buffer.read<GLbitfield>();
				GL_CHECK(glFenceSync(condition, flags));
				break;
			}
			case CommandId::IsSync:
			{
				GLsync sync = m_Buffer.read<GLsync>();
				GL_CHECK(glIsSync(sync));
				break;
			}
			case CommandId::ClientWaitSync:
			{
				GLsync sync = m_Buffer.read<GLsync>();
				GLbitfield flags = m_Buffer.read<GLbitfield>();
				GLuint64 timeout = m_Buffer.read<GLuint64>();
				GL_CHECK(glClientWaitSync(sync, flags, timeout));
				break;
			}
			case CommandId::GetFragDataIndex:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetFragDataIndex(program, name));
				break;
			}
			case CommandId::IsSampler:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				GL_CHECK(glIsSampler(sampler));
				break;
			}
			case CommandId::GetSubroutineUniformLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum shadertype = m_Buffer.read<GLenum>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetSubroutineUniformLocation(program, shadertype, name));
				break;
			}
			case CommandId::GetSubroutineIndex:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum shadertype = m_Buffer.read<GLenum>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetSubroutineIndex(program, shadertype, name));
				break;
			}
			case CommandId::IsTransformFeedback:
			{
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glIsTransformFeedback(id));
				break;
			}
			case CommandId::CreateShaderProgramv:
			{
				GLenum type = m_Buffer.read<GLenum>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLchar *const* strings = m_Buffer.read<const GLchar *const*>();
				GL_CHECK(glCreateShaderProgramv(type, count, strings));
				break;
			}
			case CommandId::IsProgramPipeline:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				GL_CHECK(glIsProgramPipeline(pipeline));
				break;
			}
			case CommandId::GetProgramResourceIndex:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum programInterface = m_Buffer.read<GLenum>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetProgramResourceIndex(program, programInterface, name));
				break;
			}
			case CommandId::GetProgramResourceLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum programInterface = m_Buffer.read<GLenum>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetProgramResourceLocation(program, programInterface, name));
				break;
			}
			case CommandId::GetProgramResourceLocationIndex:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum programInterface = m_Buffer.read<GLenum>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glGetProgramResourceLocationIndex(program, programInterface, name));
				break;
			}
			case CommandId::GetDebugMessageLog:
			{
				GLuint count = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLenum * sources = m_Buffer.read<GLenum *>();
				GLenum * types = m_Buffer.read<GLenum *>();
				GLuint * ids = m_Buffer.read<GLuint *>();
				GLenum * severities = m_Buffer.read<GLenum *>();
				GLsizei * lengths = m_Buffer.read<GLsizei *>();
				GLchar * messageLog = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetDebugMessageLog(count, bufSize, sources, types, ids, severities, lengths, messageLog));
				break;
			}
			case CommandId::CreateBuffer:
			{
				auto handle = m_Buffer.read<BufferHandle>();
				auto& target = *m_ResourceManager.Buffers.get(handle);
				glCreateBuffers(1, &target);
				break;
			}
			case CommandId::MapNamedBuffer:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLenum access = m_Buffer.read<GLenum>();
				GL_CHECK(glMapNamedBuffer(buffer, access));
				break;
			}
			case CommandId::MapNamedBufferRange:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr length = m_Buffer.read<GLsizeiptr>();
				GLbitfield access = m_Buffer.read<GLbitfield>();
				GL_CHECK(glMapNamedBufferRange(buffer, offset, length, access));
				break;
			}
			case CommandId::UnmapNamedBuffer:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glUnmapNamedBuffer(buffer));
				break;
			}
			case CommandId::CreateFramebuffer:
			{
				auto handle = m_Buffer.read<FramebufferHandle>();
				auto& target = *m_ResourceManager.Framebuffers.get(handle);
				glCreateFramebuffers(1, &target);
				break;
			}
			case CommandId::CheckNamedFramebufferStatus:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GLenum target = m_Buffer.read<GLenum>();
				GL_CHECK(glCheckNamedFramebufferStatus(framebuffer, target));
				break;
			}
			case CommandId::CreateRenderbuffer:
			{
				auto handle = m_Buffer.read<RenderbufferHandle>();
				auto& target = *m_ResourceManager.Renderbuffers.get(handle);
				glCreateRenderbuffers(1, &target);
				break;
			}
			case CommandId::CreateTexture:
			{
				auto target = m_Buffer.read<GLenum>();
				auto handle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(handle);
				glCreateTextures(target, 1, &texture);
				break;
			}
			case CommandId::CreateVertexArray:
			{
				auto handle = m_Buffer.read<VertexArrayHandle>();
				auto& target = *m_ResourceManager.VertexArrays.get(handle);
				glCreateVertexArrays(1, &target);
				break;
			}
			case CommandId::GetGraphicsResetStatus:
			{
				GL_CHECK(glGetGraphicsResetStatus());
				break;
			}
		}
	}
	m_Buffer.reset();
}