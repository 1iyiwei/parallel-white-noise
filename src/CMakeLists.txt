CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(Example)

option(BUILD_OGL43 "Bild OpenGL 4.3 examples" OFF)
mark_as_advanced(BUILD_OGL43)

find_package(OpenGL REQUIRED)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(external/glfw)
add_subdirectory(external/glxw)
ADD_SUBDIRECTORY(code)

set(CMAKE_CXX_FLAGS "-O2 -Wall")

add_dependencies(OpenGLLibrary glxw)
