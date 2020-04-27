#include <gl_immediate_buffer.hpp>

using namespace multigl;
ImmediateCommandBuffer::ImmediateCommandBuffer(ResourceManager& mgr) : m_ResourceManager(mgr)
	, m_HasSubmittedWork(false)
{
}

ImmediateCommandBuffer::~ImmediateCommandBuffer()
{
	if (!m_HasSubmittedWork)
	{
		// TODO: Submit queue to main thread
	}
	// TODO: Wait on job system task here
}

void ImmediateCommandBuffer::GetError(ErrorCode* returnVal)
{
	m_Buffer.write_command(CommandId::GetError);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetString(StringName name, const GLubyte ** returnVal)
{
	m_Buffer.write_command(CommandId::GetString);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsEnabled(EnableCap cap, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsEnabled);
	m_Buffer.write(cap);
	m_Buffer.write(returnVal);
}

TextureHandle ImmediateCommandBuffer::GenTexture()
{
	m_Buffer.write_command(CommandId::GenTexture);

	auto handle = m_ResourceManager.Textures.create(0);
	m_Buffer.write(handle);
	return handle;
}

void ImmediateCommandBuffer::IsTexture(TextureHandle texture, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsTexture);
	m_Buffer.write(texture);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsQuery(GLuint id, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsQuery);
	m_Buffer.write(id);
	m_Buffer.write(returnVal);
}

BufferHandle ImmediateCommandBuffer::GenBuffer()
{
	m_Buffer.write_command(CommandId::GenBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::IsBuffer(BufferHandle buffer, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsBuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::MapBuffer(BufferTarget target, BufferAccessARB access, void ** returnVal)
{
	m_Buffer.write_command(CommandId::MapBuffer);
	m_Buffer.write(target);
	m_Buffer.write(access);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::UnmapBuffer(BufferTarget target, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::UnmapBuffer);
	m_Buffer.write(target);
	m_Buffer.write(returnVal);
}

ShaderProgramHandle ImmediateCommandBuffer::CreateProgram()
{
	m_Buffer.write_command(CommandId::CreateProgram);

	auto handle = m_ResourceManager.ShaderPrograms.create(0);
	m_Buffer.write(handle);
	return handle;
}

ShaderHandle ImmediateCommandBuffer::CreateShader(multigl::ShaderType type)
{
	m_Buffer.write_command(CommandId::CreateShader);

	auto handle = m_ResourceManager.Shaders.create(0);
	m_Buffer.write(handle);
	m_Buffer.write<ShaderType>(type);
	return handle;
}

void ImmediateCommandBuffer::GetAttribLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetAttribLocation);
	m_Buffer.write(program);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetUniformLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetUniformLocation);
	m_Buffer.write(program);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsProgram(ShaderProgramHandle program, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsProgram);
	m_Buffer.write(program);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsShader(ShaderHandle shader, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsShader);
	m_Buffer.write(shader);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsEnabledi(EnableCap target, GLuint index, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsEnabledi);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetFragDataLocation(ShaderProgramHandle program, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetFragDataLocation);
	m_Buffer.write(program);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetStringi(StringName name, GLuint index, const GLubyte ** returnVal)
{
	m_Buffer.write_command(CommandId::GetStringi);
	m_Buffer.write(name);
	m_Buffer.write(index);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsRenderbuffer(RenderbufferHandle renderbuffer, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsRenderbuffer);
	m_Buffer.write(renderbuffer);
	m_Buffer.write(returnVal);
}

RenderbufferHandle ImmediateCommandBuffer::GenRenderbuffer()
{
	m_Buffer.write_command(CommandId::GenRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::IsFramebuffer(FramebufferHandle framebuffer, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsFramebuffer);
	m_Buffer.write(framebuffer);
	m_Buffer.write(returnVal);
}

FramebufferHandle ImmediateCommandBuffer::GenFramebuffer()
{
	m_Buffer.write_command(CommandId::GenFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::CheckFramebufferStatus(FramebufferTarget target, FramebufferStatus* returnVal)
{
	m_Buffer.write_command(CommandId::CheckFramebufferStatus);
	m_Buffer.write(target);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::MapBufferRange(BufferTarget target, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal)
{
	m_Buffer.write_command(CommandId::MapBufferRange);
	m_Buffer.write(target);
	m_Buffer.write(offset);
	m_Buffer.write(length);
	m_Buffer.write(access);
	m_Buffer.write(returnVal);
}

VertexArrayHandle ImmediateCommandBuffer::GenVertexArray()
{
	m_Buffer.write_command(CommandId::GenVertexArray);

	auto handle = m_ResourceManager.VertexArrays.create(0);
	m_Buffer.write<VertexArrayHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::IsVertexArray(GLuint array, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsVertexArray);
	m_Buffer.write(array);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetUniformBlockIndex(ShaderProgramHandle program, const GLchar * uniformBlockName, GLuint* returnVal)
{
	m_Buffer.write_command(CommandId::GetUniformBlockIndex);
	m_Buffer.write(program);
	m_Buffer.write(uniformBlockName);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::FenceSync(SyncCondition condition, GLbitfield flags, GLsync* returnVal)
{
	m_Buffer.write_command(CommandId::FenceSync);
	m_Buffer.write(condition);
	m_Buffer.write(flags);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsSync(GLsync sync, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsSync);
	m_Buffer.write(sync);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout, SyncStatus* returnVal)
{
	m_Buffer.write_command(CommandId::ClientWaitSync);
	m_Buffer.write(sync);
	m_Buffer.write(flags);
	m_Buffer.write(timeout);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetFragDataIndex(ShaderProgramHandle program, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetFragDataIndex);
	m_Buffer.write(program);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsSampler(GLuint sampler, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsSampler);
	m_Buffer.write(sampler);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetSubroutineUniformLocation(ShaderProgramHandle program, ShaderType shadertype, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetSubroutineUniformLocation);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetSubroutineIndex(ShaderProgramHandle program, ShaderType shadertype, const GLchar * name, GLuint* returnVal)
{
	m_Buffer.write_command(CommandId::GetSubroutineIndex);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsTransformFeedback(GLuint id, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsTransformFeedback);
	m_Buffer.write(id);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::CreateShaderProgramv(ShaderType type, GLsizei count, const GLchar *const* strings, GLuint* returnVal)
{
	m_Buffer.write_command(CommandId::CreateShaderProgramv);
	m_Buffer.write(type);
	m_Buffer.write(count);
	m_Buffer.write(strings);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::IsProgramPipeline(GLuint pipeline, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::IsProgramPipeline);
	m_Buffer.write(pipeline);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetProgramResourceIndex(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLuint* returnVal)
{
	m_Buffer.write_command(CommandId::GetProgramResourceIndex);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetProgramResourceLocation(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetProgramResourceLocation);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetProgramResourceLocationIndex(ShaderProgramHandle program, ProgramInterface programInterface, const GLchar * name, GLint* returnVal)
{
	m_Buffer.write_command(CommandId::GetProgramResourceLocationIndex);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(name);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::GetDebugMessageLog(GLuint count, GLsizei bufSize, GLenum * sources, GLenum * types, GLuint * ids, GLenum * severities, GLsizei * lengths, GLchar * messageLog, GLuint* returnVal)
{
	m_Buffer.write_command(CommandId::GetDebugMessageLog);
	m_Buffer.write(count);
	m_Buffer.write(bufSize);
	m_Buffer.write(sources);
	m_Buffer.write(types);
	m_Buffer.write(ids);
	m_Buffer.write(severities);
	m_Buffer.write(lengths);
	m_Buffer.write(messageLog);
	m_Buffer.write(returnVal);
}

BufferHandle ImmediateCommandBuffer::CreateBuffer()
{
	m_Buffer.write_command(CommandId::CreateBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::MapNamedBuffer(BufferHandle buffer, BufferAccessARB access, void ** returnVal)
{
	m_Buffer.write_command(CommandId::MapNamedBuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(access);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::MapNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length, GLbitfield access, void ** returnVal)
{
	m_Buffer.write_command(CommandId::MapNamedBufferRange);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(length);
	m_Buffer.write(access);
	m_Buffer.write(returnVal);
}

void ImmediateCommandBuffer::UnmapNamedBuffer(BufferHandle buffer, GLboolean* returnVal)
{
	m_Buffer.write_command(CommandId::UnmapNamedBuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(returnVal);
}

FramebufferHandle ImmediateCommandBuffer::CreateFramebuffer()
{
	m_Buffer.write_command(CommandId::CreateFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

void ImmediateCommandBuffer::CheckNamedFramebufferStatus(FramebufferHandle framebuffer, FramebufferTarget target, FramebufferStatus* returnVal)
{
	m_Buffer.write_command(CommandId::CheckNamedFramebufferStatus);
	m_Buffer.write(framebuffer);
	m_Buffer.write(target);
	m_Buffer.write(returnVal);
}

RenderbufferHandle ImmediateCommandBuffer::CreateRenderbuffer()
{
	m_Buffer.write_command(CommandId::CreateRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

TextureHandle ImmediateCommandBuffer::CreateTexture(multigl::TextureTarget target)
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

void ImmediateCommandBuffer::GetGraphicsResetStatus(GraphicsResetStatus* returnVal)
{
	m_Buffer.write_command(CommandId::GetGraphicsResetStatus);
	m_Buffer.write(returnVal);
}

