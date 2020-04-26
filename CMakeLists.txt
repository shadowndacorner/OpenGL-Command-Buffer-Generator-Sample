cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(glcmdbufgentest VERSION 0.1 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 14)

add_subdirectory(thirdparty/SDL-mirror EXCLUDE_FROM_ALL)

add_executable(
    test
    "src/glad.cpp"
    "src/main.cpp"
    "src/stbi.cpp"
    "generated/src/gl_command_buffer_write.cpp"
    "generated/src/gl_command_buffer_read.cpp"
    "generated/src/gl_immediate_buffer_write.cpp"
    "generated/src/gl_immediate_buffer_read.cpp"
)

target_include_directories(test PUBLIC "include" "generated/include" "thirdparty/glm/")
target_link_libraries(test PUBLIC SDL2)