#pragma once
#include "glad/glad.h"
#include <stdio.h>

#ifndef NDEBUG
#define DEBUG
#endif

inline const char* GetGLErrorStr(GLenum err)
{
	switch (err)
	{
		case GL_NO_ERROR:
			return "No error";
		case GL_INVALID_ENUM:
			return "Invalid enum";
		case GL_INVALID_VALUE:
			return "Invalid value";
		case GL_INVALID_OPERATION:
			return "Invalid operation";
#ifdef GL_STACK_OVERFLOW
		case GL_STACK_OVERFLOW:
			return "Stack overflow";
#endif
#ifdef GL_STACK_UNDERFLOW
		case GL_STACK_UNDERFLOW:
			return "Stack underflow";
#endif
		case GL_OUT_OF_MEMORY:
			return "Out of memory";
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			return "INVALID_FRAMEBUFFER_OPERATION";
		default:
			return "Unknown error";
	}
}

inline void ForceCheckGLError()
{
	bool found = false;
	while (true)
	{
		const GLenum err = glGetError();
		if (GL_NO_ERROR == err)
			break;

		found = true;
		fprintf(stderr, "OpenGL Error: %s\n", GetGLErrorStr(err));
		break;
	}
#ifdef DEBUGa
	assert(!found && "Graphics backend error(s).  Check console for details.");
#else
	if (found)
	{
		fprintf(stderr, "Graphics backend error(s).  Check console for details.\n");
	}
#endif
}

inline void CheckGLError()
{
#ifdef DEBUG
	ForceCheckGLError();
#endif
}

#define GL_CHECK(func) \
	func;              \
	CheckGLError()

