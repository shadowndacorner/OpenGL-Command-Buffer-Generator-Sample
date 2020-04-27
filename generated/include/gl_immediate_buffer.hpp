#pragma once
#include <glad/glad.h>
#include "gl_resource_manager.hpp"
#include "raw_rw_buffer.hpp"
#include "gl_function_enums.hpp"

namespace multigl
{
	class ImmediateCommandBuffer
	{
	public:
		ImmediateCommandBuffer(ResourceManager& manager);
		~ImmediateCommandBuffer();

	public:
		void GetError(ErrorCode* returnVal = 0);
		void GetString(StringName name, const GLubyte ** returnVal = 0);
		void IsEnabled(EnableCap cap, GLboolean* returnVal = 0);
		TextureHandle GenTexture();
		void IsTexture(TextureHandle texture, GLboolean* returnVal = 0);
		void IsQuery(GLuint id, GLboolean* returnVal = 0);
		BufferHandle GenBuffer();
		void IsBuffer(BufferHandle buffer, GLboolean* returnVal = 0);
		void MapBuffer(BufferTarget target, BufferAccessARB access, void ** returnVal = 0);
		void UnmapBuffer(BufferTarget target, GLboolean* returnVal = 0);
		ShaderProgramHandle CreateProgram();
		ShaderHandle CreateShader(multigl::ShaderType type);
		void GetAttribLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void GetUniformLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void IsProgram(ShaderProgramHandle program, GLboolean* returnVal = 0);
		void IsShader(ShaderHandle shader, GLboolean* returnVal = 0);
		void IsEnabledi(EnableCap target, GLuint index, GLboolean* returnVal = 0);
		void GetFragDataLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void GetStringi(StringName name, GLuint index, const GLubyte ** returnVal = 0);
		void IsRenderbuffer(RenderbufferHandle renderbuffer, GLboolean* returnVal = 0);
		RenderbufferHandle GenRenderbuffer();
		void IsFramebuffer(FramebufferHandle framebuffer, GLboolean* returnVal = 0);
		FramebufferHandle GenFramebuffer();
		void CheckFramebufferStatus(FramebufferTarget target, FramebufferStatus* returnVal = 0);
		void MapBufferRange(BufferTarget target, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal = 0);
		VertexArrayHandle GenVertexArray();
		void IsVertexArray(GLuint array, GLboolean* returnVal = 0);
		void GetUniformBlockIndex(ShaderProgramHandle program, const GLchar * uniformBlockName, GLuint* returnVal = 0);
		void FenceSync(SyncCondition condition, GLbitfield flags, GLsync* returnVal = 0);
		void IsSync(GLsync sync, GLboolean* returnVal = 0);
		void ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, SyncStatus* returnVal = 0);
		void GetFragDataIndex(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void IsSampler(GLuint sampler, GLboolean* returnVal = 0);
		void GetSubroutineUniformLocation(ShaderProgramHandle program, ShaderType shadertype, const GLchar * name, GLint* returnVal = 0);
		void GetSubroutineIndex(ShaderProgramHandle program, ShaderType shadertype, const GLchar * name, GLuint* returnVal = 0);
		void IsTransformFeedback(GLuint id, GLboolean* returnVal = 0);
		void CreateShaderProgramv(ShaderType type, GLsizei count, const GLchar *const* strings, GLuint* returnVal = 0);
		void IsProgramPipeline(GLuint pipeline, GLboolean* returnVal = 0);
		void GetProgramResourceIndex(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLuint* returnVal = 0);
		void GetProgramResourceLocation(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLint* returnVal = 0);
		void GetProgramResourceLocationIndex(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLint* returnVal = 0);
		void GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* returnVal = 0);
		BufferHandle CreateBuffer();
		void MapNamedBuffer(BufferHandle buffer, BufferAccessARB access, void ** returnVal = 0);
		void MapNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal = 0);
		void UnmapNamedBuffer(BufferHandle buffer, GLboolean* returnVal = 0);
		FramebufferHandle CreateFramebuffer();
		void CheckNamedFramebufferStatus(FramebufferHandle framebuffer, FramebufferTarget target, FramebufferStatus* returnVal = 0);
		RenderbufferHandle CreateRenderbuffer();
		TextureHandle CreateTexture(multigl::TextureTarget target);
		VertexArrayHandle CreateVertexArray();
		void GetGraphicsResetStatus(GraphicsResetStatus* returnVal = 0);

	public:
		void ProcessCommands();

	private:
		ResourceManager& m_ResourceManager;
		raw_rw_buffer m_Buffer;
		bool m_HasSubmittedWork;
	};
}
