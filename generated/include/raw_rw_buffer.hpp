#pragma once
#include <vector>
#include "gl_function_enums.hpp"

namespace multigl
{
    class raw_rw_buffer
    {
    public:
        inline raw_rw_buffer() : m_WriteIdx(0), m_ReadIdx(0)
        {
            m_Buffer.reserve(512);
        }

        inline ~raw_rw_buffer() { }
    
    public:
        inline void reset()
        {
            m_Buffer.resize(0);
            m_WriteIdx = 0;
            m_ReadIdx = 0;
        }

    public:
        inline void write_command(const CommandId& cmd)
        {
            write<gl_command_id_t>(gl_command_id_t(cmd));
        }

        template<typename T>
        inline void write(const T& val)
        {
            auto align = alignof(T);
            auto mod = align - m_WriteIdx % align;
            if (mod == align)
            {
                ensure_write_capacity(sizeof(T));
            }
            else
            {
                ensure_write_capacity(sizeof(T) + mod);
                write_padding(mod);
            }

            write_unchecked(val);
        }

    private:
        inline void ensure_write_capacity(size_t amount)
        {
            auto tgCapacity = m_WriteIdx + amount;
            if (m_Buffer.capacity() < tgCapacity)
            {
                m_Buffer.reserve(size_t(double(tgCapacity) * 2));
            }
        }

        inline void write_padding(size_t padding)
        {
            m_Buffer.resize(m_WriteIdx + padding);
            m_WriteIdx += padding;
        }

        template<typename T>
        inline void write_unchecked(const T& val)
        {
            m_Buffer.resize(m_WriteIdx + sizeof(T));
            *(reinterpret_cast<T*>(&m_Buffer[m_WriteIdx])) = val;
            m_WriteIdx += sizeof(T);
        }

    public:
        inline bool has_commands()
        {
            return m_ReadIdx < m_WriteIdx;
        }


        inline CommandId read_command()
        {
            return read<CommandId>();
        }

        template<typename T>
        inline T read()
        {
            auto align = alignof(T);
            auto mod = align - m_ReadIdx % align;
            if (mod != align)
            {
                read_padding(mod);
            }

            return read_unchecked<T>();
        }

    private:
        inline void read_padding(size_t padding)
        {
            m_ReadIdx += padding;
        }

        template<typename T>
        inline T read_unchecked()
        {
            auto old = m_ReadIdx;
            m_ReadIdx += sizeof(T);
            return *(reinterpret_cast<T*>(&m_Buffer[old]));
        }

    private:
        std::vector<char> m_Buffer;
        size_t m_WriteIdx;
        size_t m_ReadIdx;
    };
}