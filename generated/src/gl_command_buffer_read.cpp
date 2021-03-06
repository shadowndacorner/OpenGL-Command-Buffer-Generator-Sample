#include <gl_command_buffer.hpp>
#include <gl_utilities.hpp>

using namespace multigl;
void CommandBuffer::ProcessCommands()
{
	while(m_Buffer.has_commands())
	{
		auto cmd = m_Buffer.read_command();
		switch(cmd)
		{
			case CommandId::CullFace:
			{
				multigl::CullFaceMode mode = m_Buffer.read<multigl::CullFaceMode>();
				GL_CHECK(glCullFace(mode));
				break;
			}
			case CommandId::FrontFace:
			{
				multigl::FrontFaceDirection mode = m_Buffer.read<multigl::FrontFaceDirection>();
				GL_CHECK(glFrontFace(mode));
				break;
			}
			case CommandId::Hint:
			{
				multigl::HintTarget target = m_Buffer.read<multigl::HintTarget>();
				multigl::HintMode mode = m_Buffer.read<multigl::HintMode>();
				GL_CHECK(glHint(target, mode));
				break;
			}
			case CommandId::LineWidth:
			{
				GLfloat width = m_Buffer.read<GLfloat>();
				GL_CHECK(glLineWidth(width));
				break;
			}
			case CommandId::PointSize:
			{
				GLfloat size = m_Buffer.read<GLfloat>();
				GL_CHECK(glPointSize(size));
				break;
			}
			case CommandId::PolygonMode:
			{
				multigl::MaterialFace face = m_Buffer.read<multigl::MaterialFace>();
				multigl::PolygonMode mode = m_Buffer.read<multigl::PolygonMode>();
				GL_CHECK(glPolygonMode(face, mode));
				break;
			}
			case CommandId::Scissor:
			{
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glScissor(x, y, width, height));
				break;
			}
			case CommandId::TexParameterf:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				GLfloat param = m_Buffer.read<GLfloat>();
				GL_CHECK(glTexParameterf(target, pname, param));
				break;
			}
			case CommandId::TexParameterfv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLfloat * params = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glTexParameterfv(target, pname, params));
				break;
			}
			case CommandId::TexParameteri:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glTexParameteri(target, pname, param));
				break;
			}
			case CommandId::TexParameteriv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLint * params = m_Buffer.read<const GLint *>();
				GL_CHECK(glTexParameteriv(target, pname, params));
				break;
			}
			case CommandId::TexImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint internalformat = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
				break;
			}
			case CommandId::TexImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint internalformat = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
				break;
			}
			case CommandId::DrawBuffer:
			{
				multigl::DrawBufferMode buf = m_Buffer.read<multigl::DrawBufferMode>();
				GL_CHECK(glDrawBuffer(buf));
				break;
			}
			case CommandId::Clear:
			{
				GLbitfield mask = m_Buffer.read<GLbitfield>();
				GL_CHECK(glClear(mask));
				break;
			}
			case CommandId::ClearColor:
			{
				GLfloat red = m_Buffer.read<GLfloat>();
				GLfloat green = m_Buffer.read<GLfloat>();
				GLfloat blue = m_Buffer.read<GLfloat>();
				GLfloat alpha = m_Buffer.read<GLfloat>();
				GL_CHECK(glClearColor(red, green, blue, alpha));
				break;
			}
			case CommandId::ClearStencil:
			{
				GLint s = m_Buffer.read<GLint>();
				GL_CHECK(glClearStencil(s));
				break;
			}
			case CommandId::ClearDepth:
			{
				GLdouble depth = m_Buffer.read<GLdouble>();
				GL_CHECK(glClearDepth(depth));
				break;
			}
			case CommandId::StencilMask:
			{
				GLuint mask = m_Buffer.read<GLuint>();
				GL_CHECK(glStencilMask(mask));
				break;
			}
			case CommandId::ColorMask:
			{
				GLboolean red = m_Buffer.read<GLboolean>();
				GLboolean green = m_Buffer.read<GLboolean>();
				GLboolean blue = m_Buffer.read<GLboolean>();
				GLboolean alpha = m_Buffer.read<GLboolean>();
				GL_CHECK(glColorMask(red, green, blue, alpha));
				break;
			}
			case CommandId::DepthMask:
			{
				GLboolean flag = m_Buffer.read<GLboolean>();
				GL_CHECK(glDepthMask(flag));
				break;
			}
			case CommandId::Disable:
			{
				multigl::EnableCap cap = m_Buffer.read<multigl::EnableCap>();
				GL_CHECK(glDisable(cap));
				break;
			}
			case CommandId::Enable:
			{
				multigl::EnableCap cap = m_Buffer.read<multigl::EnableCap>();
				GL_CHECK(glEnable(cap));
				break;
			}
			case CommandId::Finish:
			{
				GL_CHECK(glFinish());
				break;
			}
			case CommandId::Flush:
			{
				GL_CHECK(glFlush());
				break;
			}
			case CommandId::BlendFunc:
			{
				multigl::BlendingFactor sfactor = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dfactor = m_Buffer.read<multigl::BlendingFactor>();
				GL_CHECK(glBlendFunc(sfactor, dfactor));
				break;
			}
			case CommandId::LogicOp:
			{
				multigl::LogicOp opcode = m_Buffer.read<multigl::LogicOp>();
				GL_CHECK(glLogicOp(opcode));
				break;
			}
			case CommandId::StencilFunc:
			{
				multigl::StencilFunction func = m_Buffer.read<multigl::StencilFunction>();
				GLint ref = m_Buffer.read<GLint>();
				GLuint mask = m_Buffer.read<GLuint>();
				GL_CHECK(glStencilFunc(func, ref, mask));
				break;
			}
			case CommandId::StencilOp:
			{
				multigl::StencilOp fail = m_Buffer.read<multigl::StencilOp>();
				multigl::StencilOp zfail = m_Buffer.read<multigl::StencilOp>();
				multigl::StencilOp zpass = m_Buffer.read<multigl::StencilOp>();
				GL_CHECK(glStencilOp(fail, zfail, zpass));
				break;
			}
			case CommandId::DepthFunc:
			{
				multigl::DepthFunction func = m_Buffer.read<multigl::DepthFunction>();
				GL_CHECK(glDepthFunc(func));
				break;
			}
			case CommandId::PixelStoref:
			{
				multigl::PixelStoreParameter pname = m_Buffer.read<multigl::PixelStoreParameter>();
				GLfloat param = m_Buffer.read<GLfloat>();
				GL_CHECK(glPixelStoref(pname, param));
				break;
			}
			case CommandId::PixelStorei:
			{
				multigl::PixelStoreParameter pname = m_Buffer.read<multigl::PixelStoreParameter>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glPixelStorei(pname, param));
				break;
			}
			case CommandId::ReadBuffer:
			{
				multigl::ReadBufferMode src = m_Buffer.read<multigl::ReadBufferMode>();
				GL_CHECK(glReadBuffer(src));
				break;
			}
			case CommandId::ReadPixels:
			{
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glReadPixels(x, y, width, height, format, type, pixels));
				break;
			}
			case CommandId::GetBooleanv:
			{
				multigl::GetPName pname = m_Buffer.read<multigl::GetPName>();
				GLboolean * data = m_Buffer.read<GLboolean *>();
				GL_CHECK(glGetBooleanv(pname, data));
				break;
			}
			case CommandId::GetDoublev:
			{
				multigl::GetPName pname = m_Buffer.read<multigl::GetPName>();
				GLdouble * data = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetDoublev(pname, data));
				break;
			}
			case CommandId::GetFloatv:
			{
				multigl::GetPName pname = m_Buffer.read<multigl::GetPName>();
				GLfloat * data = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetFloatv(pname, data));
				break;
			}
			case CommandId::GetIntegerv:
			{
				multigl::GetPName pname = m_Buffer.read<multigl::GetPName>();
				GLint * data = m_Buffer.read<GLint *>();
				GL_CHECK(glGetIntegerv(pname, data));
				break;
			}
			case CommandId::GetTexImage:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetTexImage(target, level, format, type, pixels));
				break;
			}
			case CommandId::GetTexParameterfv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetTexParameterfv(target, pname, params));
				break;
			}
			case CommandId::GetTexParameteriv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTexParameteriv(target, pname, params));
				break;
			}
			case CommandId::GetTexLevelParameterfv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetTexLevelParameterfv(target, level, pname, params));
				break;
			}
			case CommandId::GetTexLevelParameteriv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTexLevelParameteriv(target, level, pname, params));
				break;
			}
			case CommandId::DepthRange:
			{
				GLdouble n = m_Buffer.read<GLdouble>();
				GLdouble f = m_Buffer.read<GLdouble>();
				GL_CHECK(glDepthRange(n, f));
				break;
			}
			case CommandId::Viewport:
			{
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glViewport(x, y, width, height));
				break;
			}
			case CommandId::DrawArrays:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLint first = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GL_CHECK(glDrawArrays(mode, first, count));
				break;
			}
			case CommandId::DrawElements:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GL_CHECK(glDrawElements(mode, count, type, indices));
				break;
			}
			case CommandId::PolygonOffset:
			{
				GLfloat factor = m_Buffer.read<GLfloat>();
				GLfloat units = m_Buffer.read<GLfloat>();
				GL_CHECK(glPolygonOffset(factor, units));
				break;
			}
			case CommandId::CopyTexImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				GL_CHECK(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
				break;
			}
			case CommandId::CopyTexImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				GL_CHECK(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
				break;
			}
			case CommandId::CopyTexSubImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
				break;
			}
			case CommandId::CopyTexSubImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
				break;
			}
			case CommandId::TexSubImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
				break;
			}
			case CommandId::TexSubImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
				break;
			}
			case CommandId::BindTexture:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GL_CHECK(glBindTexture(target, texture));
				break;
			}
			case CommandId::DeleteTextures:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * textures = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteTextures(n, textures));
				break;
			}
			case CommandId::GenTexture:
			{
				auto handle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(handle);
				glGenTextures(1, &texture);
				break;
			}
			case CommandId::DrawRangeElements:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint start = m_Buffer.read<GLuint>();
				GLuint end = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GL_CHECK(glDrawRangeElements(mode, start, end, count, type, indices));
				break;
			}
			case CommandId::TexImage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint internalformat = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
				break;
			}
			case CommandId::TexSubImage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
				break;
			}
			case CommandId::CopyTexSubImage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
				break;
			}
			case CommandId::ActiveTexture:
			{
				GLuint textureSlot = m_Buffer.read<GLuint>();
				GL_CHECK(glActiveTexture(GL_TEXTURE0 + textureSlot));
				break;
			}
			case CommandId::SampleCoverage:
			{
				GLfloat value = m_Buffer.read<GLfloat>();
				GLboolean invert = m_Buffer.read<GLboolean>();
				GL_CHECK(glSampleCoverage(value, invert));
				break;
			}
			case CommandId::CompressedTexImage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
				break;
			}
			case CommandId::CompressedTexImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
				break;
			}
			case CommandId::CompressedTexImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLint border = m_Buffer.read<GLint>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
				break;
			}
			case CommandId::CompressedTexSubImage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
				break;
			}
			case CommandId::CompressedTexSubImage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
				break;
			}
			case CommandId::CompressedTexSubImage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
				break;
			}
			case CommandId::GetCompressedTexImage:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				void * img = m_Buffer.read<void *>();
				GL_CHECK(glGetCompressedTexImage(target, level, img));
				break;
			}
			case CommandId::BlendFuncSeparate:
			{
				multigl::BlendingFactor sfactorRGB = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dfactorRGB = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor sfactorAlpha = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dfactorAlpha = m_Buffer.read<multigl::BlendingFactor>();
				GL_CHECK(glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha));
				break;
			}
			case CommandId::MultiDrawArrays:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				const GLint * first = m_Buffer.read<const GLint *>();
				const GLsizei * count = m_Buffer.read<const GLsizei *>();
				GLsizei drawcount = m_Buffer.read<GLsizei>();
				GL_CHECK(glMultiDrawArrays(mode, first, count, drawcount));
				break;
			}
			case CommandId::MultiDrawElements:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				const GLsizei * count = m_Buffer.read<const GLsizei *>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void *const* indices = m_Buffer.read<const void *const*>();
				GLsizei drawcount = m_Buffer.read<GLsizei>();
				GL_CHECK(glMultiDrawElements(mode, count, type, indices, drawcount));
				break;
			}
			case CommandId::PointParameterf:
			{
				multigl::PointParameterNameARB pname = m_Buffer.read<multigl::PointParameterNameARB>();
				GLfloat param = m_Buffer.read<GLfloat>();
				GL_CHECK(glPointParameterf(pname, param));
				break;
			}
			case CommandId::PointParameterfv:
			{
				multigl::PointParameterNameARB pname = m_Buffer.read<multigl::PointParameterNameARB>();
				const GLfloat * params = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glPointParameterfv(pname, params));
				break;
			}
			case CommandId::PointParameteri:
			{
				multigl::PointParameterNameARB pname = m_Buffer.read<multigl::PointParameterNameARB>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glPointParameteri(pname, param));
				break;
			}
			case CommandId::PointParameteriv:
			{
				multigl::PointParameterNameARB pname = m_Buffer.read<multigl::PointParameterNameARB>();
				const GLint * params = m_Buffer.read<const GLint *>();
				GL_CHECK(glPointParameteriv(pname, params));
				break;
			}
			case CommandId::BlendColor:
			{
				GLfloat red = m_Buffer.read<GLfloat>();
				GLfloat green = m_Buffer.read<GLfloat>();
				GLfloat blue = m_Buffer.read<GLfloat>();
				GLfloat alpha = m_Buffer.read<GLfloat>();
				GL_CHECK(glBlendColor(red, green, blue, alpha));
				break;
			}
			case CommandId::BlendEquation:
			{
				multigl::BlendEquationModeEXT mode = m_Buffer.read<multigl::BlendEquationModeEXT>();
				GL_CHECK(glBlendEquation(mode));
				break;
			}
			case CommandId::GenQueries:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * ids = m_Buffer.read<GLuint *>();
				GL_CHECK(glGenQueries(n, ids));
				break;
			}
			case CommandId::DeleteQueries:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * ids = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteQueries(n, ids));
				break;
			}
			case CommandId::BeginQuery:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glBeginQuery(target, id));
				break;
			}
			case CommandId::EndQuery:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GL_CHECK(glEndQuery(target));
				break;
			}
			case CommandId::GetQueryiv:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				multigl::QueryParameterName pname = m_Buffer.read<multigl::QueryParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetQueryiv(target, pname, params));
				break;
			}
			case CommandId::GetQueryObjectiv:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetQueryObjectiv(id, pname, params));
				break;
			}
			case CommandId::GetQueryObjectuiv:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetQueryObjectuiv(id, pname, params));
				break;
			}
			case CommandId::BindBuffer:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glBindBuffer(target, buffer));
				break;
			}
			case CommandId::DeleteBuffers:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * buffers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteBuffers(n, buffers));
				break;
			}
			case CommandId::GenBuffer:
			{
				auto handle = m_Buffer.read<BufferHandle>();
				auto& target = *m_ResourceManager.Buffers.get(handle);
				glGenBuffers(1, &target);
				break;
			}
			case CommandId::BufferData:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				multigl::BufferUsageARB usage = m_Buffer.read<multigl::BufferUsageARB>();
				GL_CHECK(glBufferData(target, size, data, usage));
				break;
			}
			case CommandId::BufferSubData:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glBufferSubData(target, offset, size, data));
				break;
			}
			case CommandId::GetBufferSubData:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				void * data = m_Buffer.read<void *>();
				GL_CHECK(glGetBufferSubData(target, offset, size, data));
				break;
			}
			case CommandId::GetBufferParameteriv:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				multigl::BufferPNameARB pname = m_Buffer.read<multigl::BufferPNameARB>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetBufferParameteriv(target, pname, params));
				break;
			}
			case CommandId::GetBufferPointerv:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				multigl::BufferPointerNameARB pname = m_Buffer.read<multigl::BufferPointerNameARB>();
				void ** params = m_Buffer.read<void **>();
				GL_CHECK(glGetBufferPointerv(target, pname, params));
				break;
			}
			case CommandId::BlendEquationSeparate:
			{
				multigl::BlendEquationModeEXT modeRGB = m_Buffer.read<multigl::BlendEquationModeEXT>();
				multigl::BlendEquationModeEXT modeAlpha = m_Buffer.read<multigl::BlendEquationModeEXT>();
				GL_CHECK(glBlendEquationSeparate(modeRGB, modeAlpha));
				break;
			}
			case CommandId::DrawBuffers:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLenum * bufs = m_Buffer.read<const GLenum *>();
				GL_CHECK(glDrawBuffers(n, bufs));
				break;
			}
			case CommandId::StencilOpSeparate:
			{
				multigl::StencilFaceDirection face = m_Buffer.read<multigl::StencilFaceDirection>();
				multigl::StencilOp sfail = m_Buffer.read<multigl::StencilOp>();
				multigl::StencilOp dpfail = m_Buffer.read<multigl::StencilOp>();
				multigl::StencilOp dppass = m_Buffer.read<multigl::StencilOp>();
				GL_CHECK(glStencilOpSeparate(face, sfail, dpfail, dppass));
				break;
			}
			case CommandId::StencilFuncSeparate:
			{
				multigl::StencilFaceDirection face = m_Buffer.read<multigl::StencilFaceDirection>();
				multigl::StencilFunction func = m_Buffer.read<multigl::StencilFunction>();
				GLint ref = m_Buffer.read<GLint>();
				GLuint mask = m_Buffer.read<GLuint>();
				GL_CHECK(glStencilFuncSeparate(face, func, ref, mask));
				break;
			}
			case CommandId::StencilMaskSeparate:
			{
				multigl::StencilFaceDirection face = m_Buffer.read<multigl::StencilFaceDirection>();
				GLuint mask = m_Buffer.read<GLuint>();
				GL_CHECK(glStencilMaskSeparate(face, mask));
				break;
			}
			case CommandId::AttachShader:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GL_CHECK(glAttachShader(program, shader));
				break;
			}
			case CommandId::BindAttribLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint index = m_Buffer.read<GLuint>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glBindAttribLocation(program, index, name));
				break;
			}
			case CommandId::CompileShader:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GL_CHECK(glCompileShader(shader));
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
				ShaderType type = m_Buffer.read<ShaderType>();
				target = glCreateShader(type);
				break;
			}
			case CommandId::DeleteProgram:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glDeleteProgram(program));
				break;
			}
			case CommandId::DeleteShader:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GL_CHECK(glDeleteShader(shader));
				break;
			}
			case CommandId::DetachShader:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GL_CHECK(glDetachShader(program, shader));
				break;
			}
			case CommandId::DisableVertexAttribArray:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glDisableVertexAttribArray(index));
				break;
			}
			case CommandId::EnableVertexAttribArray:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glEnableVertexAttribArray(index));
				break;
			}
			case CommandId::GetActiveAttrib:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLint * size = m_Buffer.read<GLint *>();
				GLenum * type = m_Buffer.read<GLenum *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveAttrib(program, index, bufSize, length, size, type, name));
				break;
			}
			case CommandId::GetActiveUniform:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLint * size = m_Buffer.read<GLint *>();
				GLenum * type = m_Buffer.read<GLenum *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveUniform(program, index, bufSize, length, size, type, name));
				break;
			}
			case CommandId::GetAttachedShaders:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei maxCount = m_Buffer.read<GLsizei>();
				GLsizei * count = m_Buffer.read<GLsizei *>();
				GLuint * shaders = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetAttachedShaders(program, maxCount, count, shaders));
				break;
			}
			case CommandId::GetProgramiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ProgramPropertyARB pname = m_Buffer.read<multigl::ProgramPropertyARB>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetProgramiv(program, pname, params));
				break;
			}
			case CommandId::GetProgramInfoLog:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * infoLog = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetProgramInfoLog(program, bufSize, length, infoLog));
				break;
			}
			case CommandId::GetShaderiv:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				multigl::ShaderParameterName pname = m_Buffer.read<multigl::ShaderParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetShaderiv(shader, pname, params));
				break;
			}
			case CommandId::GetShaderInfoLog:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * infoLog = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetShaderInfoLog(shader, bufSize, length, infoLog));
				break;
			}
			case CommandId::GetShaderSource:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * source = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetShaderSource(shader, bufSize, length, source));
				break;
			}
			case CommandId::GetUniformfv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetUniformfv(program, location, params));
				break;
			}
			case CommandId::GetUniformiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetUniformiv(program, location, params));
				break;
			}
			case CommandId::GetVertexAttribdv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPropertyARB pname = m_Buffer.read<multigl::VertexAttribPropertyARB>();
				GLdouble * params = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetVertexAttribdv(index, pname, params));
				break;
			}
			case CommandId::GetVertexAttribfv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPropertyARB pname = m_Buffer.read<multigl::VertexAttribPropertyARB>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetVertexAttribfv(index, pname, params));
				break;
			}
			case CommandId::GetVertexAttribiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPropertyARB pname = m_Buffer.read<multigl::VertexAttribPropertyARB>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetVertexAttribiv(index, pname, params));
				break;
			}
			case CommandId::GetVertexAttribPointerv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerPropertyARB pname = m_Buffer.read<multigl::VertexAttribPointerPropertyARB>();
				void ** pointer = m_Buffer.read<void **>();
				GL_CHECK(glGetVertexAttribPointerv(index, pname, pointer));
				break;
			}
			case CommandId::LinkProgram:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glLinkProgram(program));
				break;
			}
			case CommandId::ShaderSource:
			{
				ShaderHandle shaderHandle = m_Buffer.read<ShaderHandle>();
				auto& shader = *m_ResourceManager.Shaders.get(shaderHandle);
				const GLchar* string = m_Buffer.read<const GLchar*>();
				GLint length = m_Buffer.read<GLint>();
				glShaderSource(shader, 1, &string, &length);
				break;
			}
			case CommandId::UseProgram:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glUseProgram(program));
				break;
			}
			case CommandId::Uniform1f:
			{
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GL_CHECK(glUniform1f(location, v0));
				break;
			}
			case CommandId::Uniform2f:
			{
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GL_CHECK(glUniform2f(location, v0, v1));
				break;
			}
			case CommandId::Uniform3f:
			{
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GLfloat v2 = m_Buffer.read<GLfloat>();
				GL_CHECK(glUniform3f(location, v0, v1, v2));
				break;
			}
			case CommandId::Uniform4f:
			{
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GLfloat v2 = m_Buffer.read<GLfloat>();
				GLfloat v3 = m_Buffer.read<GLfloat>();
				GL_CHECK(glUniform4f(location, v0, v1, v2, v3));
				break;
			}
			case CommandId::Uniform1i:
			{
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GL_CHECK(glUniform1i(location, v0));
				break;
			}
			case CommandId::Uniform2i:
			{
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GL_CHECK(glUniform2i(location, v0, v1));
				break;
			}
			case CommandId::Uniform3i:
			{
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GLint v2 = m_Buffer.read<GLint>();
				GL_CHECK(glUniform3i(location, v0, v1, v2));
				break;
			}
			case CommandId::Uniform4i:
			{
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GLint v2 = m_Buffer.read<GLint>();
				GLint v3 = m_Buffer.read<GLint>();
				GL_CHECK(glUniform4i(location, v0, v1, v2, v3));
				break;
			}
			case CommandId::Uniform1fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniform1fv(location, count, value));
				break;
			}
			case CommandId::Uniform2fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniform2fv(location, count, value));
				break;
			}
			case CommandId::Uniform3fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniform3fv(location, count, value));
				break;
			}
			case CommandId::Uniform4fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniform4fv(location, count, value));
				break;
			}
			case CommandId::Uniform1iv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glUniform1iv(location, count, value));
				break;
			}
			case CommandId::Uniform2iv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glUniform2iv(location, count, value));
				break;
			}
			case CommandId::Uniform3iv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glUniform3iv(location, count, value));
				break;
			}
			case CommandId::Uniform4iv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glUniform4iv(location, count, value));
				break;
			}
			case CommandId::UniformMatrix2fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix2fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix3fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix4fv(location, count, transpose, value));
				break;
			}
			case CommandId::ValidateProgram:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glValidateProgram(program));
				break;
			}
			case CommandId::VertexAttrib1d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttrib1d(index, x));
				break;
			}
			case CommandId::VertexAttrib1dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttrib1dv(index, v));
				break;
			}
			case CommandId::VertexAttrib1f:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat x = m_Buffer.read<GLfloat>();
				GL_CHECK(glVertexAttrib1f(index, x));
				break;
			}
			case CommandId::VertexAttrib1fv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glVertexAttrib1fv(index, v));
				break;
			}
			case CommandId::VertexAttrib1s:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLshort x = m_Buffer.read<GLshort>();
				GL_CHECK(glVertexAttrib1s(index, x));
				break;
			}
			case CommandId::VertexAttrib1sv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttrib1sv(index, v));
				break;
			}
			case CommandId::VertexAttrib2d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttrib2d(index, x, y));
				break;
			}
			case CommandId::VertexAttrib2dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttrib2dv(index, v));
				break;
			}
			case CommandId::VertexAttrib2f:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat x = m_Buffer.read<GLfloat>();
				GLfloat y = m_Buffer.read<GLfloat>();
				GL_CHECK(glVertexAttrib2f(index, x, y));
				break;
			}
			case CommandId::VertexAttrib2fv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glVertexAttrib2fv(index, v));
				break;
			}
			case CommandId::VertexAttrib2s:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLshort x = m_Buffer.read<GLshort>();
				GLshort y = m_Buffer.read<GLshort>();
				GL_CHECK(glVertexAttrib2s(index, x, y));
				break;
			}
			case CommandId::VertexAttrib2sv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttrib2sv(index, v));
				break;
			}
			case CommandId::VertexAttrib3d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttrib3d(index, x, y, z));
				break;
			}
			case CommandId::VertexAttrib3dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttrib3dv(index, v));
				break;
			}
			case CommandId::VertexAttrib3f:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat x = m_Buffer.read<GLfloat>();
				GLfloat y = m_Buffer.read<GLfloat>();
				GLfloat z = m_Buffer.read<GLfloat>();
				GL_CHECK(glVertexAttrib3f(index, x, y, z));
				break;
			}
			case CommandId::VertexAttrib3fv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glVertexAttrib3fv(index, v));
				break;
			}
			case CommandId::VertexAttrib3s:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLshort x = m_Buffer.read<GLshort>();
				GLshort y = m_Buffer.read<GLshort>();
				GLshort z = m_Buffer.read<GLshort>();
				GL_CHECK(glVertexAttrib3s(index, x, y, z));
				break;
			}
			case CommandId::VertexAttrib3sv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttrib3sv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Nbv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLbyte * v = m_Buffer.read<const GLbyte *>();
				GL_CHECK(glVertexAttrib4Nbv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Niv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttrib4Niv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Nsv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttrib4Nsv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Nub:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLubyte x = m_Buffer.read<GLubyte>();
				GLubyte y = m_Buffer.read<GLubyte>();
				GLubyte z = m_Buffer.read<GLubyte>();
				GLubyte w = m_Buffer.read<GLubyte>();
				GL_CHECK(glVertexAttrib4Nub(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttrib4Nubv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLubyte * v = m_Buffer.read<const GLubyte *>();
				GL_CHECK(glVertexAttrib4Nubv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Nuiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttrib4Nuiv(index, v));
				break;
			}
			case CommandId::VertexAttrib4Nusv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLushort * v = m_Buffer.read<const GLushort *>();
				GL_CHECK(glVertexAttrib4Nusv(index, v));
				break;
			}
			case CommandId::VertexAttrib4bv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLbyte * v = m_Buffer.read<const GLbyte *>();
				GL_CHECK(glVertexAttrib4bv(index, v));
				break;
			}
			case CommandId::VertexAttrib4d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GLdouble w = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttrib4d(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttrib4dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttrib4dv(index, v));
				break;
			}
			case CommandId::VertexAttrib4f:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat x = m_Buffer.read<GLfloat>();
				GLfloat y = m_Buffer.read<GLfloat>();
				GLfloat z = m_Buffer.read<GLfloat>();
				GLfloat w = m_Buffer.read<GLfloat>();
				GL_CHECK(glVertexAttrib4f(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttrib4fv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glVertexAttrib4fv(index, v));
				break;
			}
			case CommandId::VertexAttrib4iv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttrib4iv(index, v));
				break;
			}
			case CommandId::VertexAttrib4s:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLshort x = m_Buffer.read<GLshort>();
				GLshort y = m_Buffer.read<GLshort>();
				GLshort z = m_Buffer.read<GLshort>();
				GLshort w = m_Buffer.read<GLshort>();
				GL_CHECK(glVertexAttrib4s(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttrib4sv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttrib4sv(index, v));
				break;
			}
			case CommandId::VertexAttrib4ubv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLubyte * v = m_Buffer.read<const GLubyte *>();
				GL_CHECK(glVertexAttrib4ubv(index, v));
				break;
			}
			case CommandId::VertexAttrib4uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttrib4uiv(index, v));
				break;
			}
			case CommandId::VertexAttrib4usv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLushort * v = m_Buffer.read<const GLushort *>();
				GL_CHECK(glVertexAttrib4usv(index, v));
				break;
			}
			case CommandId::VertexAttribPointer:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				const void * pointer = m_Buffer.read<const void *>();
				GL_CHECK(glVertexAttribPointer(index, size, type, normalized, stride, pointer));
				break;
			}
			case CommandId::UniformMatrix2x3fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix2x3fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3x2fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix3x2fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix2x4fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix2x4fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4x2fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix4x2fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3x4fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix3x4fv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4x3fv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glUniformMatrix4x3fv(location, count, transpose, value));
				break;
			}
			case CommandId::ColorMaski:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLboolean r = m_Buffer.read<GLboolean>();
				GLboolean g = m_Buffer.read<GLboolean>();
				GLboolean b = m_Buffer.read<GLboolean>();
				GLboolean a = m_Buffer.read<GLboolean>();
				GL_CHECK(glColorMaski(index, r, g, b, a));
				break;
			}
			case CommandId::GetBooleani_v:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				GLboolean * data = m_Buffer.read<GLboolean *>();
				GL_CHECK(glGetBooleani_v(target, index, data));
				break;
			}
			case CommandId::GetIntegeri_v:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GLint * data = m_Buffer.read<GLint *>();
				GL_CHECK(glGetIntegeri_v(target, index, data));
				break;
			}
			case CommandId::Enablei:
			{
				multigl::EnableCap target = m_Buffer.read<multigl::EnableCap>();
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glEnablei(target, index));
				break;
			}
			case CommandId::Disablei:
			{
				multigl::EnableCap target = m_Buffer.read<multigl::EnableCap>();
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glDisablei(target, index));
				break;
			}
			case CommandId::BeginTransformFeedback:
			{
				multigl::PrimitiveType primitiveMode = m_Buffer.read<multigl::PrimitiveType>();
				GL_CHECK(glBeginTransformFeedback(primitiveMode));
				break;
			}
			case CommandId::EndTransformFeedback:
			{
				GL_CHECK(glEndTransformFeedback());
				break;
			}
			case CommandId::BindBufferRange:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glBindBufferRange(target, index, buffer, offset, size));
				break;
			}
			case CommandId::BindBufferBase:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glBindBufferBase(target, index, buffer));
				break;
			}
			case CommandId::TransformFeedbackVaryings:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLchar *const* varyings = m_Buffer.read<const GLchar *const*>();
				multigl::TransformFeedbackBufferMode bufferMode = m_Buffer.read<multigl::TransformFeedbackBufferMode>();
				GL_CHECK(glTransformFeedbackVaryings(program, count, varyings, bufferMode));
				break;
			}
			case CommandId::GetTransformFeedbackVarying:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLsizei * size = m_Buffer.read<GLsizei *>();
				GLenum * type = m_Buffer.read<GLenum *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name));
				break;
			}
			case CommandId::ClampColor:
			{
				multigl::ClampColorTargetARB target = m_Buffer.read<multigl::ClampColorTargetARB>();
				multigl::ClampColorModeARB clamp = m_Buffer.read<multigl::ClampColorModeARB>();
				GL_CHECK(glClampColor(target, clamp));
				break;
			}
			case CommandId::BeginConditionalRender:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::ConditionalRenderMode mode = m_Buffer.read<multigl::ConditionalRenderMode>();
				GL_CHECK(glBeginConditionalRender(id, mode));
				break;
			}
			case CommandId::EndConditionalRender:
			{
				GL_CHECK(glEndConditionalRender());
				break;
			}
			case CommandId::VertexAttribIPointer:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				const void * pointer = m_Buffer.read<const void *>();
				GL_CHECK(glVertexAttribIPointer(index, size, type, stride, pointer));
				break;
			}
			case CommandId::GetVertexAttribIiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribEnum pname = m_Buffer.read<multigl::VertexAttribEnum>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetVertexAttribIiv(index, pname, params));
				break;
			}
			case CommandId::GetVertexAttribIuiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribEnum pname = m_Buffer.read<multigl::VertexAttribEnum>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetVertexAttribIuiv(index, pname, params));
				break;
			}
			case CommandId::VertexAttribI1i:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint x = m_Buffer.read<GLint>();
				GL_CHECK(glVertexAttribI1i(index, x));
				break;
			}
			case CommandId::VertexAttribI2i:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GL_CHECK(glVertexAttribI2i(index, x, y));
				break;
			}
			case CommandId::VertexAttribI3i:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLint z = m_Buffer.read<GLint>();
				GL_CHECK(glVertexAttribI3i(index, x, y, z));
				break;
			}
			case CommandId::VertexAttribI4i:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLint z = m_Buffer.read<GLint>();
				GLint w = m_Buffer.read<GLint>();
				GL_CHECK(glVertexAttribI4i(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttribI1ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLuint x = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribI1ui(index, x));
				break;
			}
			case CommandId::VertexAttribI2ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLuint x = m_Buffer.read<GLuint>();
				GLuint y = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribI2ui(index, x, y));
				break;
			}
			case CommandId::VertexAttribI3ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLuint x = m_Buffer.read<GLuint>();
				GLuint y = m_Buffer.read<GLuint>();
				GLuint z = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribI3ui(index, x, y, z));
				break;
			}
			case CommandId::VertexAttribI4ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLuint x = m_Buffer.read<GLuint>();
				GLuint y = m_Buffer.read<GLuint>();
				GLuint z = m_Buffer.read<GLuint>();
				GLuint w = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribI4ui(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttribI1iv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttribI1iv(index, v));
				break;
			}
			case CommandId::VertexAttribI2iv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttribI2iv(index, v));
				break;
			}
			case CommandId::VertexAttribI3iv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttribI3iv(index, v));
				break;
			}
			case CommandId::VertexAttribI4iv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glVertexAttribI4iv(index, v));
				break;
			}
			case CommandId::VertexAttribI1uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribI1uiv(index, v));
				break;
			}
			case CommandId::VertexAttribI2uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribI2uiv(index, v));
				break;
			}
			case CommandId::VertexAttribI3uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribI3uiv(index, v));
				break;
			}
			case CommandId::VertexAttribI4uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLuint * v = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribI4uiv(index, v));
				break;
			}
			case CommandId::VertexAttribI4bv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLbyte * v = m_Buffer.read<const GLbyte *>();
				GL_CHECK(glVertexAttribI4bv(index, v));
				break;
			}
			case CommandId::VertexAttribI4sv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLshort * v = m_Buffer.read<const GLshort *>();
				GL_CHECK(glVertexAttribI4sv(index, v));
				break;
			}
			case CommandId::VertexAttribI4ubv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLubyte * v = m_Buffer.read<const GLubyte *>();
				GL_CHECK(glVertexAttribI4ubv(index, v));
				break;
			}
			case CommandId::VertexAttribI4usv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLushort * v = m_Buffer.read<const GLushort *>();
				GL_CHECK(glVertexAttribI4usv(index, v));
				break;
			}
			case CommandId::GetUniformuiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetUniformuiv(program, location, params));
				break;
			}
			case CommandId::BindFragDataLocation:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint color = m_Buffer.read<GLuint>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glBindFragDataLocation(program, color, name));
				break;
			}
			case CommandId::Uniform1ui:
			{
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GL_CHECK(glUniform1ui(location, v0));
				break;
			}
			case CommandId::Uniform2ui:
			{
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GL_CHECK(glUniform2ui(location, v0, v1));
				break;
			}
			case CommandId::Uniform3ui:
			{
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GLuint v2 = m_Buffer.read<GLuint>();
				GL_CHECK(glUniform3ui(location, v0, v1, v2));
				break;
			}
			case CommandId::Uniform4ui:
			{
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GLuint v2 = m_Buffer.read<GLuint>();
				GLuint v3 = m_Buffer.read<GLuint>();
				GL_CHECK(glUniform4ui(location, v0, v1, v2, v3));
				break;
			}
			case CommandId::Uniform1uiv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glUniform1uiv(location, count, value));
				break;
			}
			case CommandId::Uniform2uiv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glUniform2uiv(location, count, value));
				break;
			}
			case CommandId::Uniform3uiv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glUniform3uiv(location, count, value));
				break;
			}
			case CommandId::Uniform4uiv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glUniform4uiv(location, count, value));
				break;
			}
			case CommandId::TexParameterIiv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLint * params = m_Buffer.read<const GLint *>();
				GL_CHECK(glTexParameterIiv(target, pname, params));
				break;
			}
			case CommandId::TexParameterIuiv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLuint * params = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTexParameterIuiv(target, pname, params));
				break;
			}
			case CommandId::GetTexParameterIiv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTexParameterIiv(target, pname, params));
				break;
			}
			case CommandId::GetTexParameterIuiv:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetTexParameterIuiv(target, pname, params));
				break;
			}
			case CommandId::ClearBufferiv:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glClearBufferiv(buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearBufferuiv:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glClearBufferuiv(buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearBufferfv:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glClearBufferfv(buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearBufferfi:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				GLfloat depth = m_Buffer.read<GLfloat>();
				GLint stencil = m_Buffer.read<GLint>();
				GL_CHECK(glClearBufferfi(buffer, drawbuffer, depth, stencil));
				break;
			}
			case CommandId::BindRenderbuffer:
			{
				multigl::RenderbufferTarget target = m_Buffer.read<multigl::RenderbufferTarget>();
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				GL_CHECK(glBindRenderbuffer(target, renderbuffer));
				break;
			}
			case CommandId::DeleteRenderbuffers:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * renderbuffers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteRenderbuffers(n, renderbuffers));
				break;
			}
			case CommandId::GenRenderbuffer:
			{
				auto handle = m_Buffer.read<RenderbufferHandle>();
				auto& target = *m_ResourceManager.Renderbuffers.get(handle);
				glGenRenderbuffers(1, &target);
				break;
			}
			case CommandId::RenderbufferStorage:
			{
				multigl::RenderbufferTarget target = m_Buffer.read<multigl::RenderbufferTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glRenderbufferStorage(target, internalformat, width, height));
				break;
			}
			case CommandId::GetRenderbufferParameteriv:
			{
				multigl::RenderbufferTarget target = m_Buffer.read<multigl::RenderbufferTarget>();
				multigl::RenderbufferParameterName pname = m_Buffer.read<multigl::RenderbufferParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetRenderbufferParameteriv(target, pname, params));
				break;
			}
			case CommandId::BindFramebuffer:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GL_CHECK(glBindFramebuffer(target, framebuffer));
				break;
			}
			case CommandId::DeleteFramebuffers:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * framebuffers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteFramebuffers(n, framebuffers));
				break;
			}
			case CommandId::GenFramebuffer:
			{
				auto handle = m_Buffer.read<FramebufferHandle>();
				auto& target = *m_ResourceManager.Framebuffers.get(handle);
				glGenFramebuffers(1, &target);
				break;
			}
			case CommandId::FramebufferTexture1D:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::TextureTarget textarget = m_Buffer.read<multigl::TextureTarget>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferTexture1D(target, attachment, textarget, texture, level));
				break;
			}
			case CommandId::FramebufferTexture2D:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::TextureTarget textarget = m_Buffer.read<multigl::TextureTarget>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferTexture2D(target, attachment, textarget, texture, level));
				break;
			}
			case CommandId::FramebufferTexture3D:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::TextureTarget textarget = m_Buffer.read<multigl::TextureTarget>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset));
				break;
			}
			case CommandId::FramebufferRenderbuffer:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::RenderbufferTarget renderbuffertarget = m_Buffer.read<multigl::RenderbufferTarget>();
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				GL_CHECK(glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer));
				break;
			}
			case CommandId::GetFramebufferAttachmentParameteriv:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::FramebufferAttachmentParameterName pname = m_Buffer.read<multigl::FramebufferAttachmentParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetFramebufferAttachmentParameteriv(target, attachment, pname, params));
				break;
			}
			case CommandId::GenerateMipmap:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GL_CHECK(glGenerateMipmap(target));
				break;
			}
			case CommandId::BlitFramebuffer:
			{
				GLint srcX0 = m_Buffer.read<GLint>();
				GLint srcY0 = m_Buffer.read<GLint>();
				GLint srcX1 = m_Buffer.read<GLint>();
				GLint srcY1 = m_Buffer.read<GLint>();
				GLint dstX0 = m_Buffer.read<GLint>();
				GLint dstY0 = m_Buffer.read<GLint>();
				GLint dstX1 = m_Buffer.read<GLint>();
				GLint dstY1 = m_Buffer.read<GLint>();
				GLbitfield mask = m_Buffer.read<GLbitfield>();
				multigl::BlitFramebufferFilter filter = m_Buffer.read<multigl::BlitFramebufferFilter>();
				GL_CHECK(glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter));
				break;
			}
			case CommandId::RenderbufferStorageMultisample:
			{
				multigl::RenderbufferTarget target = m_Buffer.read<multigl::RenderbufferTarget>();
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glRenderbufferStorageMultisample(target, samples, internalformat, width, height));
				break;
			}
			case CommandId::FramebufferTextureLayer:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint layer = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferTextureLayer(target, attachment, texture, level, layer));
				break;
			}
			case CommandId::FlushMappedBufferRange:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr length = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glFlushMappedBufferRange(target, offset, length));
				break;
			}
			case CommandId::BindVertexArray:
			{
				VertexArrayHandle arrayHandle = m_Buffer.read<VertexArrayHandle>();
				auto& array = *m_ResourceManager.VertexArrays.get(arrayHandle);
				GL_CHECK(glBindVertexArray(array));
				break;
			}
			case CommandId::DeleteVertexArrays:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * arrays = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteVertexArrays(n, arrays));
				break;
			}
			case CommandId::GenVertexArray:
			{
				auto handle = m_Buffer.read<VertexArrayHandle>();
				auto& target = *m_ResourceManager.VertexArrays.get(handle);
				glGenVertexArrays(1, &target);
				break;
			}
			case CommandId::DrawArraysInstanced:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLint first = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GL_CHECK(glDrawArraysInstanced(mode, first, count, instancecount));
				break;
			}
			case CommandId::DrawElementsInstanced:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GL_CHECK(glDrawElementsInstanced(mode, count, type, indices, instancecount));
				break;
			}
			case CommandId::TexBuffer:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glTexBuffer(target, internalformat, buffer));
				break;
			}
			case CommandId::PrimitiveRestartIndex:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glPrimitiveRestartIndex(index));
				break;
			}
			case CommandId::CopyBufferSubData:
			{
				multigl::CopyBufferSubDataTarget readTarget = m_Buffer.read<multigl::CopyBufferSubDataTarget>();
				multigl::CopyBufferSubDataTarget writeTarget = m_Buffer.read<multigl::CopyBufferSubDataTarget>();
				GLintptr readOffset = m_Buffer.read<GLintptr>();
				GLintptr writeOffset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size));
				break;
			}
			case CommandId::GetUniformIndices:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei uniformCount = m_Buffer.read<GLsizei>();
				const GLchar *const* uniformNames = m_Buffer.read<const GLchar *const*>();
				GLuint * uniformIndices = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices));
				break;
			}
			case CommandId::GetActiveUniformsiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei uniformCount = m_Buffer.read<GLsizei>();
				const GLuint * uniformIndices = m_Buffer.read<const GLuint *>();
				multigl::UniformPName pname = m_Buffer.read<multigl::UniformPName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params));
				break;
			}
			case CommandId::GetActiveUniformName:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint uniformIndex = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * uniformName = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName));
				break;
			}
			case CommandId::GetActiveUniformBlockiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint uniformBlockIndex = m_Buffer.read<GLuint>();
				multigl::UniformBlockPName pname = m_Buffer.read<multigl::UniformBlockPName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params));
				break;
			}
			case CommandId::GetActiveUniformBlockName:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint uniformBlockIndex = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * uniformBlockName = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName));
				break;
			}
			case CommandId::UniformBlockBinding:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint uniformBlockIndex = m_Buffer.read<GLuint>();
				GLuint uniformBlockBinding = m_Buffer.read<GLuint>();
				GL_CHECK(glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding));
				break;
			}
			case CommandId::DrawElementsBaseVertex:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GLint basevertex = m_Buffer.read<GLint>();
				GL_CHECK(glDrawElementsBaseVertex(mode, count, type, indices, basevertex));
				break;
			}
			case CommandId::DrawRangeElementsBaseVertex:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint start = m_Buffer.read<GLuint>();
				GLuint end = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GLint basevertex = m_Buffer.read<GLint>();
				GL_CHECK(glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex));
				break;
			}
			case CommandId::DrawElementsInstancedBaseVertex:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GLint basevertex = m_Buffer.read<GLint>();
				GL_CHECK(glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex));
				break;
			}
			case CommandId::MultiDrawElementsBaseVertex:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				const GLsizei * count = m_Buffer.read<const GLsizei *>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void *const* indices = m_Buffer.read<const void *const*>();
				GLsizei drawcount = m_Buffer.read<GLsizei>();
				const GLint * basevertex = m_Buffer.read<const GLint *>();
				GL_CHECK(glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex));
				break;
			}
			case CommandId::ProvokingVertex:
			{
				multigl::VertexProvokingMode mode = m_Buffer.read<multigl::VertexProvokingMode>();
				GL_CHECK(glProvokingVertex(mode));
				break;
			}
			case CommandId::DeleteSync:
			{
				GLsync sync = m_Buffer.read<GLsync>();
				GL_CHECK(glDeleteSync(sync));
				break;
			}
			case CommandId::WaitSync:
			{
				GLsync sync = m_Buffer.read<GLsync>();
				GLbitfield flags = m_Buffer.read<GLbitfield>();
				GLuint64 timeout = m_Buffer.read<GLuint64>();
				GL_CHECK(glWaitSync(sync, flags, timeout));
				break;
			}
			case CommandId::GetInteger64v:
			{
				multigl::GetPName pname = m_Buffer.read<multigl::GetPName>();
				GLint64 * data = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetInteger64v(pname, data));
				break;
			}
			case CommandId::GetSynciv:
			{
				GLsync sync = m_Buffer.read<GLsync>();
				multigl::SyncParameterName pname = m_Buffer.read<multigl::SyncParameterName>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLint * values = m_Buffer.read<GLint *>();
				GL_CHECK(glGetSynciv(sync, pname, count, length, values));
				break;
			}
			case CommandId::GetInteger64i_v:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GLint64 * data = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetInteger64i_v(target, index, data));
				break;
			}
			case CommandId::GetBufferParameteri64v:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				multigl::BufferPNameARB pname = m_Buffer.read<multigl::BufferPNameARB>();
				GLint64 * params = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetBufferParameteri64v(target, pname, params));
				break;
			}
			case CommandId::FramebufferTexture:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferTexture(target, attachment, texture, level));
				break;
			}
			case CommandId::TexImage2DMultisample:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations));
				break;
			}
			case CommandId::TexImage3DMultisample:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations));
				break;
			}
			case CommandId::GetMultisamplefv:
			{
				multigl::GetMultisamplePNameNV pname = m_Buffer.read<multigl::GetMultisamplePNameNV>();
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat * val = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetMultisamplefv(pname, index, val));
				break;
			}
			case CommandId::SampleMaski:
			{
				GLuint maskNumber = m_Buffer.read<GLuint>();
				GLbitfield mask = m_Buffer.read<GLbitfield>();
				GL_CHECK(glSampleMaski(maskNumber, mask));
				break;
			}
			case CommandId::BindFragDataLocationIndexed:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint colorNumber = m_Buffer.read<GLuint>();
				GLuint index = m_Buffer.read<GLuint>();
				const GLchar * name = m_Buffer.read<const GLchar *>();
				GL_CHECK(glBindFragDataLocationIndexed(program, colorNumber, index, name));
				break;
			}
			case CommandId::GenSamplers:
			{
				GLsizei count = m_Buffer.read<GLsizei>();
				GLuint * samplers = m_Buffer.read<GLuint *>();
				GL_CHECK(glGenSamplers(count, samplers));
				break;
			}
			case CommandId::DeleteSamplers:
			{
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * samplers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteSamplers(count, samplers));
				break;
			}
			case CommandId::BindSampler:
			{
				GLuint unit = m_Buffer.read<GLuint>();
				GLuint sampler = m_Buffer.read<GLuint>();
				GL_CHECK(glBindSampler(unit, sampler));
				break;
			}
			case CommandId::SamplerParameteri:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glSamplerParameteri(sampler, pname, param));
				break;
			}
			case CommandId::SamplerParameteriv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				const GLint * param = m_Buffer.read<const GLint *>();
				GL_CHECK(glSamplerParameteriv(sampler, pname, param));
				break;
			}
			case CommandId::SamplerParameterf:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterF pname = m_Buffer.read<multigl::SamplerParameterF>();
				GLfloat param = m_Buffer.read<GLfloat>();
				GL_CHECK(glSamplerParameterf(sampler, pname, param));
				break;
			}
			case CommandId::SamplerParameterfv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterF pname = m_Buffer.read<multigl::SamplerParameterF>();
				const GLfloat * param = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glSamplerParameterfv(sampler, pname, param));
				break;
			}
			case CommandId::SamplerParameterIiv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				const GLint * param = m_Buffer.read<const GLint *>();
				GL_CHECK(glSamplerParameterIiv(sampler, pname, param));
				break;
			}
			case CommandId::SamplerParameterIuiv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				const GLuint * param = m_Buffer.read<const GLuint *>();
				GL_CHECK(glSamplerParameterIuiv(sampler, pname, param));
				break;
			}
			case CommandId::GetSamplerParameteriv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetSamplerParameteriv(sampler, pname, params));
				break;
			}
			case CommandId::GetSamplerParameterIiv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetSamplerParameterIiv(sampler, pname, params));
				break;
			}
			case CommandId::GetSamplerParameterfv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterF pname = m_Buffer.read<multigl::SamplerParameterF>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetSamplerParameterfv(sampler, pname, params));
				break;
			}
			case CommandId::GetSamplerParameterIuiv:
			{
				GLuint sampler = m_Buffer.read<GLuint>();
				multigl::SamplerParameterI pname = m_Buffer.read<multigl::SamplerParameterI>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetSamplerParameterIuiv(sampler, pname, params));
				break;
			}
			case CommandId::QueryCounter:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::QueryCounterTarget target = m_Buffer.read<multigl::QueryCounterTarget>();
				GL_CHECK(glQueryCounter(id, target));
				break;
			}
			case CommandId::GetQueryObjecti64v:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLint64 * params = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetQueryObjecti64v(id, pname, params));
				break;
			}
			case CommandId::GetQueryObjectui64v:
			{
				GLuint id = m_Buffer.read<GLuint>();
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLuint64 * params = m_Buffer.read<GLuint64 *>();
				GL_CHECK(glGetQueryObjectui64v(id, pname, params));
				break;
			}
			case CommandId::VertexAttribDivisor:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLuint divisor = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribDivisor(index, divisor));
				break;
			}
			case CommandId::VertexAttribP1ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribP1ui(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP1uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribP1uiv(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP2ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribP2ui(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP2uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribP2uiv(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP3ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribP3ui(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP3uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribP3uiv(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP4ui:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribP4ui(index, type, normalized, value));
				break;
			}
			case CommandId::VertexAttribP4uiv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexAttribP4uiv(index, type, normalized, value));
				break;
			}
			case CommandId::VertexP2ui:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexP2ui(type, value));
				break;
			}
			case CommandId::VertexP2uiv:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexP2uiv(type, value));
				break;
			}
			case CommandId::VertexP3ui:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexP3ui(type, value));
				break;
			}
			case CommandId::VertexP3uiv:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexP3uiv(type, value));
				break;
			}
			case CommandId::VertexP4ui:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				GLuint value = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexP4ui(type, value));
				break;
			}
			case CommandId::VertexP4uiv:
			{
				multigl::VertexPointerType type = m_Buffer.read<multigl::VertexPointerType>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glVertexP4uiv(type, value));
				break;
			}
			case CommandId::TexCoordP1ui:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glTexCoordP1ui(type, coords));
				break;
			}
			case CommandId::TexCoordP1uiv:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTexCoordP1uiv(type, coords));
				break;
			}
			case CommandId::TexCoordP2ui:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glTexCoordP2ui(type, coords));
				break;
			}
			case CommandId::TexCoordP2uiv:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTexCoordP2uiv(type, coords));
				break;
			}
			case CommandId::TexCoordP3ui:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glTexCoordP3ui(type, coords));
				break;
			}
			case CommandId::TexCoordP3uiv:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTexCoordP3uiv(type, coords));
				break;
			}
			case CommandId::TexCoordP4ui:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glTexCoordP4ui(type, coords));
				break;
			}
			case CommandId::TexCoordP4uiv:
			{
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTexCoordP4uiv(type, coords));
				break;
			}
			case CommandId::MultiTexCoordP1ui:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glMultiTexCoordP1ui(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP1uiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glMultiTexCoordP1uiv(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP2ui:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glMultiTexCoordP2ui(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP2uiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glMultiTexCoordP2uiv(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP3ui:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glMultiTexCoordP3ui(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP3uiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glMultiTexCoordP3uiv(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP4ui:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glMultiTexCoordP4ui(texture, type, coords));
				break;
			}
			case CommandId::MultiTexCoordP4uiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TexCoordPointerType type = m_Buffer.read<multigl::TexCoordPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glMultiTexCoordP4uiv(texture, type, coords));
				break;
			}
			case CommandId::NormalP3ui:
			{
				multigl::NormalPointerType type = m_Buffer.read<multigl::NormalPointerType>();
				GLuint coords = m_Buffer.read<GLuint>();
				GL_CHECK(glNormalP3ui(type, coords));
				break;
			}
			case CommandId::NormalP3uiv:
			{
				multigl::NormalPointerType type = m_Buffer.read<multigl::NormalPointerType>();
				const GLuint * coords = m_Buffer.read<const GLuint *>();
				GL_CHECK(glNormalP3uiv(type, coords));
				break;
			}
			case CommandId::ColorP3ui:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				GLuint color = m_Buffer.read<GLuint>();
				GL_CHECK(glColorP3ui(type, color));
				break;
			}
			case CommandId::ColorP3uiv:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				const GLuint * color = m_Buffer.read<const GLuint *>();
				GL_CHECK(glColorP3uiv(type, color));
				break;
			}
			case CommandId::ColorP4ui:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				GLuint color = m_Buffer.read<GLuint>();
				GL_CHECK(glColorP4ui(type, color));
				break;
			}
			case CommandId::ColorP4uiv:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				const GLuint * color = m_Buffer.read<const GLuint *>();
				GL_CHECK(glColorP4uiv(type, color));
				break;
			}
			case CommandId::SecondaryColorP3ui:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				GLuint color = m_Buffer.read<GLuint>();
				GL_CHECK(glSecondaryColorP3ui(type, color));
				break;
			}
			case CommandId::SecondaryColorP3uiv:
			{
				multigl::ColorPointerType type = m_Buffer.read<multigl::ColorPointerType>();
				const GLuint * color = m_Buffer.read<const GLuint *>();
				GL_CHECK(glSecondaryColorP3uiv(type, color));
				break;
			}
			case CommandId::MinSampleShading:
			{
				GLfloat value = m_Buffer.read<GLfloat>();
				GL_CHECK(glMinSampleShading(value));
				break;
			}
			case CommandId::BlendEquationi:
			{
				GLuint buf = m_Buffer.read<GLuint>();
				multigl::BlendEquationModeEXT mode = m_Buffer.read<multigl::BlendEquationModeEXT>();
				GL_CHECK(glBlendEquationi(buf, mode));
				break;
			}
			case CommandId::BlendEquationSeparatei:
			{
				GLuint buf = m_Buffer.read<GLuint>();
				multigl::BlendEquationModeEXT modeRGB = m_Buffer.read<multigl::BlendEquationModeEXT>();
				multigl::BlendEquationModeEXT modeAlpha = m_Buffer.read<multigl::BlendEquationModeEXT>();
				GL_CHECK(glBlendEquationSeparatei(buf, modeRGB, modeAlpha));
				break;
			}
			case CommandId::BlendFunci:
			{
				GLuint buf = m_Buffer.read<GLuint>();
				multigl::BlendingFactor src = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dst = m_Buffer.read<multigl::BlendingFactor>();
				GL_CHECK(glBlendFunci(buf, src, dst));
				break;
			}
			case CommandId::BlendFuncSeparatei:
			{
				GLuint buf = m_Buffer.read<GLuint>();
				multigl::BlendingFactor srcRGB = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dstRGB = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor srcAlpha = m_Buffer.read<multigl::BlendingFactor>();
				multigl::BlendingFactor dstAlpha = m_Buffer.read<multigl::BlendingFactor>();
				GL_CHECK(glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha));
				break;
			}
			case CommandId::DrawArraysIndirect:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				const void * indirect = m_Buffer.read<const void *>();
				GL_CHECK(glDrawArraysIndirect(mode, indirect));
				break;
			}
			case CommandId::DrawElementsIndirect:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indirect = m_Buffer.read<const void *>();
				GL_CHECK(glDrawElementsIndirect(mode, type, indirect));
				break;
			}
			case CommandId::Uniform1d:
			{
				GLint location = m_Buffer.read<GLint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GL_CHECK(glUniform1d(location, x));
				break;
			}
			case CommandId::Uniform2d:
			{
				GLint location = m_Buffer.read<GLint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GL_CHECK(glUniform2d(location, x, y));
				break;
			}
			case CommandId::Uniform3d:
			{
				GLint location = m_Buffer.read<GLint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GL_CHECK(glUniform3d(location, x, y, z));
				break;
			}
			case CommandId::Uniform4d:
			{
				GLint location = m_Buffer.read<GLint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GLdouble w = m_Buffer.read<GLdouble>();
				GL_CHECK(glUniform4d(location, x, y, z, w));
				break;
			}
			case CommandId::Uniform1dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniform1dv(location, count, value));
				break;
			}
			case CommandId::Uniform2dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniform2dv(location, count, value));
				break;
			}
			case CommandId::Uniform3dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniform3dv(location, count, value));
				break;
			}
			case CommandId::Uniform4dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniform4dv(location, count, value));
				break;
			}
			case CommandId::UniformMatrix2dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix2dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix3dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix4dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix2x3dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix2x3dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix2x4dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix2x4dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3x2dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix3x2dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix3x4dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix3x4dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4x2dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix4x2dv(location, count, transpose, value));
				break;
			}
			case CommandId::UniformMatrix4x3dv:
			{
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glUniformMatrix4x3dv(location, count, transpose, value));
				break;
			}
			case CommandId::GetUniformdv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLdouble * params = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetUniformdv(program, location, params));
				break;
			}
			case CommandId::GetActiveSubroutineUniformiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				GLuint index = m_Buffer.read<GLuint>();
				multigl::SubroutineParameterName pname = m_Buffer.read<multigl::SubroutineParameterName>();
				GLint * values = m_Buffer.read<GLint *>();
				GL_CHECK(glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values));
				break;
			}
			case CommandId::GetActiveSubroutineUniformName:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name));
				break;
			}
			case CommandId::GetActiveSubroutineName:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name));
				break;
			}
			case CommandId::UniformSubroutinesuiv:
			{
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * indices = m_Buffer.read<const GLuint *>();
				GL_CHECK(glUniformSubroutinesuiv(shadertype, count, indices));
				break;
			}
			case CommandId::GetUniformSubroutineuiv:
			{
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				GLint location = m_Buffer.read<GLint>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetUniformSubroutineuiv(shadertype, location, params));
				break;
			}
			case CommandId::GetProgramStageiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				multigl::ProgramStagePName pname = m_Buffer.read<multigl::ProgramStagePName>();
				GLint * values = m_Buffer.read<GLint *>();
				GL_CHECK(glGetProgramStageiv(program, shadertype, pname, values));
				break;
			}
			case CommandId::PatchParameteri:
			{
				multigl::PatchParameterName pname = m_Buffer.read<multigl::PatchParameterName>();
				GLint value = m_Buffer.read<GLint>();
				GL_CHECK(glPatchParameteri(pname, value));
				break;
			}
			case CommandId::PatchParameterfv:
			{
				multigl::PatchParameterName pname = m_Buffer.read<multigl::PatchParameterName>();
				const GLfloat * values = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glPatchParameterfv(pname, values));
				break;
			}
			case CommandId::BindTransformFeedback:
			{
				multigl::BindTransformFeedbackTarget target = m_Buffer.read<multigl::BindTransformFeedbackTarget>();
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glBindTransformFeedback(target, id));
				break;
			}
			case CommandId::DeleteTransformFeedbacks:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * ids = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteTransformFeedbacks(n, ids));
				break;
			}
			case CommandId::GenTransformFeedbacks:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * ids = m_Buffer.read<GLuint *>();
				GL_CHECK(glGenTransformFeedbacks(n, ids));
				break;
			}
			case CommandId::PauseTransformFeedback:
			{
				GL_CHECK(glPauseTransformFeedback());
				break;
			}
			case CommandId::ResumeTransformFeedback:
			{
				GL_CHECK(glResumeTransformFeedback());
				break;
			}
			case CommandId::DrawTransformFeedback:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glDrawTransformFeedback(mode, id));
				break;
			}
			case CommandId::DrawTransformFeedbackStream:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint id = m_Buffer.read<GLuint>();
				GLuint stream = m_Buffer.read<GLuint>();
				GL_CHECK(glDrawTransformFeedbackStream(mode, id, stream));
				break;
			}
			case CommandId::BeginQueryIndexed:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				GLuint id = m_Buffer.read<GLuint>();
				GL_CHECK(glBeginQueryIndexed(target, index, id));
				break;
			}
			case CommandId::EndQueryIndexed:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glEndQueryIndexed(target, index));
				break;
			}
			case CommandId::GetQueryIndexediv:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GLuint index = m_Buffer.read<GLuint>();
				multigl::QueryParameterName pname = m_Buffer.read<multigl::QueryParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetQueryIndexediv(target, index, pname, params));
				break;
			}
			case CommandId::ReleaseShaderCompiler:
			{
				GL_CHECK(glReleaseShaderCompiler());
				break;
			}
			case CommandId::ShaderBinary:
			{
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * shaders = m_Buffer.read<const GLuint *>();
				GLenum binaryformat = m_Buffer.read<GLenum>();
				const void * binary = m_Buffer.read<const void *>();
				GLsizei length = m_Buffer.read<GLsizei>();
				GL_CHECK(glShaderBinary(count, shaders, binaryformat, binary, length));
				break;
			}
			case CommandId::GetShaderPrecisionFormat:
			{
				multigl::ShaderType shadertype = m_Buffer.read<multigl::ShaderType>();
				multigl::PrecisionType precisiontype = m_Buffer.read<multigl::PrecisionType>();
				GLint * range = m_Buffer.read<GLint *>();
				GLint * precision = m_Buffer.read<GLint *>();
				GL_CHECK(glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision));
				break;
			}
			case CommandId::DepthRangef:
			{
				GLfloat n = m_Buffer.read<GLfloat>();
				GLfloat f = m_Buffer.read<GLfloat>();
				GL_CHECK(glDepthRangef(n, f));
				break;
			}
			case CommandId::ClearDepthf:
			{
				GLfloat d = m_Buffer.read<GLfloat>();
				GL_CHECK(glClearDepthf(d));
				break;
			}
			case CommandId::GetProgramBinary:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLenum * binaryFormat = m_Buffer.read<GLenum *>();
				void * binary = m_Buffer.read<void *>();
				GL_CHECK(glGetProgramBinary(program, bufSize, length, binaryFormat, binary));
				break;
			}
			case CommandId::ProgramBinary:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLenum binaryFormat = m_Buffer.read<GLenum>();
				const void * binary = m_Buffer.read<const void *>();
				GLsizei length = m_Buffer.read<GLsizei>();
				GL_CHECK(glProgramBinary(program, binaryFormat, binary, length));
				break;
			}
			case CommandId::ProgramParameteri:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ProgramParameterPName pname = m_Buffer.read<multigl::ProgramParameterPName>();
				GLint value = m_Buffer.read<GLint>();
				GL_CHECK(glProgramParameteri(program, pname, value));
				break;
			}
			case CommandId::UseProgramStages:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				GLbitfield stages = m_Buffer.read<GLbitfield>();
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glUseProgramStages(pipeline, stages, program));
				break;
			}
			case CommandId::ActiveShaderProgram:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GL_CHECK(glActiveShaderProgram(pipeline, program));
				break;
			}
			case CommandId::BindProgramPipeline:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				GL_CHECK(glBindProgramPipeline(pipeline));
				break;
			}
			case CommandId::DeleteProgramPipelines:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLuint * pipelines = m_Buffer.read<const GLuint *>();
				GL_CHECK(glDeleteProgramPipelines(n, pipelines));
				break;
			}
			case CommandId::GenProgramPipelines:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * pipelines = m_Buffer.read<GLuint *>();
				GL_CHECK(glGenProgramPipelines(n, pipelines));
				break;
			}
			case CommandId::GetProgramPipelineiv:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				multigl::PipelineParameterName pname = m_Buffer.read<multigl::PipelineParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetProgramPipelineiv(pipeline, pname, params));
				break;
			}
			case CommandId::ProgramUniform1i:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GL_CHECK(glProgramUniform1i(program, location, v0));
				break;
			}
			case CommandId::ProgramUniform1iv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glProgramUniform1iv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform1f:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GL_CHECK(glProgramUniform1f(program, location, v0));
				break;
			}
			case CommandId::ProgramUniform1fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniform1fv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform1d:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLdouble v0 = m_Buffer.read<GLdouble>();
				GL_CHECK(glProgramUniform1d(program, location, v0));
				break;
			}
			case CommandId::ProgramUniform1dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniform1dv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform1ui:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GL_CHECK(glProgramUniform1ui(program, location, v0));
				break;
			}
			case CommandId::ProgramUniform1uiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glProgramUniform1uiv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform2i:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GL_CHECK(glProgramUniform2i(program, location, v0, v1));
				break;
			}
			case CommandId::ProgramUniform2iv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glProgramUniform2iv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform2f:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GL_CHECK(glProgramUniform2f(program, location, v0, v1));
				break;
			}
			case CommandId::ProgramUniform2fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniform2fv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform2d:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLdouble v0 = m_Buffer.read<GLdouble>();
				GLdouble v1 = m_Buffer.read<GLdouble>();
				GL_CHECK(glProgramUniform2d(program, location, v0, v1));
				break;
			}
			case CommandId::ProgramUniform2dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniform2dv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform2ui:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GL_CHECK(glProgramUniform2ui(program, location, v0, v1));
				break;
			}
			case CommandId::ProgramUniform2uiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glProgramUniform2uiv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform3i:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GLint v2 = m_Buffer.read<GLint>();
				GL_CHECK(glProgramUniform3i(program, location, v0, v1, v2));
				break;
			}
			case CommandId::ProgramUniform3iv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glProgramUniform3iv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform3f:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GLfloat v2 = m_Buffer.read<GLfloat>();
				GL_CHECK(glProgramUniform3f(program, location, v0, v1, v2));
				break;
			}
			case CommandId::ProgramUniform3fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniform3fv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform3d:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLdouble v0 = m_Buffer.read<GLdouble>();
				GLdouble v1 = m_Buffer.read<GLdouble>();
				GLdouble v2 = m_Buffer.read<GLdouble>();
				GL_CHECK(glProgramUniform3d(program, location, v0, v1, v2));
				break;
			}
			case CommandId::ProgramUniform3dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniform3dv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform3ui:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GLuint v2 = m_Buffer.read<GLuint>();
				GL_CHECK(glProgramUniform3ui(program, location, v0, v1, v2));
				break;
			}
			case CommandId::ProgramUniform3uiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glProgramUniform3uiv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform4i:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLint v0 = m_Buffer.read<GLint>();
				GLint v1 = m_Buffer.read<GLint>();
				GLint v2 = m_Buffer.read<GLint>();
				GLint v3 = m_Buffer.read<GLint>();
				GL_CHECK(glProgramUniform4i(program, location, v0, v1, v2, v3));
				break;
			}
			case CommandId::ProgramUniform4iv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glProgramUniform4iv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform4f:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLfloat v0 = m_Buffer.read<GLfloat>();
				GLfloat v1 = m_Buffer.read<GLfloat>();
				GLfloat v2 = m_Buffer.read<GLfloat>();
				GLfloat v3 = m_Buffer.read<GLfloat>();
				GL_CHECK(glProgramUniform4f(program, location, v0, v1, v2, v3));
				break;
			}
			case CommandId::ProgramUniform4fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniform4fv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform4d:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLdouble v0 = m_Buffer.read<GLdouble>();
				GLdouble v1 = m_Buffer.read<GLdouble>();
				GLdouble v2 = m_Buffer.read<GLdouble>();
				GLdouble v3 = m_Buffer.read<GLdouble>();
				GL_CHECK(glProgramUniform4d(program, location, v0, v1, v2, v3));
				break;
			}
			case CommandId::ProgramUniform4dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniform4dv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniform4ui:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLuint v0 = m_Buffer.read<GLuint>();
				GLuint v1 = m_Buffer.read<GLuint>();
				GLuint v2 = m_Buffer.read<GLuint>();
				GLuint v3 = m_Buffer.read<GLuint>();
				GL_CHECK(glProgramUniform4ui(program, location, v0, v1, v2, v3));
				break;
			}
			case CommandId::ProgramUniform4uiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glProgramUniform4uiv(program, location, count, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix2fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix3fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix4fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix2dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix3dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix4dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2x3fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix2x3fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3x2fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix3x2fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2x4fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix2x4fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4x2fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix4x2fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3x4fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix3x4fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4x3fv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glProgramUniformMatrix4x3fv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2x3dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix2x3dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3x2dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix3x2dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix2x4dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix2x4dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4x2dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix4x2dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix3x4dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix3x4dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ProgramUniformMatrix4x3dv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLboolean transpose = m_Buffer.read<GLboolean>();
				const GLdouble * value = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glProgramUniformMatrix4x3dv(program, location, count, transpose, value));
				break;
			}
			case CommandId::ValidateProgramPipeline:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				GL_CHECK(glValidateProgramPipeline(pipeline));
				break;
			}
			case CommandId::GetProgramPipelineInfoLog:
			{
				GLuint pipeline = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * infoLog = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetProgramPipelineInfoLog(pipeline, bufSize, length, infoLog));
				break;
			}
			case CommandId::VertexAttribL1d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttribL1d(index, x));
				break;
			}
			case CommandId::VertexAttribL2d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttribL2d(index, x, y));
				break;
			}
			case CommandId::VertexAttribL3d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttribL3d(index, x, y, z));
				break;
			}
			case CommandId::VertexAttribL4d:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble x = m_Buffer.read<GLdouble>();
				GLdouble y = m_Buffer.read<GLdouble>();
				GLdouble z = m_Buffer.read<GLdouble>();
				GLdouble w = m_Buffer.read<GLdouble>();
				GL_CHECK(glVertexAttribL4d(index, x, y, z, w));
				break;
			}
			case CommandId::VertexAttribL1dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttribL1dv(index, v));
				break;
			}
			case CommandId::VertexAttribL2dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttribL2dv(index, v));
				break;
			}
			case CommandId::VertexAttribL3dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttribL3dv(index, v));
				break;
			}
			case CommandId::VertexAttribL4dv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glVertexAttribL4dv(index, v));
				break;
			}
			case CommandId::VertexAttribLPointer:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribPointerType type = m_Buffer.read<multigl::VertexAttribPointerType>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				const void * pointer = m_Buffer.read<const void *>();
				GL_CHECK(glVertexAttribLPointer(index, size, type, stride, pointer));
				break;
			}
			case CommandId::GetVertexAttribLdv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexAttribEnum pname = m_Buffer.read<multigl::VertexAttribEnum>();
				GLdouble * params = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetVertexAttribLdv(index, pname, params));
				break;
			}
			case CommandId::ViewportArrayv:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glViewportArrayv(first, count, v));
				break;
			}
			case CommandId::ViewportIndexedf:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat x = m_Buffer.read<GLfloat>();
				GLfloat y = m_Buffer.read<GLfloat>();
				GLfloat w = m_Buffer.read<GLfloat>();
				GLfloat h = m_Buffer.read<GLfloat>();
				GL_CHECK(glViewportIndexedf(index, x, y, w, h));
				break;
			}
			case CommandId::ViewportIndexedfv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLfloat * v = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glViewportIndexedfv(index, v));
				break;
			}
			case CommandId::ScissorArrayv:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glScissorArrayv(first, count, v));
				break;
			}
			case CommandId::ScissorIndexed:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLint left = m_Buffer.read<GLint>();
				GLint bottom = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glScissorIndexed(index, left, bottom, width, height));
				break;
			}
			case CommandId::ScissorIndexedv:
			{
				GLuint index = m_Buffer.read<GLuint>();
				const GLint * v = m_Buffer.read<const GLint *>();
				GL_CHECK(glScissorIndexedv(index, v));
				break;
			}
			case CommandId::DepthRangeArrayv:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLdouble * v = m_Buffer.read<const GLdouble *>();
				GL_CHECK(glDepthRangeArrayv(first, count, v));
				break;
			}
			case CommandId::DepthRangeIndexed:
			{
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble n = m_Buffer.read<GLdouble>();
				GLdouble f = m_Buffer.read<GLdouble>();
				GL_CHECK(glDepthRangeIndexed(index, n, f));
				break;
			}
			case CommandId::GetFloati_v:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GLfloat * data = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetFloati_v(target, index, data));
				break;
			}
			case CommandId::GetDoublei_v:
			{
				GLenum target = m_Buffer.read<GLenum>();
				GLuint index = m_Buffer.read<GLuint>();
				GLdouble * data = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetDoublei_v(target, index, data));
				break;
			}
			case CommandId::DrawArraysInstancedBaseInstance:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLint first = m_Buffer.read<GLint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GLuint baseinstance = m_Buffer.read<GLuint>();
				GL_CHECK(glDrawArraysInstancedBaseInstance(mode, first, count, instancecount, baseinstance));
				break;
			}
			case CommandId::DrawElementsInstancedBaseInstance:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::PrimitiveType type = m_Buffer.read<multigl::PrimitiveType>();
				const void * indices = m_Buffer.read<const void *>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GLuint baseinstance = m_Buffer.read<GLuint>();
				GL_CHECK(glDrawElementsInstancedBaseInstance(mode, count, type, indices, instancecount, baseinstance));
				break;
			}
			case CommandId::DrawElementsInstancedBaseVertexBaseInstance:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLsizei count = m_Buffer.read<GLsizei>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indices = m_Buffer.read<const void *>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GLint basevertex = m_Buffer.read<GLint>();
				GLuint baseinstance = m_Buffer.read<GLuint>();
				GL_CHECK(glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, instancecount, basevertex, baseinstance));
				break;
			}
			case CommandId::GetInternalformativ:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				multigl::InternalFormatPName pname = m_Buffer.read<multigl::InternalFormatPName>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetInternalformativ(target, internalformat, pname, count, params));
				break;
			}
			case CommandId::GetActiveAtomicCounterBufferiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint bufferIndex = m_Buffer.read<GLuint>();
				multigl::AtomicCounterBufferPName pname = m_Buffer.read<multigl::AtomicCounterBufferPName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetActiveAtomicCounterBufferiv(program, bufferIndex, pname, params));
				break;
			}
			case CommandId::BindImageTexture:
			{
				GLuint unit = m_Buffer.read<GLuint>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLboolean layered = m_Buffer.read<GLboolean>();
				GLint layer = m_Buffer.read<GLint>();
				multigl::BufferAccessARB access = m_Buffer.read<multigl::BufferAccessARB>();
				multigl::InternalFormat format = m_Buffer.read<multigl::InternalFormat>();
				GL_CHECK(glBindImageTexture(unit, texture, level, layered, layer, access, format));
				break;
			}
			case CommandId::MemoryBarrier:
			{
				GLbitfield barriers = m_Buffer.read<GLbitfield>();
				GL_CHECK(glMemoryBarrier(barriers));
				break;
			}
			case CommandId::TexStorage1D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GL_CHECK(glTexStorage1D(target, levels, internalformat, width));
				break;
			}
			case CommandId::TexStorage2D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glTexStorage2D(target, levels, internalformat, width, height));
				break;
			}
			case CommandId::TexStorage3D:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GL_CHECK(glTexStorage3D(target, levels, internalformat, width, height, depth));
				break;
			}
			case CommandId::DrawTransformFeedbackInstanced:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint id = m_Buffer.read<GLuint>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GL_CHECK(glDrawTransformFeedbackInstanced(mode, id, instancecount));
				break;
			}
			case CommandId::DrawTransformFeedbackStreamInstanced:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				GLuint id = m_Buffer.read<GLuint>();
				GLuint stream = m_Buffer.read<GLuint>();
				GLsizei instancecount = m_Buffer.read<GLsizei>();
				GL_CHECK(glDrawTransformFeedbackStreamInstanced(mode, id, stream, instancecount));
				break;
			}
			case CommandId::ClearBufferData:
			{
				multigl::BufferStorageTarget target = m_Buffer.read<multigl::BufferStorageTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearBufferData(target, internalformat, format, type, data));
				break;
			}
			case CommandId::ClearBufferSubData:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearBufferSubData(target, internalformat, offset, size, format, type, data));
				break;
			}
			case CommandId::DispatchCompute:
			{
				GLuint num_groups_x = m_Buffer.read<GLuint>();
				GLuint num_groups_y = m_Buffer.read<GLuint>();
				GLuint num_groups_z = m_Buffer.read<GLuint>();
				GL_CHECK(glDispatchCompute(num_groups_x, num_groups_y, num_groups_z));
				break;
			}
			case CommandId::DispatchComputeIndirect:
			{
				GLintptr indirect = m_Buffer.read<GLintptr>();
				GL_CHECK(glDispatchComputeIndirect(indirect));
				break;
			}
			case CommandId::CopyImageSubData:
			{
				GLuint srcName = m_Buffer.read<GLuint>();
				multigl::CopyImageSubDataTarget srcTarget = m_Buffer.read<multigl::CopyImageSubDataTarget>();
				GLint srcLevel = m_Buffer.read<GLint>();
				GLint srcX = m_Buffer.read<GLint>();
				GLint srcY = m_Buffer.read<GLint>();
				GLint srcZ = m_Buffer.read<GLint>();
				GLuint dstName = m_Buffer.read<GLuint>();
				multigl::CopyImageSubDataTarget dstTarget = m_Buffer.read<multigl::CopyImageSubDataTarget>();
				GLint dstLevel = m_Buffer.read<GLint>();
				GLint dstX = m_Buffer.read<GLint>();
				GLint dstY = m_Buffer.read<GLint>();
				GLint dstZ = m_Buffer.read<GLint>();
				GLsizei srcWidth = m_Buffer.read<GLsizei>();
				GLsizei srcHeight = m_Buffer.read<GLsizei>();
				GLsizei srcDepth = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth));
				break;
			}
			case CommandId::FramebufferParameteri:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferParameterName pname = m_Buffer.read<multigl::FramebufferParameterName>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glFramebufferParameteri(target, pname, param));
				break;
			}
			case CommandId::GetFramebufferParameteriv:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				multigl::FramebufferAttachmentParameterName pname = m_Buffer.read<multigl::FramebufferAttachmentParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetFramebufferParameteriv(target, pname, params));
				break;
			}
			case CommandId::GetInternalformati64v:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				multigl::InternalFormatPName pname = m_Buffer.read<multigl::InternalFormatPName>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLint64 * params = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetInternalformati64v(target, internalformat, pname, count, params));
				break;
			}
			case CommandId::InvalidateTexSubImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GL_CHECK(glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth));
				break;
			}
			case CommandId::InvalidateTexImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GL_CHECK(glInvalidateTexImage(texture, level));
				break;
			}
			case CommandId::InvalidateBufferSubData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr length = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glInvalidateBufferSubData(buffer, offset, length));
				break;
			}
			case CommandId::InvalidateBufferData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glInvalidateBufferData(buffer));
				break;
			}
			case CommandId::InvalidateFramebuffer:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				GLsizei numAttachments = m_Buffer.read<GLsizei>();
				const GLenum * attachments = m_Buffer.read<const GLenum *>();
				GL_CHECK(glInvalidateFramebuffer(target, numAttachments, attachments));
				break;
			}
			case CommandId::InvalidateSubFramebuffer:
			{
				multigl::FramebufferTarget target = m_Buffer.read<multigl::FramebufferTarget>();
				GLsizei numAttachments = m_Buffer.read<GLsizei>();
				const GLenum * attachments = m_Buffer.read<const GLenum *>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height));
				break;
			}
			case CommandId::MultiDrawArraysIndirect:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				const void * indirect = m_Buffer.read<const void *>();
				GLsizei drawcount = m_Buffer.read<GLsizei>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				GL_CHECK(glMultiDrawArraysIndirect(mode, indirect, drawcount, stride));
				break;
			}
			case CommandId::MultiDrawElementsIndirect:
			{
				multigl::PrimitiveType mode = m_Buffer.read<multigl::PrimitiveType>();
				multigl::DrawElementsType type = m_Buffer.read<multigl::DrawElementsType>();
				const void * indirect = m_Buffer.read<const void *>();
				GLsizei drawcount = m_Buffer.read<GLsizei>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				GL_CHECK(glMultiDrawElementsIndirect(mode, type, indirect, drawcount, stride));
				break;
			}
			case CommandId::GetProgramInterfaceiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ProgramInterface programInterface = m_Buffer.read<multigl::ProgramInterface>();
				multigl::ProgramInterfacePName pname = m_Buffer.read<multigl::ProgramInterfacePName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetProgramInterfaceiv(program, programInterface, pname, params));
				break;
			}
			case CommandId::GetProgramResourceName:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ProgramInterface programInterface = m_Buffer.read<multigl::ProgramInterface>();
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * name = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetProgramResourceName(program, programInterface, index, bufSize, length, name));
				break;
			}
			case CommandId::GetProgramResourceiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				multigl::ProgramInterface programInterface = m_Buffer.read<multigl::ProgramInterface>();
				GLuint index = m_Buffer.read<GLuint>();
				GLsizei propCount = m_Buffer.read<GLsizei>();
				const GLenum * props = m_Buffer.read<const GLenum *>();
				GLsizei count = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetProgramResourceiv(program, programInterface, index, propCount, props, count, length, params));
				break;
			}
			case CommandId::ShaderStorageBlockBinding:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLuint storageBlockIndex = m_Buffer.read<GLuint>();
				GLuint storageBlockBinding = m_Buffer.read<GLuint>();
				GL_CHECK(glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding));
				break;
			}
			case CommandId::TexBufferRange:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glTexBufferRange(target, internalformat, buffer, offset, size));
				break;
			}
			case CommandId::TexStorage2DMultisample:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTexStorage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations));
				break;
			}
			case CommandId::TexStorage3DMultisample:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTexStorage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations));
				break;
			}
			case CommandId::TextureView:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLuint origtexture = m_Buffer.read<GLuint>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLuint minlevel = m_Buffer.read<GLuint>();
				GLuint numlevels = m_Buffer.read<GLuint>();
				GLuint minlayer = m_Buffer.read<GLuint>();
				GLuint numlayers = m_Buffer.read<GLuint>();
				GL_CHECK(glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers));
				break;
			}
			case CommandId::BindVertexBuffer:
			{
				GLuint bindingindex = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				GL_CHECK(glBindVertexBuffer(bindingindex, buffer, offset, stride));
				break;
			}
			case CommandId::VertexAttribFormat:
			{
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribType type = m_Buffer.read<multigl::VertexAttribType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset));
				break;
			}
			case CommandId::VertexAttribIFormat:
			{
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribIType type = m_Buffer.read<multigl::VertexAttribIType>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribIFormat(attribindex, size, type, relativeoffset));
				break;
			}
			case CommandId::VertexAttribLFormat:
			{
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribLType type = m_Buffer.read<multigl::VertexAttribLType>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribLFormat(attribindex, size, type, relativeoffset));
				break;
			}
			case CommandId::VertexAttribBinding:
			{
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLuint bindingindex = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexAttribBinding(attribindex, bindingindex));
				break;
			}
			case CommandId::VertexBindingDivisor:
			{
				GLuint bindingindex = m_Buffer.read<GLuint>();
				GLuint divisor = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexBindingDivisor(bindingindex, divisor));
				break;
			}
			case CommandId::DebugMessageControl:
			{
				multigl::DebugSource source = m_Buffer.read<multigl::DebugSource>();
				multigl::DebugType type = m_Buffer.read<multigl::DebugType>();
				multigl::DebugSeverity severity = m_Buffer.read<multigl::DebugSeverity>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * ids = m_Buffer.read<const GLuint *>();
				GLboolean enabled = m_Buffer.read<GLboolean>();
				GL_CHECK(glDebugMessageControl(source, type, severity, count, ids, enabled));
				break;
			}
			case CommandId::DebugMessageInsert:
			{
				multigl::DebugSource source = m_Buffer.read<multigl::DebugSource>();
				multigl::DebugType type = m_Buffer.read<multigl::DebugType>();
				GLuint id = m_Buffer.read<GLuint>();
				multigl::DebugSeverity severity = m_Buffer.read<multigl::DebugSeverity>();
				GLsizei length = m_Buffer.read<GLsizei>();
				const GLchar * buf = m_Buffer.read<const GLchar *>();
				GL_CHECK(glDebugMessageInsert(source, type, id, severity, length, buf));
				break;
			}
			case CommandId::DebugMessageCallback:
			{
				GLDEBUGPROC callback = m_Buffer.read<GLDEBUGPROC>();
				const void * userParam = m_Buffer.read<const void *>();
				GL_CHECK(glDebugMessageCallback(callback, userParam));
				break;
			}
			case CommandId::PushDebugGroup:
			{
				multigl::DebugSource source = m_Buffer.read<multigl::DebugSource>();
				GLuint id = m_Buffer.read<GLuint>();
				GLsizei length = m_Buffer.read<GLsizei>();
				const GLchar * message = m_Buffer.read<const GLchar *>();
				GL_CHECK(glPushDebugGroup(source, id, length, message));
				break;
			}
			case CommandId::PopDebugGroup:
			{
				GL_CHECK(glPopDebugGroup());
				break;
			}
			case CommandId::ObjectLabel:
			{
				multigl::ObjectIdentifier identifier = m_Buffer.read<multigl::ObjectIdentifier>();
				GLuint name = m_Buffer.read<GLuint>();
				GLsizei length = m_Buffer.read<GLsizei>();
				const GLchar * label = m_Buffer.read<const GLchar *>();
				GL_CHECK(glObjectLabel(identifier, name, length, label));
				break;
			}
			case CommandId::GetObjectLabel:
			{
				multigl::ObjectIdentifier identifier = m_Buffer.read<multigl::ObjectIdentifier>();
				GLuint name = m_Buffer.read<GLuint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * label = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetObjectLabel(identifier, name, bufSize, length, label));
				break;
			}
			case CommandId::ObjectPtrLabel:
			{
				const void * ptr = m_Buffer.read<const void *>();
				GLsizei length = m_Buffer.read<GLsizei>();
				const GLchar * label = m_Buffer.read<const GLchar *>();
				GL_CHECK(glObjectPtrLabel(ptr, length, label));
				break;
			}
			case CommandId::GetObjectPtrLabel:
			{
				const void * ptr = m_Buffer.read<const void *>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLsizei * length = m_Buffer.read<GLsizei *>();
				GLchar * label = m_Buffer.read<GLchar *>();
				GL_CHECK(glGetObjectPtrLabel(ptr, bufSize, length, label));
				break;
			}
			case CommandId::GetPointerv:
			{
				multigl::GetPointervPName pname = m_Buffer.read<multigl::GetPointervPName>();
				void ** params = m_Buffer.read<void **>();
				GL_CHECK(glGetPointerv(pname, params));
				break;
			}
			case CommandId::BufferStorage:
			{
				multigl::BufferStorageTarget target = m_Buffer.read<multigl::BufferStorageTarget>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				GLbitfield flags = m_Buffer.read<GLbitfield>();
				GL_CHECK(glBufferStorage(target, size, data, flags));
				break;
			}
			case CommandId::ClearTexImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearTexImage(texture, level, format, type, data));
				break;
			}
			case CommandId::ClearTexSubImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data));
				break;
			}
			case CommandId::BindBuffersBase:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * buffers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glBindBuffersBase(target, first, count, buffers));
				break;
			}
			case CommandId::BindBuffersRange:
			{
				multigl::BufferTarget target = m_Buffer.read<multigl::BufferTarget>();
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * buffers = m_Buffer.read<const GLuint *>();
				const GLintptr * offsets = m_Buffer.read<const GLintptr *>();
				const GLsizeiptr * sizes = m_Buffer.read<const GLsizeiptr *>();
				GL_CHECK(glBindBuffersRange(target, first, count, buffers, offsets, sizes));
				break;
			}
			case CommandId::BindTextures:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * textures = m_Buffer.read<const GLuint *>();
				GL_CHECK(glBindTextures(first, count, textures));
				break;
			}
			case CommandId::BindSamplers:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * samplers = m_Buffer.read<const GLuint *>();
				GL_CHECK(glBindSamplers(first, count, samplers));
				break;
			}
			case CommandId::BindImageTextures:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * textures = m_Buffer.read<const GLuint *>();
				GL_CHECK(glBindImageTextures(first, count, textures));
				break;
			}
			case CommandId::BindVertexBuffers:
			{
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * buffers = m_Buffer.read<const GLuint *>();
				const GLintptr * offsets = m_Buffer.read<const GLintptr *>();
				const GLsizei * strides = m_Buffer.read<const GLsizei *>();
				GL_CHECK(glBindVertexBuffers(first, count, buffers, offsets, strides));
				break;
			}
			case CommandId::ClipControl:
			{
				multigl::ClipControlOrigin origin = m_Buffer.read<multigl::ClipControlOrigin>();
				multigl::ClipControlDepth depth = m_Buffer.read<multigl::ClipControlDepth>();
				GL_CHECK(glClipControl(origin, depth));
				break;
			}
			case CommandId::CreateTransformFeedbacks:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * ids = m_Buffer.read<GLuint *>();
				GL_CHECK(glCreateTransformFeedbacks(n, ids));
				break;
			}
			case CommandId::TransformFeedbackBufferBase:
			{
				GLuint xfb = m_Buffer.read<GLuint>();
				GLuint index = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glTransformFeedbackBufferBase(xfb, index, buffer));
				break;
			}
			case CommandId::TransformFeedbackBufferRange:
			{
				GLuint xfb = m_Buffer.read<GLuint>();
				GLuint index = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glTransformFeedbackBufferRange(xfb, index, buffer, offset, size));
				break;
			}
			case CommandId::GetTransformFeedbackiv:
			{
				GLuint xfb = m_Buffer.read<GLuint>();
				multigl::TransformFeedbackPName pname = m_Buffer.read<multigl::TransformFeedbackPName>();
				GLint * param = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTransformFeedbackiv(xfb, pname, param));
				break;
			}
			case CommandId::GetTransformFeedbacki_v:
			{
				GLuint xfb = m_Buffer.read<GLuint>();
				multigl::TransformFeedbackPName pname = m_Buffer.read<multigl::TransformFeedbackPName>();
				GLuint index = m_Buffer.read<GLuint>();
				GLint * param = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTransformFeedbacki_v(xfb, pname, index, param));
				break;
			}
			case CommandId::GetTransformFeedbacki64_v:
			{
				GLuint xfb = m_Buffer.read<GLuint>();
				multigl::TransformFeedbackPName pname = m_Buffer.read<multigl::TransformFeedbackPName>();
				GLuint index = m_Buffer.read<GLuint>();
				GLint64 * param = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetTransformFeedbacki64_v(xfb, pname, index, param));
				break;
			}
			case CommandId::CreateBuffer:
			{
				auto handle = m_Buffer.read<BufferHandle>();
				auto& target = *m_ResourceManager.Buffers.get(handle);
				glCreateBuffers(1, &target);
				break;
			}
			case CommandId::NamedBufferStorage:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				GLbitfield flags = m_Buffer.read<GLbitfield>();
				GL_CHECK(glNamedBufferStorage(buffer, size, data, flags));
				break;
			}
			case CommandId::NamedBufferData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				multigl::VertexBufferObjectUsage usage = m_Buffer.read<multigl::VertexBufferObjectUsage>();
				GL_CHECK(glNamedBufferData(buffer, size, data, usage));
				break;
			}
			case CommandId::NamedBufferSubData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glNamedBufferSubData(buffer, offset, size, data));
				break;
			}
			case CommandId::CopyNamedBufferSubData:
			{
				GLuint readBuffer = m_Buffer.read<GLuint>();
				GLuint writeBuffer = m_Buffer.read<GLuint>();
				GLintptr readOffset = m_Buffer.read<GLintptr>();
				GLintptr writeOffset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size));
				break;
			}
			case CommandId::ClearNamedBufferData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearNamedBufferData(buffer, internalformat, format, type, data));
				break;
			}
			case CommandId::ClearNamedBufferSubData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data));
				break;
			}
			case CommandId::FlushMappedNamedBufferRange:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr length = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glFlushMappedNamedBufferRange(buffer, offset, length));
				break;
			}
			case CommandId::GetNamedBufferParameteriv:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::VertexBufferObjectParameter pname = m_Buffer.read<multigl::VertexBufferObjectParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetNamedBufferParameteriv(buffer, pname, params));
				break;
			}
			case CommandId::GetNamedBufferParameteri64v:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::VertexBufferObjectParameter pname = m_Buffer.read<multigl::VertexBufferObjectParameter>();
				GLint64 * params = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetNamedBufferParameteri64v(buffer, pname, params));
				break;
			}
			case CommandId::GetNamedBufferPointerv:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::VertexBufferObjectParameter pname = m_Buffer.read<multigl::VertexBufferObjectParameter>();
				void ** params = m_Buffer.read<void **>();
				GL_CHECK(glGetNamedBufferPointerv(buffer, pname, params));
				break;
			}
			case CommandId::GetNamedBufferSubData:
			{
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				void * data = m_Buffer.read<void *>();
				GL_CHECK(glGetNamedBufferSubData(buffer, offset, size, data));
				break;
			}
			case CommandId::CreateFramebuffer:
			{
				auto handle = m_Buffer.read<FramebufferHandle>();
				auto& target = *m_ResourceManager.Framebuffers.get(handle);
				glCreateFramebuffers(1, &target);
				break;
			}
			case CommandId::NamedFramebufferRenderbuffer:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::RenderbufferTarget renderbuffertarget = m_Buffer.read<multigl::RenderbufferTarget>();
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				GL_CHECK(glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer));
				break;
			}
			case CommandId::NamedFramebufferParameteri:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::FramebufferParameterName pname = m_Buffer.read<multigl::FramebufferParameterName>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glNamedFramebufferParameteri(framebuffer, pname, param));
				break;
			}
			case CommandId::NamedFramebufferTexture:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GL_CHECK(glNamedFramebufferTexture(framebuffer, attachment, texture, level));
				break;
			}
			case CommandId::NamedFramebufferTextureLayer:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint layer = m_Buffer.read<GLint>();
				GL_CHECK(glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer));
				break;
			}
			case CommandId::NamedFramebufferDrawBuffer:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::ColorBuffer buf = m_Buffer.read<multigl::ColorBuffer>();
				GL_CHECK(glNamedFramebufferDrawBuffer(framebuffer, buf));
				break;
			}
			case CommandId::NamedFramebufferDrawBuffers:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GLsizei n = m_Buffer.read<GLsizei>();
				const GLenum * bufs = m_Buffer.read<const GLenum *>();
				GL_CHECK(glNamedFramebufferDrawBuffers(framebuffer, n, bufs));
				break;
			}
			case CommandId::NamedFramebufferReadBuffer:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::ColorBuffer src = m_Buffer.read<multigl::ColorBuffer>();
				GL_CHECK(glNamedFramebufferReadBuffer(framebuffer, src));
				break;
			}
			case CommandId::InvalidateNamedFramebufferData:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GLsizei numAttachments = m_Buffer.read<GLsizei>();
				const GLenum * attachments = m_Buffer.read<const GLenum *>();
				GL_CHECK(glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments));
				break;
			}
			case CommandId::InvalidateNamedFramebufferSubData:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				GLsizei numAttachments = m_Buffer.read<GLsizei>();
				const GLenum * attachments = m_Buffer.read<const GLenum *>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height));
				break;
			}
			case CommandId::ClearNamedFramebufferiv:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLint * value = m_Buffer.read<const GLint *>();
				GL_CHECK(glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearNamedFramebufferuiv:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLuint * value = m_Buffer.read<const GLuint *>();
				GL_CHECK(glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearNamedFramebufferfv:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				const GLfloat * value = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value));
				break;
			}
			case CommandId::ClearNamedFramebufferfi:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLint drawbuffer = m_Buffer.read<GLint>();
				GLfloat depth = m_Buffer.read<GLfloat>();
				GLint stencil = m_Buffer.read<GLint>();
				GL_CHECK(glClearNamedFramebufferfi(framebuffer, buffer, drawbuffer, depth, stencil));
				break;
			}
			case CommandId::BlitNamedFramebuffer:
			{
				GLuint readFramebuffer = m_Buffer.read<GLuint>();
				GLuint drawFramebuffer = m_Buffer.read<GLuint>();
				GLint srcX0 = m_Buffer.read<GLint>();
				GLint srcY0 = m_Buffer.read<GLint>();
				GLint srcX1 = m_Buffer.read<GLint>();
				GLint srcY1 = m_Buffer.read<GLint>();
				GLint dstX0 = m_Buffer.read<GLint>();
				GLint dstY0 = m_Buffer.read<GLint>();
				GLint dstX1 = m_Buffer.read<GLint>();
				GLint dstY1 = m_Buffer.read<GLint>();
				GLbitfield mask = m_Buffer.read<GLbitfield>();
				multigl::BlitFramebufferFilter filter = m_Buffer.read<multigl::BlitFramebufferFilter>();
				GL_CHECK(glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter));
				break;
			}
			case CommandId::GetNamedFramebufferParameteriv:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::GetFramebufferParameter pname = m_Buffer.read<multigl::GetFramebufferParameter>();
				GLint * param = m_Buffer.read<GLint *>();
				GL_CHECK(glGetNamedFramebufferParameteriv(framebuffer, pname, param));
				break;
			}
			case CommandId::GetNamedFramebufferAttachmentParameteriv:
			{
				FramebufferHandle framebufferHandle = m_Buffer.read<FramebufferHandle>();
				auto& framebuffer = *m_ResourceManager.Framebuffers.get(framebufferHandle);
				multigl::FramebufferAttachment attachment = m_Buffer.read<multigl::FramebufferAttachment>();
				multigl::FramebufferAttachmentParameterName pname = m_Buffer.read<multigl::FramebufferAttachmentParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetNamedFramebufferAttachmentParameteriv(framebuffer, attachment, pname, params));
				break;
			}
			case CommandId::CreateRenderbuffer:
			{
				auto handle = m_Buffer.read<RenderbufferHandle>();
				auto& target = *m_ResourceManager.Renderbuffers.get(handle);
				glCreateRenderbuffers(1, &target);
				break;
			}
			case CommandId::NamedRenderbufferStorage:
			{
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glNamedRenderbufferStorage(renderbuffer, internalformat, width, height));
				break;
			}
			case CommandId::NamedRenderbufferStorageMultisample:
			{
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height));
				break;
			}
			case CommandId::GetNamedRenderbufferParameteriv:
			{
				RenderbufferHandle renderbufferHandle = m_Buffer.read<RenderbufferHandle>();
				auto& renderbuffer = *m_ResourceManager.Renderbuffers.get(renderbufferHandle);
				multigl::RenderbufferParameterName pname = m_Buffer.read<multigl::RenderbufferParameterName>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetNamedRenderbufferParameteriv(renderbuffer, pname, params));
				break;
			}
			case CommandId::CreateTexture:
			{
				auto target = m_Buffer.read<TextureTarget>();
				auto handle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(handle);
				glCreateTextures(target, 1, &texture);
				break;
			}
			case CommandId::TextureBuffer:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glTextureBuffer(texture, internalformat, buffer));
				break;
			}
			case CommandId::TextureBufferRange:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizeiptr size = m_Buffer.read<GLsizeiptr>();
				GL_CHECK(glTextureBufferRange(texture, internalformat, buffer, offset, size));
				break;
			}
			case CommandId::TextureStorage1D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GL_CHECK(glTextureStorage1D(texture, levels, internalformat, width));
				break;
			}
			case CommandId::TextureStorage2D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glTextureStorage2D(texture, levels, internalformat, width, height));
				break;
			}
			case CommandId::TextureStorage3D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLsizei levels = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GL_CHECK(glTextureStorage3D(texture, levels, internalformat, width, height, depth));
				break;
			}
			case CommandId::TextureStorage2DMultisample:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTextureStorage2DMultisample(texture, samples, internalformat, width, height, fixedsamplelocations));
				break;
			}
			case CommandId::TextureStorage3DMultisample:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLsizei samples = m_Buffer.read<GLsizei>();
				multigl::InternalFormat internalformat = m_Buffer.read<multigl::InternalFormat>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLboolean fixedsamplelocations = m_Buffer.read<GLboolean>();
				GL_CHECK(glTextureStorage3DMultisample(texture, samples, internalformat, width, height, depth, fixedsamplelocations));
				break;
			}
			case CommandId::TextureSubImage1D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTextureSubImage1D(texture, level, xoffset, width, format, type, pixels));
				break;
			}
			case CommandId::TextureSubImage2D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, type, pixels));
				break;
			}
			case CommandId::TextureSubImage3D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				const void * pixels = m_Buffer.read<const void *>();
				GL_CHECK(glTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
				break;
			}
			case CommandId::CompressedTextureSubImage1D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTextureSubImage1D(texture, level, xoffset, width, format, imageSize, data));
				break;
			}
			case CommandId::CompressedTextureSubImage2D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTextureSubImage2D(texture, level, xoffset, yoffset, width, height, format, imageSize, data));
				break;
			}
			case CommandId::CompressedTextureSubImage3D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				GLsizei imageSize = m_Buffer.read<GLsizei>();
				const void * data = m_Buffer.read<const void *>();
				GL_CHECK(glCompressedTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
				break;
			}
			case CommandId::CopyTextureSubImage1D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTextureSubImage1D(texture, level, xoffset, x, y, width));
				break;
			}
			case CommandId::CopyTextureSubImage2D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTextureSubImage2D(texture, level, xoffset, yoffset, x, y, width, height));
				break;
			}
			case CommandId::CopyTextureSubImage3D:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GL_CHECK(glCopyTextureSubImage3D(texture, level, xoffset, yoffset, zoffset, x, y, width, height));
				break;
			}
			case CommandId::TextureParameterf:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				GLfloat param = m_Buffer.read<GLfloat>();
				GL_CHECK(glTextureParameterf(texture, pname, param));
				break;
			}
			case CommandId::TextureParameterfv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLfloat * param = m_Buffer.read<const GLfloat *>();
				GL_CHECK(glTextureParameterfv(texture, pname, param));
				break;
			}
			case CommandId::TextureParameteri:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				GLint param = m_Buffer.read<GLint>();
				GL_CHECK(glTextureParameteri(texture, pname, param));
				break;
			}
			case CommandId::TextureParameterIiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLint * params = m_Buffer.read<const GLint *>();
				GL_CHECK(glTextureParameterIiv(texture, pname, params));
				break;
			}
			case CommandId::TextureParameterIuiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLuint * params = m_Buffer.read<const GLuint *>();
				GL_CHECK(glTextureParameterIuiv(texture, pname, params));
				break;
			}
			case CommandId::TextureParameteriv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::TextureParameterName pname = m_Buffer.read<multigl::TextureParameterName>();
				const GLint * param = m_Buffer.read<const GLint *>();
				GL_CHECK(glTextureParameteriv(texture, pname, param));
				break;
			}
			case CommandId::GenerateTextureMipmap:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GL_CHECK(glGenerateTextureMipmap(texture));
				break;
			}
			case CommandId::BindTextureUnit:
			{
				GLuint unit = m_Buffer.read<GLuint>();
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GL_CHECK(glBindTextureUnit(unit, texture));
				break;
			}
			case CommandId::GetTextureImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetTextureImage(texture, level, format, type, bufSize, pixels));
				break;
			}
			case CommandId::GetCompressedTextureImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetCompressedTextureImage(texture, level, bufSize, pixels));
				break;
			}
			case CommandId::GetTextureLevelParameterfv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetTextureLevelParameterfv(texture, level, pname, params));
				break;
			}
			case CommandId::GetTextureLevelParameteriv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTextureLevelParameteriv(texture, level, pname, params));
				break;
			}
			case CommandId::GetTextureParameterfv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetTextureParameterfv(texture, pname, params));
				break;
			}
			case CommandId::GetTextureParameterIiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTextureParameterIiv(texture, pname, params));
				break;
			}
			case CommandId::GetTextureParameterIuiv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetTextureParameterIuiv(texture, pname, params));
				break;
			}
			case CommandId::GetTextureParameteriv:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				multigl::GetTextureParameter pname = m_Buffer.read<multigl::GetTextureParameter>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetTextureParameteriv(texture, pname, params));
				break;
			}
			case CommandId::CreateVertexArray:
			{
				auto handle = m_Buffer.read<VertexArrayHandle>();
				auto& target = *m_ResourceManager.VertexArrays.get(handle);
				glCreateVertexArrays(1, &target);
				break;
			}
			case CommandId::DisableVertexArrayAttrib:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glDisableVertexArrayAttrib(vaobj, index));
				break;
			}
			case CommandId::EnableVertexArrayAttrib:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint index = m_Buffer.read<GLuint>();
				GL_CHECK(glEnableVertexArrayAttrib(vaobj, index));
				break;
			}
			case CommandId::VertexArrayElementBuffer:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GL_CHECK(glVertexArrayElementBuffer(vaobj, buffer));
				break;
			}
			case CommandId::VertexArrayVertexBuffer:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint bindingindex = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				GLintptr offset = m_Buffer.read<GLintptr>();
				GLsizei stride = m_Buffer.read<GLsizei>();
				GL_CHECK(glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride));
				break;
			}
			case CommandId::VertexArrayVertexBuffers:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint first = m_Buffer.read<GLuint>();
				GLsizei count = m_Buffer.read<GLsizei>();
				const GLuint * buffers = m_Buffer.read<const GLuint *>();
				const GLintptr * offsets = m_Buffer.read<const GLintptr *>();
				const GLsizei * strides = m_Buffer.read<const GLsizei *>();
				GL_CHECK(glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides));
				break;
			}
			case CommandId::VertexArrayAttribBinding:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLuint bindingindex = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexArrayAttribBinding(vaobj, attribindex, bindingindex));
				break;
			}
			case CommandId::VertexArrayAttribFormat:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribType type = m_Buffer.read<multigl::VertexAttribType>();
				GLboolean normalized = m_Buffer.read<GLboolean>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset));
				break;
			}
			case CommandId::VertexArrayAttribIFormat:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribIType type = m_Buffer.read<multigl::VertexAttribIType>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset));
				break;
			}
			case CommandId::VertexArrayAttribLFormat:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint attribindex = m_Buffer.read<GLuint>();
				GLint size = m_Buffer.read<GLint>();
				multigl::VertexAttribLType type = m_Buffer.read<multigl::VertexAttribLType>();
				GLuint relativeoffset = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset));
				break;
			}
			case CommandId::VertexArrayBindingDivisor:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint bindingindex = m_Buffer.read<GLuint>();
				GLuint divisor = m_Buffer.read<GLuint>();
				GL_CHECK(glVertexArrayBindingDivisor(vaobj, bindingindex, divisor));
				break;
			}
			case CommandId::GetVertexArrayiv:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				multigl::VertexArrayPName pname = m_Buffer.read<multigl::VertexArrayPName>();
				GLint * param = m_Buffer.read<GLint *>();
				GL_CHECK(glGetVertexArrayiv(vaobj, pname, param));
				break;
			}
			case CommandId::GetVertexArrayIndexediv:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexArrayPName pname = m_Buffer.read<multigl::VertexArrayPName>();
				GLint * param = m_Buffer.read<GLint *>();
				GL_CHECK(glGetVertexArrayIndexediv(vaobj, index, pname, param));
				break;
			}
			case CommandId::GetVertexArrayIndexed64iv:
			{
				VertexArrayHandle vaobjHandle = m_Buffer.read<VertexArrayHandle>();
				auto& vaobj = *m_ResourceManager.VertexArrays.get(vaobjHandle);
				GLuint index = m_Buffer.read<GLuint>();
				multigl::VertexArrayPName pname = m_Buffer.read<multigl::VertexArrayPName>();
				GLint64 * param = m_Buffer.read<GLint64 *>();
				GL_CHECK(glGetVertexArrayIndexed64iv(vaobj, index, pname, param));
				break;
			}
			case CommandId::CreateSamplers:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * samplers = m_Buffer.read<GLuint *>();
				GL_CHECK(glCreateSamplers(n, samplers));
				break;
			}
			case CommandId::CreateProgramPipelines:
			{
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * pipelines = m_Buffer.read<GLuint *>();
				GL_CHECK(glCreateProgramPipelines(n, pipelines));
				break;
			}
			case CommandId::CreateQueries:
			{
				multigl::QueryTarget target = m_Buffer.read<multigl::QueryTarget>();
				GLsizei n = m_Buffer.read<GLsizei>();
				GLuint * ids = m_Buffer.read<GLuint *>();
				GL_CHECK(glCreateQueries(target, n, ids));
				break;
			}
			case CommandId::GetQueryBufferObjecti64v:
			{
				GLuint id = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GL_CHECK(glGetQueryBufferObjecti64v(id, buffer, pname, offset));
				break;
			}
			case CommandId::GetQueryBufferObjectiv:
			{
				GLuint id = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GL_CHECK(glGetQueryBufferObjectiv(id, buffer, pname, offset));
				break;
			}
			case CommandId::GetQueryBufferObjectui64v:
			{
				GLuint id = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GL_CHECK(glGetQueryBufferObjectui64v(id, buffer, pname, offset));
				break;
			}
			case CommandId::GetQueryBufferObjectuiv:
			{
				GLuint id = m_Buffer.read<GLuint>();
				BufferHandle bufferHandle = m_Buffer.read<BufferHandle>();
				auto& buffer = *m_ResourceManager.Buffers.get(bufferHandle);
				multigl::QueryObjectParameterName pname = m_Buffer.read<multigl::QueryObjectParameterName>();
				GLintptr offset = m_Buffer.read<GLintptr>();
				GL_CHECK(glGetQueryBufferObjectuiv(id, buffer, pname, offset));
				break;
			}
			case CommandId::MemoryBarrierByRegion:
			{
				GLbitfield barriers = m_Buffer.read<GLbitfield>();
				GL_CHECK(glMemoryBarrierByRegion(barriers));
				break;
			}
			case CommandId::GetTextureSubImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels));
				break;
			}
			case CommandId::GetCompressedTextureSubImage:
			{
				TextureHandle textureHandle = m_Buffer.read<TextureHandle>();
				auto& texture = *m_ResourceManager.Textures.get(textureHandle);
				GLint level = m_Buffer.read<GLint>();
				GLint xoffset = m_Buffer.read<GLint>();
				GLint yoffset = m_Buffer.read<GLint>();
				GLint zoffset = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				GLsizei depth = m_Buffer.read<GLsizei>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetCompressedTextureSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels));
				break;
			}
			case CommandId::GetnCompressedTexImage:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint lod = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetnCompressedTexImage(target, lod, bufSize, pixels));
				break;
			}
			case CommandId::GetnTexImage:
			{
				multigl::TextureTarget target = m_Buffer.read<multigl::TextureTarget>();
				GLint level = m_Buffer.read<GLint>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * pixels = m_Buffer.read<void *>();
				GL_CHECK(glGetnTexImage(target, level, format, type, bufSize, pixels));
				break;
			}
			case CommandId::GetnUniformdv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLdouble * params = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetnUniformdv(program, location, bufSize, params));
				break;
			}
			case CommandId::GetnUniformfv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLfloat * params = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetnUniformfv(program, location, bufSize, params));
				break;
			}
			case CommandId::GetnUniformiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLint * params = m_Buffer.read<GLint *>();
				GL_CHECK(glGetnUniformiv(program, location, bufSize, params));
				break;
			}
			case CommandId::GetnUniformuiv:
			{
				ShaderProgramHandle programHandle = m_Buffer.read<ShaderProgramHandle>();
				auto& program = *m_ResourceManager.ShaderPrograms.get(programHandle);
				GLint location = m_Buffer.read<GLint>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLuint * params = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetnUniformuiv(program, location, bufSize, params));
				break;
			}
			case CommandId::ReadnPixels:
			{
				GLint x = m_Buffer.read<GLint>();
				GLint y = m_Buffer.read<GLint>();
				GLsizei width = m_Buffer.read<GLsizei>();
				GLsizei height = m_Buffer.read<GLsizei>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * data = m_Buffer.read<void *>();
				GL_CHECK(glReadnPixels(x, y, width, height, format, type, bufSize, data));
				break;
			}
			case CommandId::GetnMapdv:
			{
				multigl::MapTarget target = m_Buffer.read<multigl::MapTarget>();
				multigl::MapQuery query = m_Buffer.read<multigl::MapQuery>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLdouble * v = m_Buffer.read<GLdouble *>();
				GL_CHECK(glGetnMapdv(target, query, bufSize, v));
				break;
			}
			case CommandId::GetnMapfv:
			{
				multigl::MapTarget target = m_Buffer.read<multigl::MapTarget>();
				multigl::MapQuery query = m_Buffer.read<multigl::MapQuery>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLfloat * v = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetnMapfv(target, query, bufSize, v));
				break;
			}
			case CommandId::GetnMapiv:
			{
				multigl::MapTarget target = m_Buffer.read<multigl::MapTarget>();
				multigl::MapQuery query = m_Buffer.read<multigl::MapQuery>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLint * v = m_Buffer.read<GLint *>();
				GL_CHECK(glGetnMapiv(target, query, bufSize, v));
				break;
			}
			case CommandId::GetnPixelMapfv:
			{
				multigl::PixelMap map = m_Buffer.read<multigl::PixelMap>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLfloat * values = m_Buffer.read<GLfloat *>();
				GL_CHECK(glGetnPixelMapfv(map, bufSize, values));
				break;
			}
			case CommandId::GetnPixelMapuiv:
			{
				multigl::PixelMap map = m_Buffer.read<multigl::PixelMap>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLuint * values = m_Buffer.read<GLuint *>();
				GL_CHECK(glGetnPixelMapuiv(map, bufSize, values));
				break;
			}
			case CommandId::GetnPixelMapusv:
			{
				multigl::PixelMap map = m_Buffer.read<multigl::PixelMap>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLushort * values = m_Buffer.read<GLushort *>();
				GL_CHECK(glGetnPixelMapusv(map, bufSize, values));
				break;
			}
			case CommandId::GetnPolygonStipple:
			{
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				GLubyte * pattern = m_Buffer.read<GLubyte *>();
				GL_CHECK(glGetnPolygonStipple(bufSize, pattern));
				break;
			}
			case CommandId::GetnColorTable:
			{
				multigl::ColorTableTarget target = m_Buffer.read<multigl::ColorTableTarget>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * table = m_Buffer.read<void *>();
				GL_CHECK(glGetnColorTable(target, format, type, bufSize, table));
				break;
			}
			case CommandId::GetnConvolutionFilter:
			{
				multigl::ConvolutionTarget target = m_Buffer.read<multigl::ConvolutionTarget>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * image = m_Buffer.read<void *>();
				GL_CHECK(glGetnConvolutionFilter(target, format, type, bufSize, image));
				break;
			}
			case CommandId::GetnSeparableFilter:
			{
				multigl::SeparableTargetEXT target = m_Buffer.read<multigl::SeparableTargetEXT>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei rowBufSize = m_Buffer.read<GLsizei>();
				void * row = m_Buffer.read<void *>();
				GLsizei columnBufSize = m_Buffer.read<GLsizei>();
				void * column = m_Buffer.read<void *>();
				void * span = m_Buffer.read<void *>();
				GL_CHECK(glGetnSeparableFilter(target, format, type, rowBufSize, row, columnBufSize, column, span));
				break;
			}
			case CommandId::GetnHistogram:
			{
				multigl::HistogramTargetEXT target = m_Buffer.read<multigl::HistogramTargetEXT>();
				GLboolean reset = m_Buffer.read<GLboolean>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * values = m_Buffer.read<void *>();
				GL_CHECK(glGetnHistogram(target, reset, format, type, bufSize, values));
				break;
			}
			case CommandId::GetnMinmax:
			{
				multigl::MinmaxTargetEXT target = m_Buffer.read<multigl::MinmaxTargetEXT>();
				GLboolean reset = m_Buffer.read<GLboolean>();
				multigl::PixelFormat format = m_Buffer.read<multigl::PixelFormat>();
				multigl::PixelType type = m_Buffer.read<multigl::PixelType>();
				GLsizei bufSize = m_Buffer.read<GLsizei>();
				void * values = m_Buffer.read<void *>();
				GL_CHECK(glGetnMinmax(target, reset, format, type, bufSize, values));
				break;
			}
			case CommandId::TextureBarrier:
			{
				GL_CHECK(glTextureBarrier());
				break;
			}
		}
	}
	m_Buffer.reset();
}
