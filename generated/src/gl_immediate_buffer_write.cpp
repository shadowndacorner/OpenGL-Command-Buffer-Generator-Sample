#include <gl_immediate_buffer.hpp>

using namespace multigl;
ImmediateCommandBuffer::ImmediateCommandBuffer(ResourceManager& mgr) : m_ResourceManager(mgr) {}
ImmediateCommandBuffer::~ImmediateCommandBuffer(){}

GLenum ImmediateCommandBuffer::GetError()
{
	m_Buffer.write_command(CommandId::GetError);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

const GLubyte * ImmediateCommandBuffer::GetString(GLenum name)
{
	m_Buffer.write_command(CommandId::GetString);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsEnabled(GLenum cap)
{
	m_Buffer.write_command(CommandId::IsEnabled);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

TextureHandle ImmediateCommandBuffer::GenTexture()
{
	m_Buffer.write_command(CommandId::GenTexture);

	auto handle = m_ResourceManager.Textures.create(0);
	m_Buffer.write(handle);
	return handle;
}

GLboolean ImmediateCommandBuffer::IsTexture(TextureHandle texture)
{
	m_Buffer.write_command(CommandId::IsTexture);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsQuery(GLuint id)
{
	m_Buffer.write_command(CommandId::IsQuery);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

BufferHandle ImmediateCommandBuffer::GenBuffer()
{
	m_Buffer.write_command(CommandId::GenBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

GLboolean ImmediateCommandBuffer::IsBuffer(BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::IsBuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

void * ImmediateCommandBuffer::MapBuffer(GLenum target, GLenum access)
{
	m_Buffer.write_command(CommandId::MapBuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::UnmapBuffer(GLenum target)
{
	m_Buffer.write_command(CommandId::UnmapBuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

ShaderProgramHandle ImmediateCommandBuffer::CreateProgram()
{
	m_Buffer.write_command(CommandId::CreateProgram);

	auto handle = m_ResourceManager.ShaderPrograms.create(0);
	m_Buffer.write(handle);
	return handle;
}

ShaderHandle ImmediateCommandBuffer::CreateShader(GLenum type)
{
	m_Buffer.write_command(CommandId::CreateShader);

	auto handle = m_ResourceManager.Shaders.create(0);
	m_Buffer.write(handle);
	m_Buffer.write<GLenum>(type);
	return handle;
}

GLint ImmediateCommandBuffer::GetAttribLocation(ShaderProgramHandle program, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetAttribLocation);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetUniformLocation(ShaderProgramHandle program, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetUniformLocation);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsProgram(ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::IsProgram);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsShader(ShaderHandle shader)
{
	m_Buffer.write_command(CommandId::IsShader);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsEnabledi(GLenum target, GLuint index)
{
	m_Buffer.write_command(CommandId::IsEnabledi);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetFragDataLocation(ShaderProgramHandle program, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetFragDataLocation);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

const GLubyte * ImmediateCommandBuffer::GetStringi(GLenum name, GLuint index)
{
	m_Buffer.write_command(CommandId::GetStringi);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsRenderbuffer(RenderbufferHandle renderbuffer)
{
	m_Buffer.write_command(CommandId::IsRenderbuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

RenderbufferHandle ImmediateCommandBuffer::GenRenderbuffer()
{
	m_Buffer.write_command(CommandId::GenRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

GLboolean ImmediateCommandBuffer::IsFramebuffer(FramebufferHandle framebuffer)
{
	m_Buffer.write_command(CommandId::IsFramebuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

FramebufferHandle ImmediateCommandBuffer::GenFramebuffer()
{
	m_Buffer.write_command(CommandId::GenFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

GLenum ImmediateCommandBuffer::CheckFramebufferStatus(GLenum target)
{
	m_Buffer.write_command(CommandId::CheckFramebufferStatus);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

void * ImmediateCommandBuffer::MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	m_Buffer.write_command(CommandId::MapBufferRange);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

VertexArrayHandle ImmediateCommandBuffer::GenVertexArray()
{
	m_Buffer.write_command(CommandId::GenVertexArray);

	auto handle = m_ResourceManager.VertexArrays.create(0);
	m_Buffer.write<VertexArrayHandle>(handle);
	return handle;
}

GLboolean ImmediateCommandBuffer::IsVertexArray(GLuint array)
{
	m_Buffer.write_command(CommandId::IsVertexArray);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLuint ImmediateCommandBuffer::GetUniformBlockIndex(ShaderProgramHandle program, const GLchar * uniformBlockName)
{
	m_Buffer.write_command(CommandId::GetUniformBlockIndex);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLsync ImmediateCommandBuffer::FenceSync(GLenum condition, GLbitfield flags)
{
	m_Buffer.write_command(CommandId::FenceSync);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsSync(GLsync sync)
{
	m_Buffer.write_command(CommandId::IsSync);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLenum ImmediateCommandBuffer::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	m_Buffer.write_command(CommandId::ClientWaitSync);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetFragDataIndex(ShaderProgramHandle program, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetFragDataIndex);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsSampler(GLuint sampler)
{
	m_Buffer.write_command(CommandId::IsSampler);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetSubroutineUniformLocation(ShaderProgramHandle program, GLenum shadertype, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetSubroutineUniformLocation);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLuint ImmediateCommandBuffer::GetSubroutineIndex(ShaderProgramHandle program, GLenum shadertype, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetSubroutineIndex);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsTransformFeedback(GLuint id)
{
	m_Buffer.write_command(CommandId::IsTransformFeedback);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLuint ImmediateCommandBuffer::CreateShaderProgramv(GLenum type, GLsizei count, const GLchar *const* strings)
{
	m_Buffer.write_command(CommandId::CreateShaderProgramv);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::IsProgramPipeline(GLuint pipeline)
{
	m_Buffer.write_command(CommandId::IsProgramPipeline);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLuint ImmediateCommandBuffer::GetProgramResourceIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetProgramResourceIndex);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetProgramResourceLocation(ShaderProgramHandle program, GLenum programInterface, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetProgramResourceLocation);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLint ImmediateCommandBuffer::GetProgramResourceLocationIndex(ShaderProgramHandle program, GLenum programInterface, const GLchar * name)
{
	m_Buffer.write_command(CommandId::GetProgramResourceLocationIndex);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLuint ImmediateCommandBuffer::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog)
{
	m_Buffer.write_command(CommandId::GetDebugMessageLog);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

BufferHandle ImmediateCommandBuffer::CreateBuffer()
{
	m_Buffer.write_command(CommandId::CreateBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

void * ImmediateCommandBuffer::MapNamedBuffer(BufferHandle buffer, GLenum access)
{
	m_Buffer.write_command(CommandId::MapNamedBuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

void * ImmediateCommandBuffer::MapNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	m_Buffer.write_command(CommandId::MapNamedBufferRange);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

GLboolean ImmediateCommandBuffer::UnmapNamedBuffer(BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::UnmapNamedBuffer);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

FramebufferHandle ImmediateCommandBuffer::CreateFramebuffer()
{
	m_Buffer.write_command(CommandId::CreateFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

GLenum ImmediateCommandBuffer::CheckNamedFramebufferStatus(FramebufferHandle framebuffer, GLenum target)
{
	m_Buffer.write_command(CommandId::CheckNamedFramebufferStatus);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

RenderbufferHandle ImmediateCommandBuffer::CreateRenderbuffer()
{
	m_Buffer.write_command(CommandId::CreateRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

TextureHandle ImmediateCommandBuffer::CreateTexture(GLenum target)
{
	m_Buffer.write_command(CommandId::CreateTexture);

	m_Buffer.write(target);
	auto handle = m_ResourceManager.Textures.create(0);
	m_Buffer.write(handle);
	return handle;
}

VertexArrayHandle ImmediateCommandBuffer::CreateVertexArray()
{
	m_Buffer.write_command(CommandId::CreateVertexArray);

	auto handle = m_ResourceManager.VertexArrays.create(0);
	m_Buffer.write<VertexArrayHandle>(handle);
	return handle;
}

GLenum ImmediateCommandBuffer::GetGraphicsResetStatus()
{
	m_Buffer.write_command(CommandId::GetGraphicsResetStatus);
	#if defined(MGL_STRICT_COMPILATION)
	#error Unimplemented function with return value
	#endif
	return 0;
}

