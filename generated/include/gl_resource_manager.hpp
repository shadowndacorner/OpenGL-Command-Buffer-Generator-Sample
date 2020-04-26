#pragma once
#include <stdint.h>
#include <glad/glad.h>
#include "gl_slotmap.hpp"


#define CREATE_GL_RESOURCE_HANDLE(name, resourceType) \
struct name##Handle \
{ \
    inline name##Handle() \
        : handle_value(0) \
    { \
    } \
    inline name##Handle(uint32_t ind) \
        : index(ind) \
        , generation(0) \
    { \
    } \
    inline name##Handle(uint64_t ind) \
        : handle_value(ind) \
    { \
    } \
    union { \
        struct \
        { \
            uint32_t generation; \
            uint32_t index; \
        }; \
        uint64_t handle_value; \
    }; \
 \
    inline bool operator==(const name##Handle& rhs) \
    { \
        return handle_value == rhs.handle_value; \
    } \
 \
    inline bool operator!=(const name##Handle& rhs) \
    { \
        return handle_value != rhs.handle_value; \
    } \
    using resource_type = resourceType;\
};

#define CREATE_GL_RESOURCE_MANAGER(name) slot_map<name##Handle::resource_type, name##Handle> name##s

namespace multigl
{
    CREATE_GL_RESOURCE_HANDLE(Buffer, GLuint);
    CREATE_GL_RESOURCE_HANDLE(Texture, GLuint);
    CREATE_GL_RESOURCE_HANDLE(Shader, GLuint);
    CREATE_GL_RESOURCE_HANDLE(ShaderProgram, GLuint);
    CREATE_GL_RESOURCE_HANDLE(VertexArray, GLuint);
    CREATE_GL_RESOURCE_HANDLE(Renderbuffer, GLuint);
    CREATE_GL_RESOURCE_HANDLE(Framebuffer, GLuint);

    struct ResourceManager
    {
        CREATE_GL_RESOURCE_MANAGER(Buffer);
        CREATE_GL_RESOURCE_MANAGER(Texture);
        CREATE_GL_RESOURCE_MANAGER(Shader);
        CREATE_GL_RESOURCE_MANAGER(ShaderProgram);
        CREATE_GL_RESOURCE_MANAGER(VertexArray);
        CREATE_GL_RESOURCE_MANAGER(Renderbuffer);
        CREATE_GL_RESOURCE_MANAGER(Framebuffer);
    };
}

#undef CREATE_GL_RESOURCE_MANAGER
#undef CREATE_RESOURCE_MANAGER