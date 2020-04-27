#include <gl_command_buffer.hpp>

using namespace multigl;
CommandBuffer::CommandBuffer(ResourceManager& mgr) : m_ResourceManager(mgr)
{
}

CommandBuffer::~CommandBuffer(){}

void CommandBuffer::CullFace(multigl::CullFaceMode mode)
{
	m_Buffer.write_command(CommandId::CullFace);
	m_Buffer.write(mode);
}

void CommandBuffer::FrontFace(multigl::FrontFaceDirection mode)
{
	m_Buffer.write_command(CommandId::FrontFace);
	m_Buffer.write(mode);
}

void CommandBuffer::Hint(multigl::HintTarget target, multigl::HintMode mode)
{
	m_Buffer.write_command(CommandId::Hint);
	m_Buffer.write(target);
	m_Buffer.write(mode);
}

void CommandBuffer::LineWidth(GLfloat width)
{
	m_Buffer.write_command(CommandId::LineWidth);
	m_Buffer.write(width);
}

void CommandBuffer::PointSize(GLfloat size)
{
	m_Buffer.write_command(CommandId::PointSize);
	m_Buffer.write(size);
}

void CommandBuffer::PolygonMode(multigl::MaterialFace face, multigl::PolygonMode mode)
{
	m_Buffer.write_command(CommandId::PolygonMode);
	m_Buffer.write(face);
	m_Buffer.write(mode);
}

void CommandBuffer::Scissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::Scissor);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::TexParameterf(multigl::TextureTarget target, multigl::TextureParameterName pname, GLfloat param)
{
	m_Buffer.write_command(CommandId::TexParameterf);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::TexParameterfv(multigl::TextureTarget target, multigl::TextureParameterName pname, const GLfloat * params)
{
	m_Buffer.write_command(CommandId::TexParameterfv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::TexParameteri(multigl::TextureTarget target, multigl::TextureParameterName pname, GLint param)
{
	m_Buffer.write_command(CommandId::TexParameteri);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::TexParameteriv(multigl::TextureTarget target, multigl::TextureParameterName pname, const GLint * params)
{
	m_Buffer.write_command(CommandId::TexParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::TexImage1D(multigl::TextureTarget target, GLint level, GLint internalformat, GLsizei width, GLint border, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(border);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::TexImage2D(multigl::TextureTarget target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(border);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::DrawBuffer(multigl::DrawBufferMode buf)
{
	m_Buffer.write_command(CommandId::DrawBuffer);
	m_Buffer.write(buf);
}

void CommandBuffer::Clear(GLbitfield mask)
{
	m_Buffer.write_command(CommandId::Clear);
	m_Buffer.write(mask);
}

void CommandBuffer::ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	m_Buffer.write_command(CommandId::ClearColor);
	m_Buffer.write(red);
	m_Buffer.write(green);
	m_Buffer.write(blue);
	m_Buffer.write(alpha);
}

void CommandBuffer::ClearStencil(GLint s)
{
	m_Buffer.write_command(CommandId::ClearStencil);
	m_Buffer.write(s);
}

void CommandBuffer::ClearDepth(GLdouble depth)
{
	m_Buffer.write_command(CommandId::ClearDepth);
	m_Buffer.write(depth);
}

void CommandBuffer::StencilMask(GLuint mask)
{
	m_Buffer.write_command(CommandId::StencilMask);
	m_Buffer.write(mask);
}

void CommandBuffer::ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
	m_Buffer.write_command(CommandId::ColorMask);
	m_Buffer.write(red);
	m_Buffer.write(green);
	m_Buffer.write(blue);
	m_Buffer.write(alpha);
}

void CommandBuffer::DepthMask(GLboolean flag)
{
	m_Buffer.write_command(CommandId::DepthMask);
	m_Buffer.write(flag);
}

void CommandBuffer::Disable(multigl::EnableCap cap)
{
	m_Buffer.write_command(CommandId::Disable);
	m_Buffer.write(cap);
}

void CommandBuffer::Enable(multigl::EnableCap cap)
{
	m_Buffer.write_command(CommandId::Enable);
	m_Buffer.write(cap);
}

void CommandBuffer::Finish()
{
	m_Buffer.write_command(CommandId::Finish);
}

void CommandBuffer::Flush()
{
	m_Buffer.write_command(CommandId::Flush);
}

void CommandBuffer::BlendFunc(multigl::BlendingFactor sfactor, multigl::BlendingFactor dfactor)
{
	m_Buffer.write_command(CommandId::BlendFunc);
	m_Buffer.write(sfactor);
	m_Buffer.write(dfactor);
}

void CommandBuffer::LogicOp(multigl::LogicOp opcode)
{
	m_Buffer.write_command(CommandId::LogicOp);
	m_Buffer.write(opcode);
}

void CommandBuffer::StencilFunc(multigl::StencilFunction func, GLint ref, GLuint mask)
{
	m_Buffer.write_command(CommandId::StencilFunc);
	m_Buffer.write(func);
	m_Buffer.write(ref);
	m_Buffer.write(mask);
}

void CommandBuffer::StencilOp(multigl::StencilOp fail, multigl::StencilOp zfail, multigl::StencilOp zpass)
{
	m_Buffer.write_command(CommandId::StencilOp);
	m_Buffer.write(fail);
	m_Buffer.write(zfail);
	m_Buffer.write(zpass);
}

void CommandBuffer::DepthFunc(multigl::DepthFunction func)
{
	m_Buffer.write_command(CommandId::DepthFunc);
	m_Buffer.write(func);
}

void CommandBuffer::PixelStoref(multigl::PixelStoreParameter pname, GLfloat param)
{
	m_Buffer.write_command(CommandId::PixelStoref);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::PixelStorei(multigl::PixelStoreParameter pname, GLint param)
{
	m_Buffer.write_command(CommandId::PixelStorei);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::ReadBuffer(multigl::ReadBufferMode src)
{
	m_Buffer.write_command(CommandId::ReadBuffer);
	m_Buffer.write(src);
}

void CommandBuffer::ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, multigl::PixelFormat format, multigl::PixelType type, void * pixels)
{
	m_Buffer.write_command(CommandId::ReadPixels);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetBooleanv(multigl::GetPName pname, GLboolean * data)
{
	m_Buffer.write_command(CommandId::GetBooleanv);
	m_Buffer.write(pname);
	m_Buffer.write(data);
}

void CommandBuffer::GetDoublev(multigl::GetPName pname, GLdouble * data)
{
	m_Buffer.write_command(CommandId::GetDoublev);
	m_Buffer.write(pname);
	m_Buffer.write(data);
}

void CommandBuffer::GetFloatv(multigl::GetPName pname, GLfloat * data)
{
	m_Buffer.write_command(CommandId::GetFloatv);
	m_Buffer.write(pname);
	m_Buffer.write(data);
}

void CommandBuffer::GetIntegerv(multigl::GetPName pname, GLint * data)
{
	m_Buffer.write_command(CommandId::GetIntegerv);
	m_Buffer.write(pname);
	m_Buffer.write(data);
}

void CommandBuffer::GetTexImage(multigl::TextureTarget target, GLint level, multigl::PixelFormat format, multigl::PixelType type, void * pixels)
{
	m_Buffer.write_command(CommandId::GetTexImage);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetTexParameterfv(multigl::TextureTarget target, multigl::GetTextureParameter pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetTexParameterfv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTexParameteriv(multigl::TextureTarget target, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTexParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTexLevelParameterfv(multigl::TextureTarget target, GLint level, multigl::GetTextureParameter pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetTexLevelParameterfv);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTexLevelParameteriv(multigl::TextureTarget target, GLint level, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTexLevelParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::DepthRange(GLdouble n, GLdouble f)
{
	m_Buffer.write_command(CommandId::DepthRange);
	m_Buffer.write(n);
	m_Buffer.write(f);
}

void CommandBuffer::Viewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::Viewport);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::DrawArrays(multigl::PrimitiveType mode, GLint first, GLsizei count)
{
	m_Buffer.write_command(CommandId::DrawArrays);
	m_Buffer.write(mode);
	m_Buffer.write(first);
	m_Buffer.write(count);
}

void CommandBuffer::DrawElements(multigl::PrimitiveType mode, GLsizei count, multigl::DrawElementsType type, const void * indices)
{
	m_Buffer.write_command(CommandId::DrawElements);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
}

void CommandBuffer::PolygonOffset(GLfloat factor, GLfloat units)
{
	m_Buffer.write_command(CommandId::PolygonOffset);
	m_Buffer.write(factor);
	m_Buffer.write(units);
}

void CommandBuffer::CopyTexImage1D(multigl::TextureTarget target, GLint level, multigl::InternalFormat internalformat, GLint x, GLint y, GLsizei width, GLint border)
{
	m_Buffer.write_command(CommandId::CopyTexImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(border);
}

void CommandBuffer::CopyTexImage2D(multigl::TextureTarget target, GLint level, multigl::InternalFormat internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
	m_Buffer.write_command(CommandId::CopyTexImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(border);
}

void CommandBuffer::CopyTexSubImage1D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	m_Buffer.write_command(CommandId::CopyTexSubImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
}

void CommandBuffer::CopyTexSubImage2D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::CopyTexSubImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::TexSubImage1D(multigl::TextureTarget target, GLint level, GLint xoffset, GLsizei width, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexSubImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(width);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::TexSubImage2D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexSubImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::BindTexture(multigl::TextureTarget target, TextureHandle texture)
{
	m_Buffer.write_command(CommandId::BindTexture);
	m_Buffer.write(target);
	m_Buffer.write(texture);
}

void CommandBuffer::DeleteTextures(GLsizei n, const GLuint * textures)
{
	m_Buffer.write_command(CommandId::DeleteTextures);
	m_Buffer.write(n);
	m_Buffer.write(textures);
}

TextureHandle CommandBuffer::GenTexture()
{
	m_Buffer.write_command(CommandId::GenTexture);

	auto handle = m_ResourceManager.Textures.create(0);
	m_Buffer.write(handle);
	return handle;
}

void CommandBuffer::DrawRangeElements(multigl::PrimitiveType mode, GLuint start, GLuint end, GLsizei count, multigl::DrawElementsType type, const void * indices)
{
	m_Buffer.write_command(CommandId::DrawRangeElements);
	m_Buffer.write(mode);
	m_Buffer.write(start);
	m_Buffer.write(end);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
}

void CommandBuffer::TexImage3D(multigl::TextureTarget target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexImage3D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(border);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::TexSubImage3D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TexSubImage3D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::CopyTexSubImage3D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::CopyTexSubImage3D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::ActiveTexture(GLuint textureSlot)
{
	m_Buffer.write_command(CommandId::ActiveTexture);
	m_Buffer.write(textureSlot);
}

void CommandBuffer::SampleCoverage(GLfloat value, GLboolean invert)
{
	m_Buffer.write_command(CommandId::SampleCoverage);
	m_Buffer.write(value);
	m_Buffer.write(invert);
}

void CommandBuffer::CompressedTexImage3D(multigl::TextureTarget target, GLint level, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexImage3D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(border);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTexImage2D(multigl::TextureTarget target, GLint level, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(border);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTexImage1D(multigl::TextureTarget target, GLint level, multigl::InternalFormat internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(border);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTexSubImage3D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexSubImage3D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTexSubImage2D(multigl::TextureTarget target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexSubImage2D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTexSubImage1D(multigl::TextureTarget target, GLint level, GLint xoffset, GLsizei width, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTexSubImage1D);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(width);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::GetCompressedTexImage(multigl::TextureTarget target, GLint level, void * img)
{
	m_Buffer.write_command(CommandId::GetCompressedTexImage);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(img);
}

void CommandBuffer::BlendFuncSeparate(multigl::BlendingFactor sfactorRGB, multigl::BlendingFactor dfactorRGB, multigl::BlendingFactor sfactorAlpha, multigl::BlendingFactor dfactorAlpha)
{
	m_Buffer.write_command(CommandId::BlendFuncSeparate);
	m_Buffer.write(sfactorRGB);
	m_Buffer.write(dfactorRGB);
	m_Buffer.write(sfactorAlpha);
	m_Buffer.write(dfactorAlpha);
}

void CommandBuffer::MultiDrawArrays(multigl::PrimitiveType mode, const GLint * first, const GLsizei * count, GLsizei drawcount)
{
	m_Buffer.write_command(CommandId::MultiDrawArrays);
	m_Buffer.write(mode);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(drawcount);
}

void CommandBuffer::MultiDrawElements(multigl::PrimitiveType mode, const GLsizei * count, multigl::DrawElementsType type, const void *const* indices, GLsizei drawcount)
{
	m_Buffer.write_command(CommandId::MultiDrawElements);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(drawcount);
}

void CommandBuffer::PointParameterf(multigl::PointParameterNameARB pname, GLfloat param)
{
	m_Buffer.write_command(CommandId::PointParameterf);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::PointParameterfv(multigl::PointParameterNameARB pname, const GLfloat * params)
{
	m_Buffer.write_command(CommandId::PointParameterfv);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::PointParameteri(multigl::PointParameterNameARB pname, GLint param)
{
	m_Buffer.write_command(CommandId::PointParameteri);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::PointParameteriv(multigl::PointParameterNameARB pname, const GLint * params)
{
	m_Buffer.write_command(CommandId::PointParameteriv);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	m_Buffer.write_command(CommandId::BlendColor);
	m_Buffer.write(red);
	m_Buffer.write(green);
	m_Buffer.write(blue);
	m_Buffer.write(alpha);
}

void CommandBuffer::BlendEquation(multigl::BlendEquationModeEXT mode)
{
	m_Buffer.write_command(CommandId::BlendEquation);
	m_Buffer.write(mode);
}

void CommandBuffer::GenQueries(GLsizei n, GLuint * ids)
{
	m_Buffer.write_command(CommandId::GenQueries);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::DeleteQueries(GLsizei n, const GLuint * ids)
{
	m_Buffer.write_command(CommandId::DeleteQueries);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::BeginQuery(multigl::QueryTarget target, GLuint id)
{
	m_Buffer.write_command(CommandId::BeginQuery);
	m_Buffer.write(target);
	m_Buffer.write(id);
}

void CommandBuffer::EndQuery(multigl::QueryTarget target)
{
	m_Buffer.write_command(CommandId::EndQuery);
	m_Buffer.write(target);
}

void CommandBuffer::GetQueryiv(multigl::QueryTarget target, multigl::QueryParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetQueryiv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetQueryObjectiv(GLuint id, multigl::QueryObjectParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetQueryObjectiv);
	m_Buffer.write(id);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetQueryObjectuiv(GLuint id, multigl::QueryObjectParameterName pname, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetQueryObjectuiv);
	m_Buffer.write(id);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BindBuffer(multigl::BufferTarget target, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::BindBuffer);
	m_Buffer.write(target);
	m_Buffer.write(buffer);
}

void CommandBuffer::DeleteBuffers(GLsizei n, const GLuint * buffers)
{
	m_Buffer.write_command(CommandId::DeleteBuffers);
	m_Buffer.write(n);
	m_Buffer.write(buffers);
}

BufferHandle CommandBuffer::GenBuffer()
{
	m_Buffer.write_command(CommandId::GenBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

void CommandBuffer::BufferData(multigl::BufferTarget target, GLsizeiptr size, const void * data, multigl::BufferUsageARB usage)
{
	m_Buffer.write_command(CommandId::BufferData);
	m_Buffer.write(target);
	m_Buffer.write(size);
	m_Buffer.write(data);
	m_Buffer.write(usage);
}

void CommandBuffer::BufferSubData(multigl::BufferTarget target, GLintptr offset, GLsizeiptr size, const void * data)
{
	m_Buffer.write_command(CommandId::BufferSubData);
	m_Buffer.write(target);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(data);
}

void CommandBuffer::GetBufferSubData(multigl::BufferTarget target, GLintptr offset, GLsizeiptr size, void * data)
{
	m_Buffer.write_command(CommandId::GetBufferSubData);
	m_Buffer.write(target);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(data);
}

void CommandBuffer::GetBufferParameteriv(multigl::BufferTarget target, multigl::BufferPNameARB pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetBufferParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetBufferPointerv(multigl::BufferTarget target, multigl::BufferPointerNameARB pname, void ** params)
{
	m_Buffer.write_command(CommandId::GetBufferPointerv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BlendEquationSeparate(multigl::BlendEquationModeEXT modeRGB, multigl::BlendEquationModeEXT modeAlpha)
{
	m_Buffer.write_command(CommandId::BlendEquationSeparate);
	m_Buffer.write(modeRGB);
	m_Buffer.write(modeAlpha);
}

void CommandBuffer::DrawBuffers(GLsizei n, const GLenum * bufs)
{
	m_Buffer.write_command(CommandId::DrawBuffers);
	m_Buffer.write(n);
	m_Buffer.write(bufs);
}

void CommandBuffer::StencilOpSeparate(multigl::StencilFaceDirection face, multigl::StencilOp sfail, multigl::StencilOp dpfail, multigl::StencilOp dppass)
{
	m_Buffer.write_command(CommandId::StencilOpSeparate);
	m_Buffer.write(face);
	m_Buffer.write(sfail);
	m_Buffer.write(dpfail);
	m_Buffer.write(dppass);
}

void CommandBuffer::StencilFuncSeparate(multigl::StencilFaceDirection face, multigl::StencilFunction func, GLint ref, GLuint mask)
{
	m_Buffer.write_command(CommandId::StencilFuncSeparate);
	m_Buffer.write(face);
	m_Buffer.write(func);
	m_Buffer.write(ref);
	m_Buffer.write(mask);
}

void CommandBuffer::StencilMaskSeparate(multigl::StencilFaceDirection face, GLuint mask)
{
	m_Buffer.write_command(CommandId::StencilMaskSeparate);
	m_Buffer.write(face);
	m_Buffer.write(mask);
}

void CommandBuffer::AttachShader(ShaderProgramHandle program, ShaderHandle shader)
{
	m_Buffer.write_command(CommandId::AttachShader);
	m_Buffer.write(program);
	m_Buffer.write(shader);
}

void CommandBuffer::BindAttribLocation(ShaderProgramHandle program, GLuint index, const GLchar * name)
{
	m_Buffer.write_command(CommandId::BindAttribLocation);
	m_Buffer.write(program);
	m_Buffer.write(index);
	m_Buffer.write(name);
}

void CommandBuffer::CompileShader(ShaderHandle shader)
{
	m_Buffer.write_command(CommandId::CompileShader);
	m_Buffer.write(shader);
}

ShaderProgramHandle CommandBuffer::CreateProgram()
{
	m_Buffer.write_command(CommandId::CreateProgram);

	auto handle = m_ResourceManager.ShaderPrograms.create(0);
	m_Buffer.write(handle);
	return handle;
}

ShaderHandle CommandBuffer::CreateShader(multigl::ShaderType type)
{
	m_Buffer.write_command(CommandId::CreateShader);

	auto handle = m_ResourceManager.Shaders.create(0);
	m_Buffer.write(handle);
	m_Buffer.write<ShaderType>(type);
	return handle;
}

void CommandBuffer::DeleteProgram(ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::DeleteProgram);
	m_Buffer.write(program);
}

void CommandBuffer::DeleteShader(ShaderHandle shader)
{
	m_Buffer.write_command(CommandId::DeleteShader);
	m_Buffer.write(shader);
}

void CommandBuffer::DetachShader(ShaderProgramHandle program, ShaderHandle shader)
{
	m_Buffer.write_command(CommandId::DetachShader);
	m_Buffer.write(program);
	m_Buffer.write(shader);
}

void CommandBuffer::DisableVertexAttribArray(GLuint index)
{
	m_Buffer.write_command(CommandId::DisableVertexAttribArray);
	m_Buffer.write(index);
}

void CommandBuffer::EnableVertexAttribArray(GLuint index)
{
	m_Buffer.write_command(CommandId::EnableVertexAttribArray);
	m_Buffer.write(index);
}

void CommandBuffer::GetActiveAttrib(ShaderProgramHandle program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetActiveAttrib);
	m_Buffer.write(program);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(name);
}

void CommandBuffer::GetActiveUniform(ShaderProgramHandle program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetActiveUniform);
	m_Buffer.write(program);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(name);
}

void CommandBuffer::GetAttachedShaders(ShaderProgramHandle program, GLsizei maxCount, GLsizei * count, GLuint * shaders)
{
	m_Buffer.write_command(CommandId::GetAttachedShaders);
	m_Buffer.write(program);
	m_Buffer.write(maxCount);
	m_Buffer.write(count);
	m_Buffer.write(shaders);
}

void CommandBuffer::GetProgramiv(ShaderProgramHandle program, multigl::ProgramPropertyARB pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetProgramiv);
	m_Buffer.write(program);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetProgramInfoLog(ShaderProgramHandle program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	m_Buffer.write_command(CommandId::GetProgramInfoLog);
	m_Buffer.write(program);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(infoLog);
}

void CommandBuffer::GetShaderiv(ShaderHandle shader, multigl::ShaderParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetShaderiv);
	m_Buffer.write(shader);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetShaderInfoLog(ShaderHandle shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	m_Buffer.write_command(CommandId::GetShaderInfoLog);
	m_Buffer.write(shader);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(infoLog);
}

void CommandBuffer::GetShaderSource(ShaderHandle shader, GLsizei bufSize, GLsizei * length, GLchar * source)
{
	m_Buffer.write_command(CommandId::GetShaderSource);
	m_Buffer.write(shader);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(source);
}

void CommandBuffer::GetUniformfv(ShaderProgramHandle program, GLint location, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetUniformfv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(params);
}

void CommandBuffer::GetUniformiv(ShaderProgramHandle program, GLint location, GLint * params)
{
	m_Buffer.write_command(CommandId::GetUniformiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(params);
}

void CommandBuffer::GetVertexAttribdv(GLuint index, multigl::VertexAttribPropertyARB pname, GLdouble * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribdv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetVertexAttribfv(GLuint index, multigl::VertexAttribPropertyARB pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribfv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetVertexAttribiv(GLuint index, multigl::VertexAttribPropertyARB pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribiv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetVertexAttribPointerv(GLuint index, multigl::VertexAttribPointerPropertyARB pname, void ** pointer)
{
	m_Buffer.write_command(CommandId::GetVertexAttribPointerv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(pointer);
}

void CommandBuffer::LinkProgram(ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::LinkProgram);
	m_Buffer.write(program);
}

void CommandBuffer::ShaderSource(ShaderHandle shader, const GLchar* string, GLint length)
{
	m_Buffer.write_command(CommandId::ShaderSource);
	m_Buffer.write(shader);
	m_Buffer.write(string);
	m_Buffer.write(length);
}

void CommandBuffer::UseProgram(ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::UseProgram);
	m_Buffer.write(program);
}

void CommandBuffer::Uniform1f(GLint location, GLfloat v0)
{
	m_Buffer.write_command(CommandId::Uniform1f);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::Uniform2f(GLint location, GLfloat v0, GLfloat v1)
{
	m_Buffer.write_command(CommandId::Uniform2f);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	m_Buffer.write_command(CommandId::Uniform3f);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	m_Buffer.write_command(CommandId::Uniform4f);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::Uniform1i(GLint location, GLint v0)
{
	m_Buffer.write_command(CommandId::Uniform1i);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::Uniform2i(GLint location, GLint v0, GLint v1)
{
	m_Buffer.write_command(CommandId::Uniform2i);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::Uniform3i(GLint location, GLint v0, GLint v1, GLint v2)
{
	m_Buffer.write_command(CommandId::Uniform3i);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	m_Buffer.write_command(CommandId::Uniform4i);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::Uniform1fv(GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::Uniform1fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform2fv(GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::Uniform2fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform3fv(GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::Uniform3fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform4fv(GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::Uniform4fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform1iv(GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::Uniform1iv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform2iv(GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::Uniform2iv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform3iv(GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::Uniform3iv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform4iv(GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::Uniform4iv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ValidateProgram(ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::ValidateProgram);
	m_Buffer.write(program);
}

void CommandBuffer::VertexAttrib1d(GLuint index, GLdouble x)
{
	m_Buffer.write_command(CommandId::VertexAttrib1d);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttrib1dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib1dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib1f(GLuint index, GLfloat x)
{
	m_Buffer.write_command(CommandId::VertexAttrib1f);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttrib1fv(GLuint index, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib1fv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib1s(GLuint index, GLshort x)
{
	m_Buffer.write_command(CommandId::VertexAttrib1s);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttrib1sv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib1sv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib2d(GLuint index, GLdouble x, GLdouble y)
{
	m_Buffer.write_command(CommandId::VertexAttrib2d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttrib2dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib2dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
{
	m_Buffer.write_command(CommandId::VertexAttrib2f);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttrib2fv(GLuint index, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib2fv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib2s(GLuint index, GLshort x, GLshort y)
{
	m_Buffer.write_command(CommandId::VertexAttrib2s);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttrib2sv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib2sv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	m_Buffer.write_command(CommandId::VertexAttrib3d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttrib3dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib3dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
	m_Buffer.write_command(CommandId::VertexAttrib3f);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttrib3fv(GLuint index, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib3fv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z)
{
	m_Buffer.write_command(CommandId::VertexAttrib3s);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttrib3sv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib3sv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Nbv(GLuint index, const GLbyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nbv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Niv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Niv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Nsv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nsv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nub);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttrib4Nubv(GLuint index, const GLubyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nubv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Nuiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nuiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4Nusv(GLuint index, const GLushort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4Nusv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4bv(GLuint index, const GLbyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4bv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	m_Buffer.write_command(CommandId::VertexAttrib4d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttrib4dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	m_Buffer.write_command(CommandId::VertexAttrib4f);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttrib4fv(GLuint index, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4fv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4iv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4iv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w)
{
	m_Buffer.write_command(CommandId::VertexAttrib4s);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttrib4sv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4sv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4ubv(GLuint index, const GLubyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4ubv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4uiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4uiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttrib4usv(GLuint index, const GLushort * v)
{
	m_Buffer.write_command(CommandId::VertexAttrib4usv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribPointer(GLuint index, GLint size, multigl::VertexAttribPointerType type, GLboolean normalized, GLsizei stride, const void * pointer)
{
	m_Buffer.write_command(CommandId::VertexAttribPointer);
	m_Buffer.write(index);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(stride);
	m_Buffer.write(pointer);
}

void CommandBuffer::UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2x3fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3x2fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2x4fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4x2fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3x4fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4x3fv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
{
	m_Buffer.write_command(CommandId::ColorMaski);
	m_Buffer.write(index);
	m_Buffer.write(r);
	m_Buffer.write(g);
	m_Buffer.write(b);
	m_Buffer.write(a);
}

void CommandBuffer::GetBooleani_v(multigl::BufferTarget target, GLuint index, GLboolean * data)
{
	m_Buffer.write_command(CommandId::GetBooleani_v);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(data);
}

void CommandBuffer::GetIntegeri_v(GLenum target, GLuint index, GLint * data)
{
	m_Buffer.write_command(CommandId::GetIntegeri_v);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(data);
}

void CommandBuffer::Enablei(multigl::EnableCap target, GLuint index)
{
	m_Buffer.write_command(CommandId::Enablei);
	m_Buffer.write(target);
	m_Buffer.write(index);
}

void CommandBuffer::Disablei(multigl::EnableCap target, GLuint index)
{
	m_Buffer.write_command(CommandId::Disablei);
	m_Buffer.write(target);
	m_Buffer.write(index);
}

void CommandBuffer::BeginTransformFeedback(multigl::PrimitiveType primitiveMode)
{
	m_Buffer.write_command(CommandId::BeginTransformFeedback);
	m_Buffer.write(primitiveMode);
}

void CommandBuffer::EndTransformFeedback()
{
	m_Buffer.write_command(CommandId::EndTransformFeedback);
}

void CommandBuffer::BindBufferRange(multigl::BufferTarget target, GLuint index, BufferHandle buffer, GLintptr offset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::BindBufferRange);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
}

void CommandBuffer::BindBufferBase(multigl::BufferTarget target, GLuint index, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::BindBufferBase);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(buffer);
}

void CommandBuffer::TransformFeedbackVaryings(ShaderProgramHandle program, GLsizei count, const GLchar *const* varyings, multigl::TransformFeedbackBufferMode bufferMode)
{
	m_Buffer.write_command(CommandId::TransformFeedbackVaryings);
	m_Buffer.write(program);
	m_Buffer.write(count);
	m_Buffer.write(varyings);
	m_Buffer.write(bufferMode);
}

void CommandBuffer::GetTransformFeedbackVarying(ShaderProgramHandle program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetTransformFeedbackVarying);
	m_Buffer.write(program);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(name);
}

void CommandBuffer::ClampColor(multigl::ClampColorTargetARB target, multigl::ClampColorModeARB clamp)
{
	m_Buffer.write_command(CommandId::ClampColor);
	m_Buffer.write(target);
	m_Buffer.write(clamp);
}

void CommandBuffer::BeginConditionalRender(GLuint id, multigl::ConditionalRenderMode mode)
{
	m_Buffer.write_command(CommandId::BeginConditionalRender);
	m_Buffer.write(id);
	m_Buffer.write(mode);
}

void CommandBuffer::EndConditionalRender()
{
	m_Buffer.write_command(CommandId::EndConditionalRender);
}

void CommandBuffer::VertexAttribIPointer(GLuint index, GLint size, multigl::VertexAttribPointerType type, GLsizei stride, const void * pointer)
{
	m_Buffer.write_command(CommandId::VertexAttribIPointer);
	m_Buffer.write(index);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(stride);
	m_Buffer.write(pointer);
}

void CommandBuffer::GetVertexAttribIiv(GLuint index, multigl::VertexAttribEnum pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribIiv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetVertexAttribIuiv(GLuint index, multigl::VertexAttribEnum pname, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribIuiv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::VertexAttribI1i(GLuint index, GLint x)
{
	m_Buffer.write_command(CommandId::VertexAttribI1i);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttribI2i(GLuint index, GLint x, GLint y)
{
	m_Buffer.write_command(CommandId::VertexAttribI2i);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z)
{
	m_Buffer.write_command(CommandId::VertexAttribI3i);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
{
	m_Buffer.write_command(CommandId::VertexAttribI4i);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttribI1ui(GLuint index, GLuint x)
{
	m_Buffer.write_command(CommandId::VertexAttribI1ui);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttribI2ui(GLuint index, GLuint x, GLuint y)
{
	m_Buffer.write_command(CommandId::VertexAttribI2ui);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z)
{
	m_Buffer.write_command(CommandId::VertexAttribI3ui);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
{
	m_Buffer.write_command(CommandId::VertexAttribI4ui);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttribI1iv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI1iv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI2iv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI2iv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI3iv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI3iv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4iv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4iv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI1uiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI1uiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI2uiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI2uiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI3uiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI3uiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4uiv(GLuint index, const GLuint * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4uiv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4bv(GLuint index, const GLbyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4bv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4sv(GLuint index, const GLshort * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4sv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4ubv(GLuint index, const GLubyte * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4ubv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribI4usv(GLuint index, const GLushort * v)
{
	m_Buffer.write_command(CommandId::VertexAttribI4usv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::GetUniformuiv(ShaderProgramHandle program, GLint location, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetUniformuiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(params);
}

void CommandBuffer::BindFragDataLocation(ShaderProgramHandle program, GLuint color, const GLchar * name)
{
	m_Buffer.write_command(CommandId::BindFragDataLocation);
	m_Buffer.write(program);
	m_Buffer.write(color);
	m_Buffer.write(name);
}

void CommandBuffer::Uniform1ui(GLint location, GLuint v0)
{
	m_Buffer.write_command(CommandId::Uniform1ui);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::Uniform2ui(GLint location, GLuint v0, GLuint v1)
{
	m_Buffer.write_command(CommandId::Uniform2ui);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	m_Buffer.write_command(CommandId::Uniform3ui);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	m_Buffer.write_command(CommandId::Uniform4ui);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::Uniform1uiv(GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::Uniform1uiv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform2uiv(GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::Uniform2uiv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform3uiv(GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::Uniform3uiv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform4uiv(GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::Uniform4uiv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::TexParameterIiv(multigl::TextureTarget target, multigl::TextureParameterName pname, const GLint * params)
{
	m_Buffer.write_command(CommandId::TexParameterIiv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::TexParameterIuiv(multigl::TextureTarget target, multigl::TextureParameterName pname, const GLuint * params)
{
	m_Buffer.write_command(CommandId::TexParameterIuiv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTexParameterIiv(multigl::TextureTarget target, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTexParameterIiv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTexParameterIuiv(multigl::TextureTarget target, multigl::GetTextureParameter pname, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetTexParameterIuiv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::ClearBufferiv(multigl::BufferHandle buffer, GLint drawbuffer, const GLint * value)
{
	m_Buffer.write_command(CommandId::ClearBufferiv);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearBufferuiv(multigl::BufferHandle buffer, GLint drawbuffer, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ClearBufferuiv);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearBufferfv(multigl::BufferHandle buffer, GLint drawbuffer, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ClearBufferfv);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearBufferfi(multigl::BufferHandle buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	m_Buffer.write_command(CommandId::ClearBufferfi);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(depth);
	m_Buffer.write(stencil);
}

void CommandBuffer::BindRenderbuffer(multigl::RenderbufferTarget target, RenderbufferHandle renderbuffer)
{
	m_Buffer.write_command(CommandId::BindRenderbuffer);
	m_Buffer.write(target);
	m_Buffer.write(renderbuffer);
}

void CommandBuffer::DeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers)
{
	m_Buffer.write_command(CommandId::DeleteRenderbuffers);
	m_Buffer.write(n);
	m_Buffer.write(renderbuffers);
}

RenderbufferHandle CommandBuffer::GenRenderbuffer()
{
	m_Buffer.write_command(CommandId::GenRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

void CommandBuffer::RenderbufferStorage(multigl::RenderbufferTarget target, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::RenderbufferStorage);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::GetRenderbufferParameteriv(multigl::RenderbufferTarget target, multigl::RenderbufferParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetRenderbufferParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BindFramebuffer(multigl::FramebufferTarget target, FramebufferHandle framebuffer)
{
	m_Buffer.write_command(CommandId::BindFramebuffer);
	m_Buffer.write(target);
	m_Buffer.write(framebuffer);
}

void CommandBuffer::DeleteFramebuffers(GLsizei n, const GLuint * framebuffers)
{
	m_Buffer.write_command(CommandId::DeleteFramebuffers);
	m_Buffer.write(n);
	m_Buffer.write(framebuffers);
}

FramebufferHandle CommandBuffer::GenFramebuffer()
{
	m_Buffer.write_command(CommandId::GenFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

void CommandBuffer::FramebufferTexture1D(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, multigl::TextureTarget textarget, TextureHandle texture, GLint level)
{
	m_Buffer.write_command(CommandId::FramebufferTexture1D);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(textarget);
	m_Buffer.write(texture);
	m_Buffer.write(level);
}

void CommandBuffer::FramebufferTexture2D(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, multigl::TextureTarget textarget, TextureHandle texture, GLint level)
{
	m_Buffer.write_command(CommandId::FramebufferTexture2D);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(textarget);
	m_Buffer.write(texture);
	m_Buffer.write(level);
}

void CommandBuffer::FramebufferTexture3D(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, multigl::TextureTarget textarget, TextureHandle texture, GLint level, GLint zoffset)
{
	m_Buffer.write_command(CommandId::FramebufferTexture3D);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(textarget);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(zoffset);
}

void CommandBuffer::FramebufferRenderbuffer(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, multigl::RenderbufferTarget renderbuffertarget, RenderbufferHandle renderbuffer)
{
	m_Buffer.write_command(CommandId::FramebufferRenderbuffer);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(renderbuffertarget);
	m_Buffer.write(renderbuffer);
}

void CommandBuffer::GetFramebufferAttachmentParameteriv(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, multigl::FramebufferAttachmentParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetFramebufferAttachmentParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GenerateMipmap(multigl::TextureTarget target)
{
	m_Buffer.write_command(CommandId::GenerateMipmap);
	m_Buffer.write(target);
}

void CommandBuffer::BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, multigl::BlitFramebufferFilter filter)
{
	m_Buffer.write_command(CommandId::BlitFramebuffer);
	m_Buffer.write(srcX0);
	m_Buffer.write(srcY0);
	m_Buffer.write(srcX1);
	m_Buffer.write(srcY1);
	m_Buffer.write(dstX0);
	m_Buffer.write(dstY0);
	m_Buffer.write(dstX1);
	m_Buffer.write(dstY1);
	m_Buffer.write(mask);
	m_Buffer.write(filter);
}

void CommandBuffer::RenderbufferStorageMultisample(multigl::RenderbufferTarget target, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::RenderbufferStorageMultisample);
	m_Buffer.write(target);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::FramebufferTextureLayer(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, TextureHandle texture, GLint level, GLint layer)
{
	m_Buffer.write_command(CommandId::FramebufferTextureLayer);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(layer);
}

void CommandBuffer::FlushMappedBufferRange(multigl::BufferTarget target, GLintptr offset, GLsizeiptr length)
{
	m_Buffer.write_command(CommandId::FlushMappedBufferRange);
	m_Buffer.write(target);
	m_Buffer.write(offset);
	m_Buffer.write(length);
}

void CommandBuffer::BindVertexArray(VertexArrayHandle array)
{
	m_Buffer.write_command(CommandId::BindVertexArray);
	m_Buffer.write(array);
}

void CommandBuffer::DeleteVertexArrays(GLsizei n, const GLuint * arrays)
{
	m_Buffer.write_command(CommandId::DeleteVertexArrays);
	m_Buffer.write(n);
	m_Buffer.write(arrays);
}

VertexArrayHandle CommandBuffer::GenVertexArray()
{
	m_Buffer.write_command(CommandId::GenVertexArray);

	auto handle = m_ResourceManager.VertexArrays.create(0);
	m_Buffer.write<VertexArrayHandle>(handle);
	return handle;
}

void CommandBuffer::DrawArraysInstanced(multigl::PrimitiveType mode, GLint first, GLsizei count, GLsizei instancecount)
{
	m_Buffer.write_command(CommandId::DrawArraysInstanced);
	m_Buffer.write(mode);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(instancecount);
}

void CommandBuffer::DrawElementsInstanced(multigl::PrimitiveType mode, GLsizei count, multigl::DrawElementsType type, const void * indices, GLsizei instancecount)
{
	m_Buffer.write_command(CommandId::DrawElementsInstanced);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(instancecount);
}

void CommandBuffer::TexBuffer(multigl::TextureTarget target, multigl::InternalFormat internalformat, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::TexBuffer);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(buffer);
}

void CommandBuffer::PrimitiveRestartIndex(GLuint index)
{
	m_Buffer.write_command(CommandId::PrimitiveRestartIndex);
	m_Buffer.write(index);
}

void CommandBuffer::CopyBufferSubData(multigl::CopyBufferSubDataTarget readTarget, multigl::CopyBufferSubDataTarget writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::CopyBufferSubData);
	m_Buffer.write(readTarget);
	m_Buffer.write(writeTarget);
	m_Buffer.write(readOffset);
	m_Buffer.write(writeOffset);
	m_Buffer.write(size);
}

void CommandBuffer::GetUniformIndices(ShaderProgramHandle program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices)
{
	m_Buffer.write_command(CommandId::GetUniformIndices);
	m_Buffer.write(program);
	m_Buffer.write(uniformCount);
	m_Buffer.write(uniformNames);
	m_Buffer.write(uniformIndices);
}

void CommandBuffer::GetActiveUniformsiv(ShaderProgramHandle program, GLsizei uniformCount, const GLuint * uniformIndices, multigl::UniformPName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetActiveUniformsiv);
	m_Buffer.write(program);
	m_Buffer.write(uniformCount);
	m_Buffer.write(uniformIndices);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetActiveUniformName(ShaderProgramHandle program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName)
{
	m_Buffer.write_command(CommandId::GetActiveUniformName);
	m_Buffer.write(program);
	m_Buffer.write(uniformIndex);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(uniformName);
}

void CommandBuffer::GetActiveUniformBlockiv(ShaderProgramHandle program, GLuint uniformBlockIndex, multigl::UniformBlockPName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetActiveUniformBlockiv);
	m_Buffer.write(program);
	m_Buffer.write(uniformBlockIndex);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetActiveUniformBlockName(ShaderProgramHandle program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName)
{
	m_Buffer.write_command(CommandId::GetActiveUniformBlockName);
	m_Buffer.write(program);
	m_Buffer.write(uniformBlockIndex);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(uniformBlockName);
}

void CommandBuffer::UniformBlockBinding(ShaderProgramHandle program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	m_Buffer.write_command(CommandId::UniformBlockBinding);
	m_Buffer.write(program);
	m_Buffer.write(uniformBlockIndex);
	m_Buffer.write(uniformBlockBinding);
}

void CommandBuffer::DrawElementsBaseVertex(multigl::PrimitiveType mode, GLsizei count, multigl::DrawElementsType type, const void * indices, GLint basevertex)
{
	m_Buffer.write_command(CommandId::DrawElementsBaseVertex);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(basevertex);
}

void CommandBuffer::DrawRangeElementsBaseVertex(multigl::PrimitiveType mode, GLuint start, GLuint end, GLsizei count, multigl::DrawElementsType type, const void * indices, GLint basevertex)
{
	m_Buffer.write_command(CommandId::DrawRangeElementsBaseVertex);
	m_Buffer.write(mode);
	m_Buffer.write(start);
	m_Buffer.write(end);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(basevertex);
}

void CommandBuffer::DrawElementsInstancedBaseVertex(multigl::PrimitiveType mode, GLsizei count, multigl::DrawElementsType type, const void * indices, GLsizei instancecount, GLint basevertex)
{
	m_Buffer.write_command(CommandId::DrawElementsInstancedBaseVertex);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(instancecount);
	m_Buffer.write(basevertex);
}

void CommandBuffer::MultiDrawElementsBaseVertex(multigl::PrimitiveType mode, const GLsizei * count, multigl::DrawElementsType type, const void *const* indices, GLsizei drawcount, const GLint * basevertex)
{
	m_Buffer.write_command(CommandId::MultiDrawElementsBaseVertex);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(drawcount);
	m_Buffer.write(basevertex);
}

void CommandBuffer::ProvokingVertex(multigl::VertexProvokingMode mode)
{
	m_Buffer.write_command(CommandId::ProvokingVertex);
	m_Buffer.write(mode);
}

void CommandBuffer::DeleteSync(GLsync sync)
{
	m_Buffer.write_command(CommandId::DeleteSync);
	m_Buffer.write(sync);
}

void CommandBuffer::WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
{
	m_Buffer.write_command(CommandId::WaitSync);
	m_Buffer.write(sync);
	m_Buffer.write(flags);
	m_Buffer.write(timeout);
}

void CommandBuffer::GetInteger64v(multigl::GetPName pname, GLint64 * data)
{
	m_Buffer.write_command(CommandId::GetInteger64v);
	m_Buffer.write(pname);
	m_Buffer.write(data);
}

void CommandBuffer::GetSynciv(GLsync sync, multigl::SyncParameterName pname, GLsizei count, GLsizei * length, GLint * values)
{
	m_Buffer.write_command(CommandId::GetSynciv);
	m_Buffer.write(sync);
	m_Buffer.write(pname);
	m_Buffer.write(count);
	m_Buffer.write(length);
	m_Buffer.write(values);
}

void CommandBuffer::GetInteger64i_v(GLenum target, GLuint index, GLint64 * data)
{
	m_Buffer.write_command(CommandId::GetInteger64i_v);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(data);
}

void CommandBuffer::GetBufferParameteri64v(multigl::BufferTarget target, multigl::BufferPNameARB pname, GLint64 * params)
{
	m_Buffer.write_command(CommandId::GetBufferParameteri64v);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::FramebufferTexture(multigl::FramebufferTarget target, multigl::FramebufferAttachment attachment, TextureHandle texture, GLint level)
{
	m_Buffer.write_command(CommandId::FramebufferTexture);
	m_Buffer.write(target);
	m_Buffer.write(attachment);
	m_Buffer.write(texture);
	m_Buffer.write(level);
}

void CommandBuffer::TexImage2DMultisample(multigl::TextureTarget target, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TexImage2DMultisample);
	m_Buffer.write(target);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::TexImage3DMultisample(multigl::TextureTarget target, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TexImage3DMultisample);
	m_Buffer.write(target);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::GetMultisamplefv(multigl::GetMultisamplePNameNV pname, GLuint index, GLfloat * val)
{
	m_Buffer.write_command(CommandId::GetMultisamplefv);
	m_Buffer.write(pname);
	m_Buffer.write(index);
	m_Buffer.write(val);
}

void CommandBuffer::SampleMaski(GLuint maskNumber, GLbitfield mask)
{
	m_Buffer.write_command(CommandId::SampleMaski);
	m_Buffer.write(maskNumber);
	m_Buffer.write(mask);
}

void CommandBuffer::BindFragDataLocationIndexed(ShaderProgramHandle program, GLuint colorNumber, GLuint index, const GLchar * name)
{
	m_Buffer.write_command(CommandId::BindFragDataLocationIndexed);
	m_Buffer.write(program);
	m_Buffer.write(colorNumber);
	m_Buffer.write(index);
	m_Buffer.write(name);
}

void CommandBuffer::GenSamplers(GLsizei count, GLuint * samplers)
{
	m_Buffer.write_command(CommandId::GenSamplers);
	m_Buffer.write(count);
	m_Buffer.write(samplers);
}

void CommandBuffer::DeleteSamplers(GLsizei count, const GLuint * samplers)
{
	m_Buffer.write_command(CommandId::DeleteSamplers);
	m_Buffer.write(count);
	m_Buffer.write(samplers);
}

void CommandBuffer::BindSampler(GLuint unit, GLuint sampler)
{
	m_Buffer.write_command(CommandId::BindSampler);
	m_Buffer.write(unit);
	m_Buffer.write(sampler);
}

void CommandBuffer::SamplerParameteri(GLuint sampler, multigl::SamplerParameterI pname, GLint param)
{
	m_Buffer.write_command(CommandId::SamplerParameteri);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::SamplerParameteriv(GLuint sampler, multigl::SamplerParameterI pname, const GLint * param)
{
	m_Buffer.write_command(CommandId::SamplerParameteriv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::SamplerParameterf(GLuint sampler, multigl::SamplerParameterF pname, GLfloat param)
{
	m_Buffer.write_command(CommandId::SamplerParameterf);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::SamplerParameterfv(GLuint sampler, multigl::SamplerParameterF pname, const GLfloat * param)
{
	m_Buffer.write_command(CommandId::SamplerParameterfv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::SamplerParameterIiv(GLuint sampler, multigl::SamplerParameterI pname, const GLint * param)
{
	m_Buffer.write_command(CommandId::SamplerParameterIiv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::SamplerParameterIuiv(GLuint sampler, multigl::SamplerParameterI pname, const GLuint * param)
{
	m_Buffer.write_command(CommandId::SamplerParameterIuiv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetSamplerParameteriv(GLuint sampler, multigl::SamplerParameterI pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetSamplerParameteriv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetSamplerParameterIiv(GLuint sampler, multigl::SamplerParameterI pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetSamplerParameterIiv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetSamplerParameterfv(GLuint sampler, multigl::SamplerParameterF pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetSamplerParameterfv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetSamplerParameterIuiv(GLuint sampler, multigl::SamplerParameterI pname, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetSamplerParameterIuiv);
	m_Buffer.write(sampler);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::QueryCounter(GLuint id, multigl::QueryCounterTarget target)
{
	m_Buffer.write_command(CommandId::QueryCounter);
	m_Buffer.write(id);
	m_Buffer.write(target);
}

void CommandBuffer::GetQueryObjecti64v(GLuint id, multigl::QueryObjectParameterName pname, GLint64 * params)
{
	m_Buffer.write_command(CommandId::GetQueryObjecti64v);
	m_Buffer.write(id);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetQueryObjectui64v(GLuint id, multigl::QueryObjectParameterName pname, GLuint64 * params)
{
	m_Buffer.write_command(CommandId::GetQueryObjectui64v);
	m_Buffer.write(id);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::VertexAttribDivisor(GLuint index, GLuint divisor)
{
	m_Buffer.write_command(CommandId::VertexAttribDivisor);
	m_Buffer.write(index);
	m_Buffer.write(divisor);
}

void CommandBuffer::VertexAttribP1ui(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexAttribP1ui);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP1uiv(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexAttribP1uiv);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP2ui(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexAttribP2ui);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP2uiv(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexAttribP2uiv);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP3ui(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexAttribP3ui);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP3uiv(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexAttribP3uiv);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP4ui(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexAttribP4ui);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexAttribP4uiv(GLuint index, multigl::VertexAttribPointerType type, GLboolean normalized, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexAttribP4uiv);
	m_Buffer.write(index);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP2ui(multigl::VertexPointerType type, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexP2ui);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP2uiv(multigl::VertexPointerType type, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexP2uiv);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP3ui(multigl::VertexPointerType type, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexP3ui);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP3uiv(multigl::VertexPointerType type, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexP3uiv);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP4ui(multigl::VertexPointerType type, GLuint value)
{
	m_Buffer.write_command(CommandId::VertexP4ui);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::VertexP4uiv(multigl::VertexPointerType type, const GLuint * value)
{
	m_Buffer.write_command(CommandId::VertexP4uiv);
	m_Buffer.write(type);
	m_Buffer.write(value);
}

void CommandBuffer::TexCoordP1ui(multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::TexCoordP1ui);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP1uiv(multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::TexCoordP1uiv);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP2ui(multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::TexCoordP2ui);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP2uiv(multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::TexCoordP2uiv);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP3ui(multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::TexCoordP3ui);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP3uiv(multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::TexCoordP3uiv);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP4ui(multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::TexCoordP4ui);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::TexCoordP4uiv(multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::TexCoordP4uiv);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP1ui(multigl::TextureHandle texture, multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP1ui);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP1uiv(multigl::TextureHandle texture, multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP1uiv);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP2ui(multigl::TextureHandle texture, multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP2ui);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP2uiv(multigl::TextureHandle texture, multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP2uiv);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP3ui(multigl::TextureHandle texture, multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP3ui);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP3uiv(multigl::TextureHandle texture, multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP3uiv);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP4ui(multigl::TextureHandle texture, multigl::TexCoordPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP4ui);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::MultiTexCoordP4uiv(multigl::TextureHandle texture, multigl::TexCoordPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::MultiTexCoordP4uiv);
	m_Buffer.write(texture);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::NormalP3ui(multigl::NormalPointerType type, GLuint coords)
{
	m_Buffer.write_command(CommandId::NormalP3ui);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::NormalP3uiv(multigl::NormalPointerType type, const GLuint * coords)
{
	m_Buffer.write_command(CommandId::NormalP3uiv);
	m_Buffer.write(type);
	m_Buffer.write(coords);
}

void CommandBuffer::ColorP3ui(multigl::ColorPointerType type, GLuint color)
{
	m_Buffer.write_command(CommandId::ColorP3ui);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::ColorP3uiv(multigl::ColorPointerType type, const GLuint * color)
{
	m_Buffer.write_command(CommandId::ColorP3uiv);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::ColorP4ui(multigl::ColorPointerType type, GLuint color)
{
	m_Buffer.write_command(CommandId::ColorP4ui);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::ColorP4uiv(multigl::ColorPointerType type, const GLuint * color)
{
	m_Buffer.write_command(CommandId::ColorP4uiv);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::SecondaryColorP3ui(multigl::ColorPointerType type, GLuint color)
{
	m_Buffer.write_command(CommandId::SecondaryColorP3ui);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::SecondaryColorP3uiv(multigl::ColorPointerType type, const GLuint * color)
{
	m_Buffer.write_command(CommandId::SecondaryColorP3uiv);
	m_Buffer.write(type);
	m_Buffer.write(color);
}

void CommandBuffer::MinSampleShading(GLfloat value)
{
	m_Buffer.write_command(CommandId::MinSampleShading);
	m_Buffer.write(value);
}

void CommandBuffer::BlendEquationi(GLuint buf, multigl::BlendEquationModeEXT mode)
{
	m_Buffer.write_command(CommandId::BlendEquationi);
	m_Buffer.write(buf);
	m_Buffer.write(mode);
}

void CommandBuffer::BlendEquationSeparatei(GLuint buf, multigl::BlendEquationModeEXT modeRGB, multigl::BlendEquationModeEXT modeAlpha)
{
	m_Buffer.write_command(CommandId::BlendEquationSeparatei);
	m_Buffer.write(buf);
	m_Buffer.write(modeRGB);
	m_Buffer.write(modeAlpha);
}

void CommandBuffer::BlendFunci(GLuint buf, multigl::BlendingFactor src, multigl::BlendingFactor dst)
{
	m_Buffer.write_command(CommandId::BlendFunci);
	m_Buffer.write(buf);
	m_Buffer.write(src);
	m_Buffer.write(dst);
}

void CommandBuffer::BlendFuncSeparatei(GLuint buf, multigl::BlendingFactor srcRGB, multigl::BlendingFactor dstRGB, multigl::BlendingFactor srcAlpha, multigl::BlendingFactor dstAlpha)
{
	m_Buffer.write_command(CommandId::BlendFuncSeparatei);
	m_Buffer.write(buf);
	m_Buffer.write(srcRGB);
	m_Buffer.write(dstRGB);
	m_Buffer.write(srcAlpha);
	m_Buffer.write(dstAlpha);
}

void CommandBuffer::DrawArraysIndirect(multigl::PrimitiveType mode, const void * indirect)
{
	m_Buffer.write_command(CommandId::DrawArraysIndirect);
	m_Buffer.write(mode);
	m_Buffer.write(indirect);
}

void CommandBuffer::DrawElementsIndirect(multigl::PrimitiveType mode, multigl::DrawElementsType type, const void * indirect)
{
	m_Buffer.write_command(CommandId::DrawElementsIndirect);
	m_Buffer.write(mode);
	m_Buffer.write(type);
	m_Buffer.write(indirect);
}

void CommandBuffer::Uniform1d(GLint location, GLdouble x)
{
	m_Buffer.write_command(CommandId::Uniform1d);
	m_Buffer.write(location);
	m_Buffer.write(x);
}

void CommandBuffer::Uniform2d(GLint location, GLdouble x, GLdouble y)
{
	m_Buffer.write_command(CommandId::Uniform2d);
	m_Buffer.write(location);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z)
{
	m_Buffer.write_command(CommandId::Uniform3d);
	m_Buffer.write(location);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	m_Buffer.write_command(CommandId::Uniform4d);
	m_Buffer.write(location);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::Uniform1dv(GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::Uniform1dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform2dv(GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::Uniform2dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform3dv(GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::Uniform3dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::Uniform4dv(GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::Uniform4dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2x3dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix2x4dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3x2dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix3x4dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4x2dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::UniformMatrix4x3dv);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::GetUniformdv(ShaderProgramHandle program, GLint location, GLdouble * params)
{
	m_Buffer.write_command(CommandId::GetUniformdv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(params);
}

void CommandBuffer::GetActiveSubroutineUniformiv(ShaderProgramHandle program, multigl::ShaderType shadertype, GLuint index, multigl::SubroutineParameterName pname, GLint * values)
{
	m_Buffer.write_command(CommandId::GetActiveSubroutineUniformiv);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(values);
}

void CommandBuffer::GetActiveSubroutineUniformName(ShaderProgramHandle program, multigl::ShaderType shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetActiveSubroutineUniformName);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(name);
}

void CommandBuffer::GetActiveSubroutineName(ShaderProgramHandle program, multigl::ShaderType shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetActiveSubroutineName);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(name);
}

void CommandBuffer::UniformSubroutinesuiv(multigl::ShaderType shadertype, GLsizei count, const GLuint * indices)
{
	m_Buffer.write_command(CommandId::UniformSubroutinesuiv);
	m_Buffer.write(shadertype);
	m_Buffer.write(count);
	m_Buffer.write(indices);
}

void CommandBuffer::GetUniformSubroutineuiv(multigl::ShaderType shadertype, GLint location, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetUniformSubroutineuiv);
	m_Buffer.write(shadertype);
	m_Buffer.write(location);
	m_Buffer.write(params);
}

void CommandBuffer::GetProgramStageiv(ShaderProgramHandle program, multigl::ShaderType shadertype, multigl::ProgramStagePName pname, GLint * values)
{
	m_Buffer.write_command(CommandId::GetProgramStageiv);
	m_Buffer.write(program);
	m_Buffer.write(shadertype);
	m_Buffer.write(pname);
	m_Buffer.write(values);
}

void CommandBuffer::PatchParameteri(multigl::PatchParameterName pname, GLint value)
{
	m_Buffer.write_command(CommandId::PatchParameteri);
	m_Buffer.write(pname);
	m_Buffer.write(value);
}

void CommandBuffer::PatchParameterfv(multigl::PatchParameterName pname, const GLfloat * values)
{
	m_Buffer.write_command(CommandId::PatchParameterfv);
	m_Buffer.write(pname);
	m_Buffer.write(values);
}

void CommandBuffer::BindTransformFeedback(multigl::BindTransformFeedbackTarget target, GLuint id)
{
	m_Buffer.write_command(CommandId::BindTransformFeedback);
	m_Buffer.write(target);
	m_Buffer.write(id);
}

void CommandBuffer::DeleteTransformFeedbacks(GLsizei n, const GLuint * ids)
{
	m_Buffer.write_command(CommandId::DeleteTransformFeedbacks);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::GenTransformFeedbacks(GLsizei n, GLuint * ids)
{
	m_Buffer.write_command(CommandId::GenTransformFeedbacks);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::PauseTransformFeedback()
{
	m_Buffer.write_command(CommandId::PauseTransformFeedback);
}

void CommandBuffer::ResumeTransformFeedback()
{
	m_Buffer.write_command(CommandId::ResumeTransformFeedback);
}

void CommandBuffer::DrawTransformFeedback(multigl::PrimitiveType mode, GLuint id)
{
	m_Buffer.write_command(CommandId::DrawTransformFeedback);
	m_Buffer.write(mode);
	m_Buffer.write(id);
}

void CommandBuffer::DrawTransformFeedbackStream(multigl::PrimitiveType mode, GLuint id, GLuint stream)
{
	m_Buffer.write_command(CommandId::DrawTransformFeedbackStream);
	m_Buffer.write(mode);
	m_Buffer.write(id);
	m_Buffer.write(stream);
}

void CommandBuffer::BeginQueryIndexed(multigl::QueryTarget target, GLuint index, GLuint id)
{
	m_Buffer.write_command(CommandId::BeginQueryIndexed);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(id);
}

void CommandBuffer::EndQueryIndexed(multigl::QueryTarget target, GLuint index)
{
	m_Buffer.write_command(CommandId::EndQueryIndexed);
	m_Buffer.write(target);
	m_Buffer.write(index);
}

void CommandBuffer::GetQueryIndexediv(multigl::QueryTarget target, GLuint index, multigl::QueryParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetQueryIndexediv);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::ReleaseShaderCompiler()
{
	m_Buffer.write_command(CommandId::ReleaseShaderCompiler);
}

void CommandBuffer::ShaderBinary(GLsizei count, const GLuint * shaders, GLenum binaryformat, const void * binary, GLsizei length)
{
	m_Buffer.write_command(CommandId::ShaderBinary);
	m_Buffer.write(count);
	m_Buffer.write(shaders);
	m_Buffer.write(binaryformat);
	m_Buffer.write(binary);
	m_Buffer.write(length);
}

void CommandBuffer::GetShaderPrecisionFormat(multigl::ShaderType shadertype, multigl::PrecisionType precisiontype, GLint * range, GLint * precision)
{
	m_Buffer.write_command(CommandId::GetShaderPrecisionFormat);
	m_Buffer.write(shadertype);
	m_Buffer.write(precisiontype);
	m_Buffer.write(range);
	m_Buffer.write(precision);
}

void CommandBuffer::DepthRangef(GLfloat n, GLfloat f)
{
	m_Buffer.write_command(CommandId::DepthRangef);
	m_Buffer.write(n);
	m_Buffer.write(f);
}

void CommandBuffer::ClearDepthf(GLfloat d)
{
	m_Buffer.write_command(CommandId::ClearDepthf);
	m_Buffer.write(d);
}

void CommandBuffer::GetProgramBinary(ShaderProgramHandle program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary)
{
	m_Buffer.write_command(CommandId::GetProgramBinary);
	m_Buffer.write(program);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(binaryFormat);
	m_Buffer.write(binary);
}

void CommandBuffer::ProgramBinary(ShaderProgramHandle program, GLenum binaryFormat, const void * binary, GLsizei length)
{
	m_Buffer.write_command(CommandId::ProgramBinary);
	m_Buffer.write(program);
	m_Buffer.write(binaryFormat);
	m_Buffer.write(binary);
	m_Buffer.write(length);
}

void CommandBuffer::ProgramParameteri(ShaderProgramHandle program, multigl::ProgramParameterPName pname, GLint value)
{
	m_Buffer.write_command(CommandId::ProgramParameteri);
	m_Buffer.write(program);
	m_Buffer.write(pname);
	m_Buffer.write(value);
}

void CommandBuffer::UseProgramStages(GLuint pipeline, GLbitfield stages, ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::UseProgramStages);
	m_Buffer.write(pipeline);
	m_Buffer.write(stages);
	m_Buffer.write(program);
}

void CommandBuffer::ActiveShaderProgram(GLuint pipeline, ShaderProgramHandle program)
{
	m_Buffer.write_command(CommandId::ActiveShaderProgram);
	m_Buffer.write(pipeline);
	m_Buffer.write(program);
}

void CommandBuffer::BindProgramPipeline(GLuint pipeline)
{
	m_Buffer.write_command(CommandId::BindProgramPipeline);
	m_Buffer.write(pipeline);
}

void CommandBuffer::DeleteProgramPipelines(GLsizei n, const GLuint * pipelines)
{
	m_Buffer.write_command(CommandId::DeleteProgramPipelines);
	m_Buffer.write(n);
	m_Buffer.write(pipelines);
}

void CommandBuffer::GenProgramPipelines(GLsizei n, GLuint * pipelines)
{
	m_Buffer.write_command(CommandId::GenProgramPipelines);
	m_Buffer.write(n);
	m_Buffer.write(pipelines);
}

void CommandBuffer::GetProgramPipelineiv(GLuint pipeline, multigl::PipelineParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetProgramPipelineiv);
	m_Buffer.write(pipeline);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::ProgramUniform1i(ShaderProgramHandle program, GLint location, GLint v0)
{
	m_Buffer.write_command(CommandId::ProgramUniform1i);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::ProgramUniform1iv(ShaderProgramHandle program, GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform1iv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform1f(ShaderProgramHandle program, GLint location, GLfloat v0)
{
	m_Buffer.write_command(CommandId::ProgramUniform1f);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::ProgramUniform1fv(ShaderProgramHandle program, GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform1fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform1d(ShaderProgramHandle program, GLint location, GLdouble v0)
{
	m_Buffer.write_command(CommandId::ProgramUniform1d);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::ProgramUniform1dv(ShaderProgramHandle program, GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform1dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform1ui(ShaderProgramHandle program, GLint location, GLuint v0)
{
	m_Buffer.write_command(CommandId::ProgramUniform1ui);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
}

void CommandBuffer::ProgramUniform1uiv(ShaderProgramHandle program, GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform1uiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform2i(ShaderProgramHandle program, GLint location, GLint v0, GLint v1)
{
	m_Buffer.write_command(CommandId::ProgramUniform2i);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::ProgramUniform2iv(ShaderProgramHandle program, GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform2iv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform2f(ShaderProgramHandle program, GLint location, GLfloat v0, GLfloat v1)
{
	m_Buffer.write_command(CommandId::ProgramUniform2f);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::ProgramUniform2fv(ShaderProgramHandle program, GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform2fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform2d(ShaderProgramHandle program, GLint location, GLdouble v0, GLdouble v1)
{
	m_Buffer.write_command(CommandId::ProgramUniform2d);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::ProgramUniform2dv(ShaderProgramHandle program, GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform2dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform2ui(ShaderProgramHandle program, GLint location, GLuint v0, GLuint v1)
{
	m_Buffer.write_command(CommandId::ProgramUniform2ui);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
}

void CommandBuffer::ProgramUniform2uiv(ShaderProgramHandle program, GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform2uiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform3i(ShaderProgramHandle program, GLint location, GLint v0, GLint v1, GLint v2)
{
	m_Buffer.write_command(CommandId::ProgramUniform3i);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::ProgramUniform3iv(ShaderProgramHandle program, GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform3iv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform3f(ShaderProgramHandle program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
	m_Buffer.write_command(CommandId::ProgramUniform3f);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::ProgramUniform3fv(ShaderProgramHandle program, GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform3fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform3d(ShaderProgramHandle program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2)
{
	m_Buffer.write_command(CommandId::ProgramUniform3d);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::ProgramUniform3dv(ShaderProgramHandle program, GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform3dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform3ui(ShaderProgramHandle program, GLint location, GLuint v0, GLuint v1, GLuint v2)
{
	m_Buffer.write_command(CommandId::ProgramUniform3ui);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
}

void CommandBuffer::ProgramUniform3uiv(ShaderProgramHandle program, GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform3uiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform4i(ShaderProgramHandle program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
	m_Buffer.write_command(CommandId::ProgramUniform4i);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::ProgramUniform4iv(ShaderProgramHandle program, GLint location, GLsizei count, const GLint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform4iv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform4f(ShaderProgramHandle program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
	m_Buffer.write_command(CommandId::ProgramUniform4f);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::ProgramUniform4fv(ShaderProgramHandle program, GLint location, GLsizei count, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform4fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform4d(ShaderProgramHandle program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3)
{
	m_Buffer.write_command(CommandId::ProgramUniform4d);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::ProgramUniform4dv(ShaderProgramHandle program, GLint location, GLsizei count, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform4dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniform4ui(ShaderProgramHandle program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
{
	m_Buffer.write_command(CommandId::ProgramUniform4ui);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(v0);
	m_Buffer.write(v1);
	m_Buffer.write(v2);
	m_Buffer.write(v3);
}

void CommandBuffer::ProgramUniform4uiv(ShaderProgramHandle program, GLint location, GLsizei count, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ProgramUniform4uiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2x3fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2x3fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3x2fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3x2fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2x4fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2x4fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4x2fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4x2fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3x4fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3x4fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4x3fv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4x3fv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2x3dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2x3dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3x2dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3x2dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix2x4dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix2x4dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4x2dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4x2dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix3x4dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix3x4dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ProgramUniformMatrix4x3dv(ShaderProgramHandle program, GLint location, GLsizei count, GLboolean transpose, const GLdouble * value)
{
	m_Buffer.write_command(CommandId::ProgramUniformMatrix4x3dv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(count);
	m_Buffer.write(transpose);
	m_Buffer.write(value);
}

void CommandBuffer::ValidateProgramPipeline(GLuint pipeline)
{
	m_Buffer.write_command(CommandId::ValidateProgramPipeline);
	m_Buffer.write(pipeline);
}

void CommandBuffer::GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	m_Buffer.write_command(CommandId::GetProgramPipelineInfoLog);
	m_Buffer.write(pipeline);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(infoLog);
}

void CommandBuffer::VertexAttribL1d(GLuint index, GLdouble x)
{
	m_Buffer.write_command(CommandId::VertexAttribL1d);
	m_Buffer.write(index);
	m_Buffer.write(x);
}

void CommandBuffer::VertexAttribL2d(GLuint index, GLdouble x, GLdouble y)
{
	m_Buffer.write_command(CommandId::VertexAttribL2d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
}

void CommandBuffer::VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z)
{
	m_Buffer.write_command(CommandId::VertexAttribL3d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
}

void CommandBuffer::VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w)
{
	m_Buffer.write_command(CommandId::VertexAttribL4d);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(z);
	m_Buffer.write(w);
}

void CommandBuffer::VertexAttribL1dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttribL1dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribL2dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttribL2dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribL3dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttribL3dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribL4dv(GLuint index, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::VertexAttribL4dv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::VertexAttribLPointer(GLuint index, GLint size, multigl::VertexAttribPointerType type, GLsizei stride, const void * pointer)
{
	m_Buffer.write_command(CommandId::VertexAttribLPointer);
	m_Buffer.write(index);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(stride);
	m_Buffer.write(pointer);
}

void CommandBuffer::GetVertexAttribLdv(GLuint index, multigl::VertexAttribEnum pname, GLdouble * params)
{
	m_Buffer.write_command(CommandId::GetVertexAttribLdv);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::ViewportArrayv(GLuint first, GLsizei count, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::ViewportArrayv);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(v);
}

void CommandBuffer::ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	m_Buffer.write_command(CommandId::ViewportIndexedf);
	m_Buffer.write(index);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(w);
	m_Buffer.write(h);
}

void CommandBuffer::ViewportIndexedfv(GLuint index, const GLfloat * v)
{
	m_Buffer.write_command(CommandId::ViewportIndexedfv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::ScissorArrayv(GLuint first, GLsizei count, const GLint * v)
{
	m_Buffer.write_command(CommandId::ScissorArrayv);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(v);
}

void CommandBuffer::ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::ScissorIndexed);
	m_Buffer.write(index);
	m_Buffer.write(left);
	m_Buffer.write(bottom);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::ScissorIndexedv(GLuint index, const GLint * v)
{
	m_Buffer.write_command(CommandId::ScissorIndexedv);
	m_Buffer.write(index);
	m_Buffer.write(v);
}

void CommandBuffer::DepthRangeArrayv(GLuint first, GLsizei count, const GLdouble * v)
{
	m_Buffer.write_command(CommandId::DepthRangeArrayv);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(v);
}

void CommandBuffer::DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f)
{
	m_Buffer.write_command(CommandId::DepthRangeIndexed);
	m_Buffer.write(index);
	m_Buffer.write(n);
	m_Buffer.write(f);
}

void CommandBuffer::GetFloati_v(GLenum target, GLuint index, GLfloat * data)
{
	m_Buffer.write_command(CommandId::GetFloati_v);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(data);
}

void CommandBuffer::GetDoublei_v(GLenum target, GLuint index, GLdouble * data)
{
	m_Buffer.write_command(CommandId::GetDoublei_v);
	m_Buffer.write(target);
	m_Buffer.write(index);
	m_Buffer.write(data);
}

void CommandBuffer::DrawArraysInstancedBaseInstance(multigl::PrimitiveType mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance)
{
	m_Buffer.write_command(CommandId::DrawArraysInstancedBaseInstance);
	m_Buffer.write(mode);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(instancecount);
	m_Buffer.write(baseinstance);
}

void CommandBuffer::DrawElementsInstancedBaseInstance(multigl::PrimitiveType mode, GLsizei count, multigl::PrimitiveType type, const void * indices, GLsizei instancecount, GLuint baseinstance)
{
	m_Buffer.write_command(CommandId::DrawElementsInstancedBaseInstance);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(instancecount);
	m_Buffer.write(baseinstance);
}

void CommandBuffer::DrawElementsInstancedBaseVertexBaseInstance(multigl::PrimitiveType mode, GLsizei count, multigl::DrawElementsType type, const void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance)
{
	m_Buffer.write_command(CommandId::DrawElementsInstancedBaseVertexBaseInstance);
	m_Buffer.write(mode);
	m_Buffer.write(count);
	m_Buffer.write(type);
	m_Buffer.write(indices);
	m_Buffer.write(instancecount);
	m_Buffer.write(basevertex);
	m_Buffer.write(baseinstance);
}

void CommandBuffer::GetInternalformativ(multigl::TextureTarget target, multigl::InternalFormat internalformat, multigl::InternalFormatPName pname, GLsizei count, GLint * params)
{
	m_Buffer.write_command(CommandId::GetInternalformativ);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(pname);
	m_Buffer.write(count);
	m_Buffer.write(params);
}

void CommandBuffer::GetActiveAtomicCounterBufferiv(ShaderProgramHandle program, GLuint bufferIndex, multigl::AtomicCounterBufferPName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetActiveAtomicCounterBufferiv);
	m_Buffer.write(program);
	m_Buffer.write(bufferIndex);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BindImageTexture(GLuint unit, TextureHandle texture, GLint level, GLboolean layered, GLint layer, multigl::BufferAccessARB access, multigl::InternalFormat format)
{
	m_Buffer.write_command(CommandId::BindImageTexture);
	m_Buffer.write(unit);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(layered);
	m_Buffer.write(layer);
	m_Buffer.write(access);
	m_Buffer.write(format);
}

void CommandBuffer::MemoryBarrier(GLbitfield barriers)
{
	m_Buffer.write_command(CommandId::MemoryBarrier);
	m_Buffer.write(barriers);
}

void CommandBuffer::TexStorage1D(multigl::TextureTarget target, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width)
{
	m_Buffer.write_command(CommandId::TexStorage1D);
	m_Buffer.write(target);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
}

void CommandBuffer::TexStorage2D(multigl::TextureTarget target, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::TexStorage2D);
	m_Buffer.write(target);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::TexStorage3D(multigl::TextureTarget target, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	m_Buffer.write_command(CommandId::TexStorage3D);
	m_Buffer.write(target);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
}

void CommandBuffer::DrawTransformFeedbackInstanced(multigl::PrimitiveType mode, GLuint id, GLsizei instancecount)
{
	m_Buffer.write_command(CommandId::DrawTransformFeedbackInstanced);
	m_Buffer.write(mode);
	m_Buffer.write(id);
	m_Buffer.write(instancecount);
}

void CommandBuffer::DrawTransformFeedbackStreamInstanced(multigl::PrimitiveType mode, GLuint id, GLuint stream, GLsizei instancecount)
{
	m_Buffer.write_command(CommandId::DrawTransformFeedbackStreamInstanced);
	m_Buffer.write(mode);
	m_Buffer.write(id);
	m_Buffer.write(stream);
	m_Buffer.write(instancecount);
}

void CommandBuffer::ClearBufferData(multigl::BufferStorageTarget target, multigl::InternalFormat internalformat, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearBufferData);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::ClearBufferSubData(multigl::BufferTarget target, multigl::InternalFormat internalformat, GLintptr offset, GLsizeiptr size, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearBufferSubData);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
{
	m_Buffer.write_command(CommandId::DispatchCompute);
	m_Buffer.write(num_groups_x);
	m_Buffer.write(num_groups_y);
	m_Buffer.write(num_groups_z);
}

void CommandBuffer::DispatchComputeIndirect(GLintptr indirect)
{
	m_Buffer.write_command(CommandId::DispatchComputeIndirect);
	m_Buffer.write(indirect);
}

void CommandBuffer::CopyImageSubData(GLuint srcName, multigl::CopyImageSubDataTarget srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, multigl::CopyImageSubDataTarget dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
	m_Buffer.write_command(CommandId::CopyImageSubData);
	m_Buffer.write(srcName);
	m_Buffer.write(srcTarget);
	m_Buffer.write(srcLevel);
	m_Buffer.write(srcX);
	m_Buffer.write(srcY);
	m_Buffer.write(srcZ);
	m_Buffer.write(dstName);
	m_Buffer.write(dstTarget);
	m_Buffer.write(dstLevel);
	m_Buffer.write(dstX);
	m_Buffer.write(dstY);
	m_Buffer.write(dstZ);
	m_Buffer.write(srcWidth);
	m_Buffer.write(srcHeight);
	m_Buffer.write(srcDepth);
}

void CommandBuffer::FramebufferParameteri(multigl::FramebufferTarget target, multigl::FramebufferParameterName pname, GLint param)
{
	m_Buffer.write_command(CommandId::FramebufferParameteri);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetFramebufferParameteriv(multigl::FramebufferTarget target, multigl::FramebufferAttachmentParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetFramebufferParameteriv);
	m_Buffer.write(target);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetInternalformati64v(multigl::TextureTarget target, multigl::InternalFormat internalformat, multigl::InternalFormatPName pname, GLsizei count, GLint64 * params)
{
	m_Buffer.write_command(CommandId::GetInternalformati64v);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(pname);
	m_Buffer.write(count);
	m_Buffer.write(params);
}

void CommandBuffer::InvalidateTexSubImage(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
{
	m_Buffer.write_command(CommandId::InvalidateTexSubImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
}

void CommandBuffer::InvalidateTexImage(TextureHandle texture, GLint level)
{
	m_Buffer.write_command(CommandId::InvalidateTexImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
}

void CommandBuffer::InvalidateBufferSubData(BufferHandle buffer, GLintptr offset, GLsizeiptr length)
{
	m_Buffer.write_command(CommandId::InvalidateBufferSubData);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(length);
}

void CommandBuffer::InvalidateBufferData(BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::InvalidateBufferData);
	m_Buffer.write(buffer);
}

void CommandBuffer::InvalidateFramebuffer(multigl::FramebufferTarget target, GLsizei numAttachments, const GLenum * attachments)
{
	m_Buffer.write_command(CommandId::InvalidateFramebuffer);
	m_Buffer.write(target);
	m_Buffer.write(numAttachments);
	m_Buffer.write(attachments);
}

void CommandBuffer::InvalidateSubFramebuffer(multigl::FramebufferTarget target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::InvalidateSubFramebuffer);
	m_Buffer.write(target);
	m_Buffer.write(numAttachments);
	m_Buffer.write(attachments);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::MultiDrawArraysIndirect(multigl::PrimitiveType mode, const void * indirect, GLsizei drawcount, GLsizei stride)
{
	m_Buffer.write_command(CommandId::MultiDrawArraysIndirect);
	m_Buffer.write(mode);
	m_Buffer.write(indirect);
	m_Buffer.write(drawcount);
	m_Buffer.write(stride);
}

void CommandBuffer::MultiDrawElementsIndirect(multigl::PrimitiveType mode, multigl::DrawElementsType type, const void * indirect, GLsizei drawcount, GLsizei stride)
{
	m_Buffer.write_command(CommandId::MultiDrawElementsIndirect);
	m_Buffer.write(mode);
	m_Buffer.write(type);
	m_Buffer.write(indirect);
	m_Buffer.write(drawcount);
	m_Buffer.write(stride);
}

void CommandBuffer::GetProgramInterfaceiv(ShaderProgramHandle program, multigl::ProgramInterface programInterface, multigl::ProgramInterfacePName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetProgramInterfaceiv);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetProgramResourceName(ShaderProgramHandle program, multigl::ProgramInterface programInterface, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name)
{
	m_Buffer.write_command(CommandId::GetProgramResourceName);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(index);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(name);
}

void CommandBuffer::GetProgramResourceiv(ShaderProgramHandle program, multigl::ProgramInterface programInterface, GLuint index, GLsizei propCount, const GLenum * props, GLsizei count, GLsizei * length, GLint * params)
{
	m_Buffer.write_command(CommandId::GetProgramResourceiv);
	m_Buffer.write(program);
	m_Buffer.write(programInterface);
	m_Buffer.write(index);
	m_Buffer.write(propCount);
	m_Buffer.write(props);
	m_Buffer.write(count);
	m_Buffer.write(length);
	m_Buffer.write(params);
}

void CommandBuffer::ShaderStorageBlockBinding(ShaderProgramHandle program, GLuint storageBlockIndex, GLuint storageBlockBinding)
{
	m_Buffer.write_command(CommandId::ShaderStorageBlockBinding);
	m_Buffer.write(program);
	m_Buffer.write(storageBlockIndex);
	m_Buffer.write(storageBlockBinding);
}

void CommandBuffer::TexBufferRange(multigl::TextureTarget target, multigl::InternalFormat internalformat, BufferHandle buffer, GLintptr offset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::TexBufferRange);
	m_Buffer.write(target);
	m_Buffer.write(internalformat);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
}

void CommandBuffer::TexStorage2DMultisample(multigl::TextureTarget target, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TexStorage2DMultisample);
	m_Buffer.write(target);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::TexStorage3DMultisample(multigl::TextureTarget target, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TexStorage3DMultisample);
	m_Buffer.write(target);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::TextureView(TextureHandle texture, multigl::TextureTarget target, GLuint origtexture, multigl::InternalFormat internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
{
	m_Buffer.write_command(CommandId::TextureView);
	m_Buffer.write(texture);
	m_Buffer.write(target);
	m_Buffer.write(origtexture);
	m_Buffer.write(internalformat);
	m_Buffer.write(minlevel);
	m_Buffer.write(numlevels);
	m_Buffer.write(minlayer);
	m_Buffer.write(numlayers);
}

void CommandBuffer::BindVertexBuffer(GLuint bindingindex, BufferHandle buffer, GLintptr offset, GLsizei stride)
{
	m_Buffer.write_command(CommandId::BindVertexBuffer);
	m_Buffer.write(bindingindex);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(stride);
}

void CommandBuffer::VertexAttribFormat(GLuint attribindex, GLint size, multigl::VertexAttribType type, GLboolean normalized, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexAttribFormat);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexAttribIFormat(GLuint attribindex, GLint size, multigl::VertexAttribIType type, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexAttribIFormat);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexAttribLFormat(GLuint attribindex, GLint size, multigl::VertexAttribLType type, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexAttribLFormat);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexAttribBinding(GLuint attribindex, GLuint bindingindex)
{
	m_Buffer.write_command(CommandId::VertexAttribBinding);
	m_Buffer.write(attribindex);
	m_Buffer.write(bindingindex);
}

void CommandBuffer::VertexBindingDivisor(GLuint bindingindex, GLuint divisor)
{
	m_Buffer.write_command(CommandId::VertexBindingDivisor);
	m_Buffer.write(bindingindex);
	m_Buffer.write(divisor);
}

void CommandBuffer::DebugMessageControl(multigl::DebugSource source, multigl::DebugType type, multigl::DebugSeverity severity, GLsizei count, const GLuint * ids, GLboolean enabled)
{
	m_Buffer.write_command(CommandId::DebugMessageControl);
	m_Buffer.write(source);
	m_Buffer.write(type);
	m_Buffer.write(severity);
	m_Buffer.write(count);
	m_Buffer.write(ids);
	m_Buffer.write(enabled);
}

void CommandBuffer::DebugMessageInsert(multigl::DebugSource source, multigl::DebugType type, GLuint id, multigl::DebugSeverity severity, GLsizei length, const GLchar * buf)
{
	m_Buffer.write_command(CommandId::DebugMessageInsert);
	m_Buffer.write(source);
	m_Buffer.write(type);
	m_Buffer.write(id);
	m_Buffer.write(severity);
	m_Buffer.write(length);
	m_Buffer.write(buf);
}

void CommandBuffer::DebugMessageCallback(GLDEBUGPROC callback, const void * userParam)
{
	m_Buffer.write_command(CommandId::DebugMessageCallback);
	m_Buffer.write(callback);
	m_Buffer.write(userParam);
}

void CommandBuffer::PushDebugGroup(multigl::DebugSource source, GLuint id, GLsizei length, const GLchar * message)
{
	m_Buffer.write_command(CommandId::PushDebugGroup);
	m_Buffer.write(source);
	m_Buffer.write(id);
	m_Buffer.write(length);
	m_Buffer.write(message);
}

void CommandBuffer::PopDebugGroup()
{
	m_Buffer.write_command(CommandId::PopDebugGroup);
}

void CommandBuffer::ObjectLabel(multigl::ObjectIdentifier identifier, GLuint name, GLsizei length, const GLchar * label)
{
	m_Buffer.write_command(CommandId::ObjectLabel);
	m_Buffer.write(identifier);
	m_Buffer.write(name);
	m_Buffer.write(length);
	m_Buffer.write(label);
}

void CommandBuffer::GetObjectLabel(multigl::ObjectIdentifier identifier, GLuint name, GLsizei bufSize, GLsizei * length, GLchar * label)
{
	m_Buffer.write_command(CommandId::GetObjectLabel);
	m_Buffer.write(identifier);
	m_Buffer.write(name);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(label);
}

void CommandBuffer::ObjectPtrLabel(const void * ptr, GLsizei length, const GLchar * label)
{
	m_Buffer.write_command(CommandId::ObjectPtrLabel);
	m_Buffer.write(ptr);
	m_Buffer.write(length);
	m_Buffer.write(label);
}

void CommandBuffer::GetObjectPtrLabel(const void * ptr, GLsizei bufSize, GLsizei * length, GLchar * label)
{
	m_Buffer.write_command(CommandId::GetObjectPtrLabel);
	m_Buffer.write(ptr);
	m_Buffer.write(bufSize);
	m_Buffer.write(length);
	m_Buffer.write(label);
}

void CommandBuffer::GetPointerv(multigl::GetPointervPName pname, void ** params)
{
	m_Buffer.write_command(CommandId::GetPointerv);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::BufferStorage(multigl::BufferStorageTarget target, GLsizeiptr size, const void * data, GLbitfield flags)
{
	m_Buffer.write_command(CommandId::BufferStorage);
	m_Buffer.write(target);
	m_Buffer.write(size);
	m_Buffer.write(data);
	m_Buffer.write(flags);
}

void CommandBuffer::ClearTexImage(TextureHandle texture, GLint level, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearTexImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::ClearTexSubImage(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearTexSubImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::BindBuffersBase(multigl::BufferTarget target, GLuint first, GLsizei count, const GLuint * buffers)
{
	m_Buffer.write_command(CommandId::BindBuffersBase);
	m_Buffer.write(target);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(buffers);
}

void CommandBuffer::BindBuffersRange(multigl::BufferTarget target, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizeiptr * sizes)
{
	m_Buffer.write_command(CommandId::BindBuffersRange);
	m_Buffer.write(target);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(buffers);
	m_Buffer.write(offsets);
	m_Buffer.write(sizes);
}

void CommandBuffer::BindTextures(GLuint first, GLsizei count, const GLuint * textures)
{
	m_Buffer.write_command(CommandId::BindTextures);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(textures);
}

void CommandBuffer::BindSamplers(GLuint first, GLsizei count, const GLuint * samplers)
{
	m_Buffer.write_command(CommandId::BindSamplers);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(samplers);
}

void CommandBuffer::BindImageTextures(GLuint first, GLsizei count, const GLuint * textures)
{
	m_Buffer.write_command(CommandId::BindImageTextures);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(textures);
}

void CommandBuffer::BindVertexBuffers(GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides)
{
	m_Buffer.write_command(CommandId::BindVertexBuffers);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(buffers);
	m_Buffer.write(offsets);
	m_Buffer.write(strides);
}

void CommandBuffer::ClipControl(multigl::ClipControlOrigin origin, multigl::ClipControlDepth depth)
{
	m_Buffer.write_command(CommandId::ClipControl);
	m_Buffer.write(origin);
	m_Buffer.write(depth);
}

void CommandBuffer::CreateTransformFeedbacks(GLsizei n, GLuint * ids)
{
	m_Buffer.write_command(CommandId::CreateTransformFeedbacks);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::TransformFeedbackBufferBase(GLuint xfb, GLuint index, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::TransformFeedbackBufferBase);
	m_Buffer.write(xfb);
	m_Buffer.write(index);
	m_Buffer.write(buffer);
}

void CommandBuffer::TransformFeedbackBufferRange(GLuint xfb, GLuint index, BufferHandle buffer, GLintptr offset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::TransformFeedbackBufferRange);
	m_Buffer.write(xfb);
	m_Buffer.write(index);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
}

void CommandBuffer::GetTransformFeedbackiv(GLuint xfb, multigl::TransformFeedbackPName pname, GLint * param)
{
	m_Buffer.write_command(CommandId::GetTransformFeedbackiv);
	m_Buffer.write(xfb);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetTransformFeedbacki_v(GLuint xfb, multigl::TransformFeedbackPName pname, GLuint index, GLint * param)
{
	m_Buffer.write_command(CommandId::GetTransformFeedbacki_v);
	m_Buffer.write(xfb);
	m_Buffer.write(pname);
	m_Buffer.write(index);
	m_Buffer.write(param);
}

void CommandBuffer::GetTransformFeedbacki64_v(GLuint xfb, multigl::TransformFeedbackPName pname, GLuint index, GLint64 * param)
{
	m_Buffer.write_command(CommandId::GetTransformFeedbacki64_v);
	m_Buffer.write(xfb);
	m_Buffer.write(pname);
	m_Buffer.write(index);
	m_Buffer.write(param);
}

BufferHandle CommandBuffer::CreateBuffer()
{
	m_Buffer.write_command(CommandId::CreateBuffer);

	auto handle = m_ResourceManager.Buffers.create(0);
	m_Buffer.write<BufferHandle>(handle);
	return handle;
}

void CommandBuffer::NamedBufferStorage(BufferHandle buffer, GLsizeiptr size, const void * data, GLbitfield flags)
{
	m_Buffer.write_command(CommandId::NamedBufferStorage);
	m_Buffer.write(buffer);
	m_Buffer.write(size);
	m_Buffer.write(data);
	m_Buffer.write(flags);
}

void CommandBuffer::NamedBufferData(BufferHandle buffer, GLsizeiptr size, const void * data, multigl::VertexBufferObjectUsage usage)
{
	m_Buffer.write_command(CommandId::NamedBufferData);
	m_Buffer.write(buffer);
	m_Buffer.write(size);
	m_Buffer.write(data);
	m_Buffer.write(usage);
}

void CommandBuffer::NamedBufferSubData(BufferHandle buffer, GLintptr offset, GLsizeiptr size, const void * data)
{
	m_Buffer.write_command(CommandId::NamedBufferSubData);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(data);
}

void CommandBuffer::CopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::CopyNamedBufferSubData);
	m_Buffer.write(readBuffer);
	m_Buffer.write(writeBuffer);
	m_Buffer.write(readOffset);
	m_Buffer.write(writeOffset);
	m_Buffer.write(size);
}

void CommandBuffer::ClearNamedBufferData(BufferHandle buffer, multigl::InternalFormat internalformat, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearNamedBufferData);
	m_Buffer.write(buffer);
	m_Buffer.write(internalformat);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::ClearNamedBufferSubData(BufferHandle buffer, multigl::InternalFormat internalformat, GLintptr offset, GLsizeiptr size, multigl::PixelFormat format, multigl::PixelType type, const void * data)
{
	m_Buffer.write_command(CommandId::ClearNamedBufferSubData);
	m_Buffer.write(buffer);
	m_Buffer.write(internalformat);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(data);
}

void CommandBuffer::FlushMappedNamedBufferRange(BufferHandle buffer, GLintptr offset, GLsizeiptr length)
{
	m_Buffer.write_command(CommandId::FlushMappedNamedBufferRange);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(length);
}

void CommandBuffer::GetNamedBufferParameteriv(BufferHandle buffer, multigl::VertexBufferObjectParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetNamedBufferParameteriv);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetNamedBufferParameteri64v(BufferHandle buffer, multigl::VertexBufferObjectParameter pname, GLint64 * params)
{
	m_Buffer.write_command(CommandId::GetNamedBufferParameteri64v);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetNamedBufferPointerv(BufferHandle buffer, multigl::VertexBufferObjectParameter pname, void ** params)
{
	m_Buffer.write_command(CommandId::GetNamedBufferPointerv);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetNamedBufferSubData(BufferHandle buffer, GLintptr offset, GLsizeiptr size, void * data)
{
	m_Buffer.write_command(CommandId::GetNamedBufferSubData);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
	m_Buffer.write(data);
}

FramebufferHandle CommandBuffer::CreateFramebuffer()
{
	m_Buffer.write_command(CommandId::CreateFramebuffer);

	auto handle = m_ResourceManager.Framebuffers.create(0);
	m_Buffer.write<FramebufferHandle>(handle);
	return handle;
}

void CommandBuffer::NamedFramebufferRenderbuffer(FramebufferHandle framebuffer, multigl::FramebufferAttachment attachment, multigl::RenderbufferTarget renderbuffertarget, RenderbufferHandle renderbuffer)
{
	m_Buffer.write_command(CommandId::NamedFramebufferRenderbuffer);
	m_Buffer.write(framebuffer);
	m_Buffer.write(attachment);
	m_Buffer.write(renderbuffertarget);
	m_Buffer.write(renderbuffer);
}

void CommandBuffer::NamedFramebufferParameteri(FramebufferHandle framebuffer, multigl::FramebufferParameterName pname, GLint param)
{
	m_Buffer.write_command(CommandId::NamedFramebufferParameteri);
	m_Buffer.write(framebuffer);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::NamedFramebufferTexture(FramebufferHandle framebuffer, multigl::FramebufferAttachment attachment, TextureHandle texture, GLint level)
{
	m_Buffer.write_command(CommandId::NamedFramebufferTexture);
	m_Buffer.write(framebuffer);
	m_Buffer.write(attachment);
	m_Buffer.write(texture);
	m_Buffer.write(level);
}

void CommandBuffer::NamedFramebufferTextureLayer(FramebufferHandle framebuffer, multigl::FramebufferAttachment attachment, TextureHandle texture, GLint level, GLint layer)
{
	m_Buffer.write_command(CommandId::NamedFramebufferTextureLayer);
	m_Buffer.write(framebuffer);
	m_Buffer.write(attachment);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(layer);
}

void CommandBuffer::NamedFramebufferDrawBuffer(FramebufferHandle framebuffer, multigl::ColorBuffer buf)
{
	m_Buffer.write_command(CommandId::NamedFramebufferDrawBuffer);
	m_Buffer.write(framebuffer);
	m_Buffer.write(buf);
}

void CommandBuffer::NamedFramebufferDrawBuffers(FramebufferHandle framebuffer, GLsizei n, const GLenum * bufs)
{
	m_Buffer.write_command(CommandId::NamedFramebufferDrawBuffers);
	m_Buffer.write(framebuffer);
	m_Buffer.write(n);
	m_Buffer.write(bufs);
}

void CommandBuffer::NamedFramebufferReadBuffer(FramebufferHandle framebuffer, multigl::ColorBuffer src)
{
	m_Buffer.write_command(CommandId::NamedFramebufferReadBuffer);
	m_Buffer.write(framebuffer);
	m_Buffer.write(src);
}

void CommandBuffer::InvalidateNamedFramebufferData(FramebufferHandle framebuffer, GLsizei numAttachments, const GLenum * attachments)
{
	m_Buffer.write_command(CommandId::InvalidateNamedFramebufferData);
	m_Buffer.write(framebuffer);
	m_Buffer.write(numAttachments);
	m_Buffer.write(attachments);
}

void CommandBuffer::InvalidateNamedFramebufferSubData(FramebufferHandle framebuffer, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::InvalidateNamedFramebufferSubData);
	m_Buffer.write(framebuffer);
	m_Buffer.write(numAttachments);
	m_Buffer.write(attachments);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::ClearNamedFramebufferiv(FramebufferHandle framebuffer, multigl::BufferHandle buffer, GLint drawbuffer, const GLint * value)
{
	m_Buffer.write_command(CommandId::ClearNamedFramebufferiv);
	m_Buffer.write(framebuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearNamedFramebufferuiv(FramebufferHandle framebuffer, multigl::BufferHandle buffer, GLint drawbuffer, const GLuint * value)
{
	m_Buffer.write_command(CommandId::ClearNamedFramebufferuiv);
	m_Buffer.write(framebuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearNamedFramebufferfv(FramebufferHandle framebuffer, multigl::BufferHandle buffer, GLint drawbuffer, const GLfloat * value)
{
	m_Buffer.write_command(CommandId::ClearNamedFramebufferfv);
	m_Buffer.write(framebuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(value);
}

void CommandBuffer::ClearNamedFramebufferfi(FramebufferHandle framebuffer, multigl::BufferHandle buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
{
	m_Buffer.write_command(CommandId::ClearNamedFramebufferfi);
	m_Buffer.write(framebuffer);
	m_Buffer.write(buffer);
	m_Buffer.write(drawbuffer);
	m_Buffer.write(depth);
	m_Buffer.write(stencil);
}

void CommandBuffer::BlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, multigl::BlitFramebufferFilter filter)
{
	m_Buffer.write_command(CommandId::BlitNamedFramebuffer);
	m_Buffer.write(readFramebuffer);
	m_Buffer.write(drawFramebuffer);
	m_Buffer.write(srcX0);
	m_Buffer.write(srcY0);
	m_Buffer.write(srcX1);
	m_Buffer.write(srcY1);
	m_Buffer.write(dstX0);
	m_Buffer.write(dstY0);
	m_Buffer.write(dstX1);
	m_Buffer.write(dstY1);
	m_Buffer.write(mask);
	m_Buffer.write(filter);
}

void CommandBuffer::GetNamedFramebufferParameteriv(FramebufferHandle framebuffer, multigl::GetFramebufferParameter pname, GLint * param)
{
	m_Buffer.write_command(CommandId::GetNamedFramebufferParameteriv);
	m_Buffer.write(framebuffer);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetNamedFramebufferAttachmentParameteriv(FramebufferHandle framebuffer, multigl::FramebufferAttachment attachment, multigl::FramebufferAttachmentParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetNamedFramebufferAttachmentParameteriv);
	m_Buffer.write(framebuffer);
	m_Buffer.write(attachment);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

RenderbufferHandle CommandBuffer::CreateRenderbuffer()
{
	m_Buffer.write_command(CommandId::CreateRenderbuffer);

	auto handle = m_ResourceManager.Renderbuffers.create(0);
	m_Buffer.write<RenderbufferHandle>(handle);
	return handle;
}

void CommandBuffer::NamedRenderbufferStorage(RenderbufferHandle renderbuffer, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::NamedRenderbufferStorage);
	m_Buffer.write(renderbuffer);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::NamedRenderbufferStorageMultisample(RenderbufferHandle renderbuffer, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::NamedRenderbufferStorageMultisample);
	m_Buffer.write(renderbuffer);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::GetNamedRenderbufferParameteriv(RenderbufferHandle renderbuffer, multigl::RenderbufferParameterName pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetNamedRenderbufferParameteriv);
	m_Buffer.write(renderbuffer);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

TextureHandle CommandBuffer::CreateTexture(multigl::TextureTarget target)
{
	m_Buffer.write_command(CommandId::CreateTexture);

	m_Buffer.write(target);
	auto handle = m_ResourceManager.Textures.create(0);
	m_Buffer.write(handle);
	return handle;
}

void CommandBuffer::TextureBuffer(TextureHandle texture, multigl::InternalFormat internalformat, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::TextureBuffer);
	m_Buffer.write(texture);
	m_Buffer.write(internalformat);
	m_Buffer.write(buffer);
}

void CommandBuffer::TextureBufferRange(TextureHandle texture, multigl::InternalFormat internalformat, BufferHandle buffer, GLintptr offset, GLsizeiptr size)
{
	m_Buffer.write_command(CommandId::TextureBufferRange);
	m_Buffer.write(texture);
	m_Buffer.write(internalformat);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(size);
}

void CommandBuffer::TextureStorage1D(TextureHandle texture, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width)
{
	m_Buffer.write_command(CommandId::TextureStorage1D);
	m_Buffer.write(texture);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
}

void CommandBuffer::TextureStorage2D(TextureHandle texture, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::TextureStorage2D);
	m_Buffer.write(texture);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::TextureStorage3D(TextureHandle texture, GLsizei levels, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth)
{
	m_Buffer.write_command(CommandId::TextureStorage3D);
	m_Buffer.write(texture);
	m_Buffer.write(levels);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
}

void CommandBuffer::TextureStorage2DMultisample(TextureHandle texture, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TextureStorage2DMultisample);
	m_Buffer.write(texture);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::TextureStorage3DMultisample(TextureHandle texture, GLsizei samples, multigl::InternalFormat internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations)
{
	m_Buffer.write_command(CommandId::TextureStorage3DMultisample);
	m_Buffer.write(texture);
	m_Buffer.write(samples);
	m_Buffer.write(internalformat);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(fixedsamplelocations);
}

void CommandBuffer::TextureSubImage1D(TextureHandle texture, GLint level, GLint xoffset, GLsizei width, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TextureSubImage1D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(width);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::TextureSubImage2D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TextureSubImage2D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::TextureSubImage3D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, multigl::PixelType type, const void * pixels)
{
	m_Buffer.write_command(CommandId::TextureSubImage3D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(pixels);
}

void CommandBuffer::CompressedTextureSubImage1D(TextureHandle texture, GLint level, GLint xoffset, GLsizei width, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTextureSubImage1D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(width);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTextureSubImage2D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTextureSubImage2D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CompressedTextureSubImage3D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, GLsizei imageSize, const void * data)
{
	m_Buffer.write_command(CommandId::CompressedTextureSubImage3D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(imageSize);
	m_Buffer.write(data);
}

void CommandBuffer::CopyTextureSubImage1D(TextureHandle texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
	m_Buffer.write_command(CommandId::CopyTextureSubImage1D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
}

void CommandBuffer::CopyTextureSubImage2D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::CopyTextureSubImage2D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::CopyTextureSubImage3D(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
	m_Buffer.write_command(CommandId::CopyTextureSubImage3D);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
}

void CommandBuffer::TextureParameterf(TextureHandle texture, multigl::TextureParameterName pname, GLfloat param)
{
	m_Buffer.write_command(CommandId::TextureParameterf);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::TextureParameterfv(TextureHandle texture, multigl::TextureParameterName pname, const GLfloat * param)
{
	m_Buffer.write_command(CommandId::TextureParameterfv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::TextureParameteri(TextureHandle texture, multigl::TextureParameterName pname, GLint param)
{
	m_Buffer.write_command(CommandId::TextureParameteri);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::TextureParameterIiv(TextureHandle texture, multigl::TextureParameterName pname, const GLint * params)
{
	m_Buffer.write_command(CommandId::TextureParameterIiv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::TextureParameterIuiv(TextureHandle texture, multigl::TextureParameterName pname, const GLuint * params)
{
	m_Buffer.write_command(CommandId::TextureParameterIuiv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::TextureParameteriv(TextureHandle texture, multigl::TextureParameterName pname, const GLint * param)
{
	m_Buffer.write_command(CommandId::TextureParameteriv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GenerateTextureMipmap(TextureHandle texture)
{
	m_Buffer.write_command(CommandId::GenerateTextureMipmap);
	m_Buffer.write(texture);
}

void CommandBuffer::BindTextureUnit(GLuint unit, TextureHandle texture)
{
	m_Buffer.write_command(CommandId::BindTextureUnit);
	m_Buffer.write(unit);
	m_Buffer.write(texture);
}

void CommandBuffer::GetTextureImage(TextureHandle texture, GLint level, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetTextureImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetCompressedTextureImage(TextureHandle texture, GLint level, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetCompressedTextureImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetTextureLevelParameterfv(TextureHandle texture, GLint level, multigl::GetTextureParameter pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetTextureLevelParameterfv);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTextureLevelParameteriv(TextureHandle texture, GLint level, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTextureLevelParameteriv);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTextureParameterfv(TextureHandle texture, multigl::GetTextureParameter pname, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetTextureParameterfv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTextureParameterIiv(TextureHandle texture, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTextureParameterIiv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTextureParameterIuiv(TextureHandle texture, multigl::GetTextureParameter pname, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetTextureParameterIuiv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

void CommandBuffer::GetTextureParameteriv(TextureHandle texture, multigl::GetTextureParameter pname, GLint * params)
{
	m_Buffer.write_command(CommandId::GetTextureParameteriv);
	m_Buffer.write(texture);
	m_Buffer.write(pname);
	m_Buffer.write(params);
}

VertexArrayHandle CommandBuffer::CreateVertexArray()
{
	m_Buffer.write_command(CommandId::CreateVertexArray);

	auto handle = m_ResourceManager.VertexArrays.create(0);
	m_Buffer.write<VertexArrayHandle>(handle);
	return handle;
}

void CommandBuffer::DisableVertexArrayAttrib(VertexArrayHandle vaobj, GLuint index)
{
	m_Buffer.write_command(CommandId::DisableVertexArrayAttrib);
	m_Buffer.write(vaobj);
	m_Buffer.write(index);
}

void CommandBuffer::EnableVertexArrayAttrib(VertexArrayHandle vaobj, GLuint index)
{
	m_Buffer.write_command(CommandId::EnableVertexArrayAttrib);
	m_Buffer.write(vaobj);
	m_Buffer.write(index);
}

void CommandBuffer::VertexArrayElementBuffer(VertexArrayHandle vaobj, BufferHandle buffer)
{
	m_Buffer.write_command(CommandId::VertexArrayElementBuffer);
	m_Buffer.write(vaobj);
	m_Buffer.write(buffer);
}

void CommandBuffer::VertexArrayVertexBuffer(VertexArrayHandle vaobj, GLuint bindingindex, BufferHandle buffer, GLintptr offset, GLsizei stride)
{
	m_Buffer.write_command(CommandId::VertexArrayVertexBuffer);
	m_Buffer.write(vaobj);
	m_Buffer.write(bindingindex);
	m_Buffer.write(buffer);
	m_Buffer.write(offset);
	m_Buffer.write(stride);
}

void CommandBuffer::VertexArrayVertexBuffers(VertexArrayHandle vaobj, GLuint first, GLsizei count, const GLuint * buffers, const GLintptr * offsets, const GLsizei * strides)
{
	m_Buffer.write_command(CommandId::VertexArrayVertexBuffers);
	m_Buffer.write(vaobj);
	m_Buffer.write(first);
	m_Buffer.write(count);
	m_Buffer.write(buffers);
	m_Buffer.write(offsets);
	m_Buffer.write(strides);
}

void CommandBuffer::VertexArrayAttribBinding(VertexArrayHandle vaobj, GLuint attribindex, GLuint bindingindex)
{
	m_Buffer.write_command(CommandId::VertexArrayAttribBinding);
	m_Buffer.write(vaobj);
	m_Buffer.write(attribindex);
	m_Buffer.write(bindingindex);
}

void CommandBuffer::VertexArrayAttribFormat(VertexArrayHandle vaobj, GLuint attribindex, GLint size, multigl::VertexAttribType type, GLboolean normalized, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexArrayAttribFormat);
	m_Buffer.write(vaobj);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(normalized);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexArrayAttribIFormat(VertexArrayHandle vaobj, GLuint attribindex, GLint size, multigl::VertexAttribIType type, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexArrayAttribIFormat);
	m_Buffer.write(vaobj);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexArrayAttribLFormat(VertexArrayHandle vaobj, GLuint attribindex, GLint size, multigl::VertexAttribLType type, GLuint relativeoffset)
{
	m_Buffer.write_command(CommandId::VertexArrayAttribLFormat);
	m_Buffer.write(vaobj);
	m_Buffer.write(attribindex);
	m_Buffer.write(size);
	m_Buffer.write(type);
	m_Buffer.write(relativeoffset);
}

void CommandBuffer::VertexArrayBindingDivisor(VertexArrayHandle vaobj, GLuint bindingindex, GLuint divisor)
{
	m_Buffer.write_command(CommandId::VertexArrayBindingDivisor);
	m_Buffer.write(vaobj);
	m_Buffer.write(bindingindex);
	m_Buffer.write(divisor);
}

void CommandBuffer::GetVertexArrayiv(VertexArrayHandle vaobj, multigl::VertexArrayPName pname, GLint * param)
{
	m_Buffer.write_command(CommandId::GetVertexArrayiv);
	m_Buffer.write(vaobj);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetVertexArrayIndexediv(VertexArrayHandle vaobj, GLuint index, multigl::VertexArrayPName pname, GLint * param)
{
	m_Buffer.write_command(CommandId::GetVertexArrayIndexediv);
	m_Buffer.write(vaobj);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::GetVertexArrayIndexed64iv(VertexArrayHandle vaobj, GLuint index, multigl::VertexArrayPName pname, GLint64 * param)
{
	m_Buffer.write_command(CommandId::GetVertexArrayIndexed64iv);
	m_Buffer.write(vaobj);
	m_Buffer.write(index);
	m_Buffer.write(pname);
	m_Buffer.write(param);
}

void CommandBuffer::CreateSamplers(GLsizei n, GLuint * samplers)
{
	m_Buffer.write_command(CommandId::CreateSamplers);
	m_Buffer.write(n);
	m_Buffer.write(samplers);
}

void CommandBuffer::CreateProgramPipelines(GLsizei n, GLuint * pipelines)
{
	m_Buffer.write_command(CommandId::CreateProgramPipelines);
	m_Buffer.write(n);
	m_Buffer.write(pipelines);
}

void CommandBuffer::CreateQueries(multigl::QueryTarget target, GLsizei n, GLuint * ids)
{
	m_Buffer.write_command(CommandId::CreateQueries);
	m_Buffer.write(target);
	m_Buffer.write(n);
	m_Buffer.write(ids);
}

void CommandBuffer::GetQueryBufferObjecti64v(GLuint id, BufferHandle buffer, multigl::QueryObjectParameterName pname, GLintptr offset)
{
	m_Buffer.write_command(CommandId::GetQueryBufferObjecti64v);
	m_Buffer.write(id);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(offset);
}

void CommandBuffer::GetQueryBufferObjectiv(GLuint id, BufferHandle buffer, multigl::QueryObjectParameterName pname, GLintptr offset)
{
	m_Buffer.write_command(CommandId::GetQueryBufferObjectiv);
	m_Buffer.write(id);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(offset);
}

void CommandBuffer::GetQueryBufferObjectui64v(GLuint id, BufferHandle buffer, multigl::QueryObjectParameterName pname, GLintptr offset)
{
	m_Buffer.write_command(CommandId::GetQueryBufferObjectui64v);
	m_Buffer.write(id);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(offset);
}

void CommandBuffer::GetQueryBufferObjectuiv(GLuint id, BufferHandle buffer, multigl::QueryObjectParameterName pname, GLintptr offset)
{
	m_Buffer.write_command(CommandId::GetQueryBufferObjectuiv);
	m_Buffer.write(id);
	m_Buffer.write(buffer);
	m_Buffer.write(pname);
	m_Buffer.write(offset);
}

void CommandBuffer::MemoryBarrierByRegion(GLbitfield barriers)
{
	m_Buffer.write_command(CommandId::MemoryBarrierByRegion);
	m_Buffer.write(barriers);
}

void CommandBuffer::GetTextureSubImage(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetTextureSubImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetCompressedTextureSubImage(TextureHandle texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetCompressedTextureSubImage);
	m_Buffer.write(texture);
	m_Buffer.write(level);
	m_Buffer.write(xoffset);
	m_Buffer.write(yoffset);
	m_Buffer.write(zoffset);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(depth);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetnCompressedTexImage(multigl::TextureTarget target, GLint lod, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetnCompressedTexImage);
	m_Buffer.write(target);
	m_Buffer.write(lod);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetnTexImage(multigl::TextureTarget target, GLint level, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * pixels)
{
	m_Buffer.write_command(CommandId::GetnTexImage);
	m_Buffer.write(target);
	m_Buffer.write(level);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(pixels);
}

void CommandBuffer::GetnUniformdv(ShaderProgramHandle program, GLint location, GLsizei bufSize, GLdouble * params)
{
	m_Buffer.write_command(CommandId::GetnUniformdv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(bufSize);
	m_Buffer.write(params);
}

void CommandBuffer::GetnUniformfv(ShaderProgramHandle program, GLint location, GLsizei bufSize, GLfloat * params)
{
	m_Buffer.write_command(CommandId::GetnUniformfv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(bufSize);
	m_Buffer.write(params);
}

void CommandBuffer::GetnUniformiv(ShaderProgramHandle program, GLint location, GLsizei bufSize, GLint * params)
{
	m_Buffer.write_command(CommandId::GetnUniformiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(bufSize);
	m_Buffer.write(params);
}

void CommandBuffer::GetnUniformuiv(ShaderProgramHandle program, GLint location, GLsizei bufSize, GLuint * params)
{
	m_Buffer.write_command(CommandId::GetnUniformuiv);
	m_Buffer.write(program);
	m_Buffer.write(location);
	m_Buffer.write(bufSize);
	m_Buffer.write(params);
}

void CommandBuffer::ReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * data)
{
	m_Buffer.write_command(CommandId::ReadnPixels);
	m_Buffer.write(x);
	m_Buffer.write(y);
	m_Buffer.write(width);
	m_Buffer.write(height);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(data);
}

void CommandBuffer::GetnMapdv(multigl::MapTarget target, multigl::MapQuery query, GLsizei bufSize, GLdouble * v)
{
	m_Buffer.write_command(CommandId::GetnMapdv);
	m_Buffer.write(target);
	m_Buffer.write(query);
	m_Buffer.write(bufSize);
	m_Buffer.write(v);
}

void CommandBuffer::GetnMapfv(multigl::MapTarget target, multigl::MapQuery query, GLsizei bufSize, GLfloat * v)
{
	m_Buffer.write_command(CommandId::GetnMapfv);
	m_Buffer.write(target);
	m_Buffer.write(query);
	m_Buffer.write(bufSize);
	m_Buffer.write(v);
}

void CommandBuffer::GetnMapiv(multigl::MapTarget target, multigl::MapQuery query, GLsizei bufSize, GLint * v)
{
	m_Buffer.write_command(CommandId::GetnMapiv);
	m_Buffer.write(target);
	m_Buffer.write(query);
	m_Buffer.write(bufSize);
	m_Buffer.write(v);
}

void CommandBuffer::GetnPixelMapfv(multigl::PixelMap map, GLsizei bufSize, GLfloat * values)
{
	m_Buffer.write_command(CommandId::GetnPixelMapfv);
	m_Buffer.write(map);
	m_Buffer.write(bufSize);
	m_Buffer.write(values);
}

void CommandBuffer::GetnPixelMapuiv(multigl::PixelMap map, GLsizei bufSize, GLuint * values)
{
	m_Buffer.write_command(CommandId::GetnPixelMapuiv);
	m_Buffer.write(map);
	m_Buffer.write(bufSize);
	m_Buffer.write(values);
}

void CommandBuffer::GetnPixelMapusv(multigl::PixelMap map, GLsizei bufSize, GLushort * values)
{
	m_Buffer.write_command(CommandId::GetnPixelMapusv);
	m_Buffer.write(map);
	m_Buffer.write(bufSize);
	m_Buffer.write(values);
}

void CommandBuffer::GetnPolygonStipple(GLsizei bufSize, GLubyte * pattern)
{
	m_Buffer.write_command(CommandId::GetnPolygonStipple);
	m_Buffer.write(bufSize);
	m_Buffer.write(pattern);
}

void CommandBuffer::GetnColorTable(multigl::ColorTableTarget target, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * table)
{
	m_Buffer.write_command(CommandId::GetnColorTable);
	m_Buffer.write(target);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(table);
}

void CommandBuffer::GetnConvolutionFilter(multigl::ConvolutionTarget target, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * image)
{
	m_Buffer.write_command(CommandId::GetnConvolutionFilter);
	m_Buffer.write(target);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(image);
}

void CommandBuffer::GetnSeparableFilter(multigl::SeparableTargetEXT target, multigl::PixelFormat format, multigl::PixelType type, GLsizei rowBufSize, void * row, GLsizei columnBufSize, void * column, void * span)
{
	m_Buffer.write_command(CommandId::GetnSeparableFilter);
	m_Buffer.write(target);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(rowBufSize);
	m_Buffer.write(row);
	m_Buffer.write(columnBufSize);
	m_Buffer.write(column);
	m_Buffer.write(span);
}

void CommandBuffer::GetnHistogram(multigl::HistogramTargetEXT target, GLboolean reset, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * values)
{
	m_Buffer.write_command(CommandId::GetnHistogram);
	m_Buffer.write(target);
	m_Buffer.write(reset);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(values);
}

void CommandBuffer::GetnMinmax(multigl::MinmaxTargetEXT target, GLboolean reset, multigl::PixelFormat format, multigl::PixelType type, GLsizei bufSize, void * values)
{
	m_Buffer.write_command(CommandId::GetnMinmax);
	m_Buffer.write(target);
	m_Buffer.write(reset);
	m_Buffer.write(format);
	m_Buffer.write(type);
	m_Buffer.write(bufSize);
	m_Buffer.write(values);
}

void CommandBuffer::TextureBarrier()
{
	m_Buffer.write_command(CommandId::TextureBarrier);
}

