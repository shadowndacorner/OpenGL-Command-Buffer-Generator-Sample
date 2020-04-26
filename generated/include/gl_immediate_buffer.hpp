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
		GLenum GetError();
		const GLubyte * GetString(GLenum name);
		GLboolean IsEnabled(GLenum cap);
		TextureHandle GenTexture();
		GLboolean IsTexture(TextureHandle texture);
		GLboolean IsQuery(GLuint id);
		BufferHandle GenBuffer();
		GLboolean IsBuffer(BufferHandle buffer);
		void * MapBuffer(GLenum target, GLenum access);
		GLboolean UnmapBuffer(GLenum target);
		ShaderProgramHandle CreateProgram();
		ShaderHandle CreateShader(GLenum type);
		GLint GetAttribLocation(ShaderProgramHandle program, const GLchar * name);
		GLint GetUniformLocation(ShaderProgramHandle program, const GLchar * name);
		GLboolean IsProgram(ShaderProgramHandle program);
		GLboolean IsShader(ShaderHandle shader);
		GLboolean IsEnabledi(GLenum target, GLuint index);
		GLint GetFragDataLocation(ShaderProgramHandle program, const GLchar * name);
		const GLubyte * GetStringi(GLenum name, GLuint index);
		GLboolean IsRenderbuffer(RenderbufferHandle renderbuffer);
		RenderbufferHandle GenRenderbuffer();
		GLboolean IsFramebuffer(FramebufferHandle framebuffer);
		FramebufferHandle GenFramebuffer();
		GLenum CheckFramebufferStatus(GLenum target);
		void * MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
		VertexArrayHandle GenVertexArray();
		GLboolean IsVertexArray(GLuint array);
		GLuint GetUniformBlockIndex(ShaderProgramHandle program, const GLchar * uniformBlockName);
		GLsync FenceSync(GLenum condition, GLbitfield flags);
		GLboolean IsSync(GLsync sync);
		GLenum ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
		GLint GetFragDataIndex(ShaderProgramHandle program, const GLchar * name);
		GLboolean IsSampler(GLuint sampler);
		GLint GetSubroutineUniformLocation(ShaderProgramHandle program, GLenum shadertype, const GLchar * name);
		GLuint GetSubroutineIndex(ShaderProgramHandle program, GLenum shadertype, const GLchar * name);
		GLboolean IsTransformFeedback(GLuint id);
		GLuint CreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings);
		GLboolean IsProgramPipeline(GLuint pipeline);
		GLuint GetProgramResourceIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name);
		GLint GetProgramResourceLocation(ShaderProgramHandle program, GLenum programInterface, const GLchar * name);
		GLint GetProgramResourceLocationIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name);
		GLuint GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog);
		BufferHandle CreateBuffer();
		void * MapNamedBuffer(BufferHandle buffer, GLenum access);
		void * MapNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
		GLboolean UnmapNamedBuffer(BufferHandle buffer);
		FramebufferHandle CreateFramebuffer();
		GLenum CheckNamedFramebufferStatus(FramebufferHandle framebuffer, GLenum target);
		RenderbufferHandle CreateRenderbuffer();
		TextureHandle CreateTexture(GLenum target);
		VertexArrayHandle CreateVertexArray();
		GLenum GetGraphicsResetStatus();

	public:
		void ProcessCommands();

	private:
		ResourceManager& m_ResourceManager;
		raw_rw_buffer m_Buffer;
	};
}
