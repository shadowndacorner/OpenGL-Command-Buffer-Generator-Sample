#pragma once
#include <type_traits>
#include <algorithm>
#include <vector>
#include <mutex>

#if !defined MGL_ASSERT
#include <cassert>
#define MGL_ASSERT(...) assert( __VA_ARGS__ );
#endif

namespace multigl
{
    template <typename T, typename handle_t>
    class slot_map
    {
    public:
        using value_t = T;

    private:
        struct entry
        {
            value_t value;
            uint32_t generation;
            bool occupied;
        };

    public:
        using allocator_t = std::allocator<entry>;

    public:
        inline slot_map()
            : m_Data(NULL)
            , m_Size(0)
            , m_NextID(0)
            , m_Generation(0)
        {
        }

        inline ~slot_map()
        {
            if (!std::is_trivially_destructible<value_t>())
            {
                for (uint32_t i = 0; i < m_Size; ++i)
                {
                    auto& from = m_Data[i];
                    if (from.occupied)
                    {
                        from.value.~value_t();
                    }
                }
            }
            m_Allocator.deallocate(m_Data, m_Size);
        }

    public:
        template <typename... Args>
        inline handle_t create(Args&&... arg)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            handle_t handle = allocate_id();
            ensure_size(handle.index + 1);
            MGL_ASSERT(!m_Data[handle.index].occupied && "Attempted to recreate pre-existing value");
            new (&m_Data[handle.index].value) value_t(std::forward<Args>(arg)...);
            m_Data[handle.index].occupied = true;
            handle.generation = ++m_Data[handle.index].generation;
            return handle;
        }

        template <typename... Args>
        inline T* create_and_get(Args&&... arg)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            handle_t handle = allocate_id();
            ensure_size(handle.index + 1);
            MGL_ASSERT(!m_Data[handle.index].occupied && "Attempted to recreate pre-existing value");
            new (&m_Data[handle.index].value) value_t(std::forward<Args>(arg)...);
            m_Data[handle.index].occupied = true;
            handle.generation = ++m_Data[handle.index].generation;
            return &m_Data[handle.index].value;
        }

        inline void destroy(const handle_t& handle)
        {
            std::lock_guard<std::mutex> lock(m_Mutex);
            ++m_Generation;
            MGL_ASSERT(is_valid(handle) && "Attempted to destroy invalid handle");
            m_Data[handle.index].value.~value_t();
            m_Data[handle.index].occupied = false;
            m_FreeIDs.push_back(handle.index);
        }

    public:
        inline value_t* get(const handle_t& handle)
        {
            MGL_ASSERT(m_Data[handle.index].generation == handle.generation);
            return &m_Data[handle.index].value;
        }

        inline value_t* get_nogencheck(const handle_t& handle)
        {
            return &m_Data[handle.index].value;
        }

        inline bool is_index_resident(const handle_t& handle)
        {
            return m_Data[handle.index].occupied;
        }

        inline bool is_valid(const handle_t& handle)
        {
            return handle.index < m_Size && m_Data[handle.index].occupied && handle.generation == m_Data[handle.index].generation;
        }

        inline void reserve(uint32_t size)
        {
            ensure_size(size);
        }

        inline size_t max_index()
        {
            return m_Size;
        }

    private:
        inline uint32_t allocate_id()
        {
            if (m_FreeIDs.size() > 0)
            {
                uint32_t val = m_FreeIDs.back();
                m_FreeIDs.pop_back();
                return val;
            }
            return m_NextID++;
        }

        inline void ensure_size(uint32_t tgSize)
        {
            uint32_t size = tgSize;
            if (size <= m_Size)
            {
                return;
            }
            
            ++m_Generation;

            // TODO: allocation strategy?
            entry* next = m_Allocator.allocate(size);
            memset(next, 0, sizeof(entry) * size);
            for (uint32_t i = 0; i < m_Size; ++i)
            {
                auto& tg = next[i];
                auto& from = m_Data[i];
                tg.generation = from.generation;
                if ((tg.occupied = from.occupied) == true)
                {
                    new (&tg.value) value_t(std::move(from.value));
                }

                if (!std::is_trivially_destructible<value_t>())
                {
                    if (from.occupied)
                    {
                        from.value.~value_t();
                    }
                }
            }

            if (m_Data)
            {
                m_Allocator.deallocate(m_Data, m_Size);
            }

            m_Size = size;
            m_Data = next;
        }
    
    // Iterators
    public:
        class iterator
        {
        public:
            inline iterator(slot_map& map, uint32_t index) : m_Map(map), m_Index(index) {}
            inline iterator(const iterator& rhs) : m_Map(rhs.m_Map), m_Index(rhs.m_Index) {}

            inline bool operator==(const iterator& rhs)
            {
                return rhs.m_Index == m_Index && &rhs.m_Map == &m_Map;
            }

            inline bool operator!=(const iterator& rhs)
            {
                return rhs.m_Index != m_Index || &rhs.m_Map != &m_Map;
            }

            inline T* operator->()
            {
                return m_Map.get(m_Index);
            }

            inline T* operator*()
            {
                return m_Map.get(m_Index);
            }

            inline iterator operator++()
            {
                ++m_Index;
                while (m_Index < m_Size && !is_index_resident(m_Index))
                {
                    ++m_Index;
                }
                return *this;
            }

            inline iterator operator++(int)
            {
                auto old = *this;
                ++*this;
                return old;
            }

        private:
            slot_map& m_Map;
            uint32_t m_Index;
        };

        class const_iterator
        {
        public:
            inline const_iterator(const slot_map& map, uint32_t index) : m_Map(map), m_Index(index) {}
            inline const_iterator(const const_iterator& rhs) : m_Map(rhs.m_Map), m_Index(rhs.m_Index) {}

            inline bool operator==(const const_iterator& rhs) const
            {
                return rhs.m_Index == m_Index && &rhs.m_Map == &m_Map;
            }

            inline bool operator!=(const const_iterator& rhs) const
            {
                return rhs.m_Index != m_Index || &rhs.m_Map != &m_Map;
            }

            inline const T* operator->() const
            {
                return m_Map.get(m_Index);
            }

            inline const T* operator*() const
            {
                return m_Map.get(m_Index);
            }

            inline const_iterator operator++()
            {
                ++m_Index;
                while (m_Index < m_Size && !is_index_resident(m_Index))
                {
                    ++m_Index;
                }
                return *this;
            }

            inline const_iterator operator++(int)
            {
                auto old = *this;
                ++*this;
                return old;
            }

        private:
            const slot_map& m_Map;
            uint32_t m_Index;
        };

        inline iterator begin()
        {
            uint32_t index = 0;
            while (!is_index_resident(index) && index < m_Size)
            {
                ++index;
            }
            return iterator(*this, index);
        }

        inline iterator end()
        {
            return iterator(*this, m_Size);
        }

        inline const_iterator begin() const
        {
            uint32_t index = 0;
            while (!is_index_resident(index) && index < m_Size)
            {
                ++index;
            }
            return const_iterator(*this, index);
        }

        inline const_iterator end() const
        {
            return const_iterator(*this, m_Size);
        }

        class caching_handle
        {
        public:
            inline caching_handle() : map(0), handle(0) {}

            inline caching_handle(slot_map& map, const handle_t& handle) : map(&map), handle(handle) {
                update();
            }

            inline caching_handle(slot_map& map, uint64_t handle) : map(&map), handle(handle) {
                update();
            }

            inline caching_handle(const caching_handle& rhs) : cached(rhs.cached), map(rhs.map), handle(rhs.handle), generation(rhs.generation) {}

            inline caching_handle& operator=(const caching_handle& rhs)
            {
                cached = rhs.cached;
                map = rhs.map;
                handle = rhs.handle;
                generation = rhs.generation;
            }

            inline T* operator->()
            {
                return get();
            }

            inline T* operator*()
            {
                return get();
            }

            inline T* get()
            {
                if (generation != map->m_Generation) { update(); }
                return cached;
            }

            inline bool is_valid()
            {
                return map && map->is_valid(handle);
            }

        private:
            void update()
            {
                cached = map->get(handle);
                generation = map->m_Generation;
            }

        private:
            T* cached;
            slot_map* map;
            handle_t handle;
            int generation;
        };

        inline caching_handle get_handle(const handle_t& handle)
        {
            return caching_handle(*this, handle);
        }

        inline caching_handle get_handle(const uint64_t& handle)
        {
            return caching_handle(*this, handle);
        }

    private:
        entry* m_Data;
        std::mutex m_Mutex;
        std::vector<uint32_t> m_FreeIDs;
        uint32_t m_Size;
        uint32_t m_NextID;
        allocator_t m_Allocator;
        int m_Generation;
    };
}