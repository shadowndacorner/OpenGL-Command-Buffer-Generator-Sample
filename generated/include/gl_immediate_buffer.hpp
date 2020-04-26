#pragma once
#include <glad/glad.h>
#include "gl_resource_manager.hpp"
#include "raw_rw_buffer.hpp"

namespace multigl
{
	class ImmediateCommandBuffer
	{
	public:
		ImmediateCommandBuffer(ResourceManager& manager);
		~ImmediateCommandBuffer();

	public:
		void GetError(GLenum* returnVal = 0);
		void GetString(GLenum name, const GLubyte ** returnVal = 0);
		void IsEnabled(GLenum cap, GLboolean* returnVal = 0);
		TextureHandle GenTexture();
		void IsTexture(TextureHandle texture, GLboolean* returnVal = 0);
		void IsQuery(GLuint id, GLboolean* returnVal = 0);
		BufferHandle GenBuffer();
		void IsBuffer(BufferHandle buffer, GLboolean* returnVal = 0);
		void MapBuffer(GLenum target, GLenum access, void ** returnVal = 0);
		void UnmapBuffer(GLenum target, GLboolean* returnVal = 0);
		ShaderProgramHandle CreateProgram();
		ShaderHandle CreateShader(GLenum type);
		void GetAttribLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void GetUniformLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void IsProgram(ShaderProgramHandle program, GLboolean* returnVal = 0);
		void IsShader(ShaderHandle shader, GLboolean* returnVal = 0);
		void IsEnabledi(GLenum target, GLuint index, GLboolean* returnVal = 0);
		void GetFragDataLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void GetStringi(GLenum name, GLuint index, const GLubyte ** returnVal = 0);
		void IsRenderbuffer(RenderbufferHandle renderbuffer, GLboolean* returnVal = 0);
		RenderbufferHandle GenRenderbuffer();
		void IsFramebuffer(FramebufferHandle framebuffer, GLboolean* returnVal = 0);
		FramebufferHandle GenFramebuffer();
		void CheckFramebufferStatus(GLenum target, GLenum* returnVal = 0);
		void MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal = 0);
		VertexArrayHandle GenVertexArray();
		void IsVertexArray(GLuint array, GLboolean* returnVal = 0);
		void GetUniformBlockIndex(ShaderProgramHandle program, const GLchar * uniformBlockName, GLuint* returnVal = 0);
		void FenceSync(GLenum condition, GLbitfield flags, GLsync* returnVal = 0);
		void IsSync(GLsync sync, GLboolean* returnVal = 0);
		void ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, GLenum* returnVal = 0);
		void GetFragDataIndex(ShaderProgramHandle program, const GLchar * name, GLint* returnVal = 0);
		void IsSampler(GLuint sampler, GLboolean* returnVal = 0);
		void GetSubroutineUniformLocation(ShaderProgramHandle program, GLenum shadertype, const GLchar * name, GLint* returnVal = 0);
		void GetSubroutineIndex(ShaderProgramHandle program, GLenum shadertype, const GLchar * name, GLuint* returnVal = 0);
		void IsTransformFeedback(GLuint id, GLboolean* returnVal = 0);
		void CreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings, GLuint* returnVal = 0);
		void IsProgramPipeline(GLuint pipeline, GLboolean* returnVal = 0);
		void GetProgramResourceIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name, GLuint* returnVal = 0);
		void GetProgramResourceLocation(ShaderProgramHandle program, GLenum programInterface, const GLchar * name, GLint* returnVal = 0);
		void GetProgramResourceLocationIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name, GLint* returnVal = 0);
		void GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* returnVal = 0);
		BufferHandle CreateBuffer();
		void MapNamedBuffer(BufferHandle buffer, GLenum access, void ** returnVal = 0);
		void MapNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal = 0);
		void UnmapNamedBuffer(BufferHandle buffer, GLboolean* returnVal = 0);
		FramebufferHandle CreateFramebuffer();
		void CheckNamedFramebufferStatus(FramebufferHandle framebuffer, GLenum target, GLenum* returnVal = 0);
		RenderbufferHandle CreateRenderbuffer();
		TextureHandle CreateTexture(GLenum target);
		VertexArrayHandle CreateVertexArray();
		void GetGraphicsResetStatus(GLenum* returnVal = 0);

	public:
		void ProcessCommands();

	private:
		ResourceManager& m_ResourceManager;
		raw_rw_buffer m_Buffer;
		bool m_HasSubmittedWork;
	};
}
