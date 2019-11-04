CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(OpenGLLibrary)

include_directories(${GLFW_SOURCE_DIR}/include)
include_directories(${glxw_BINARY_DIR}/include)
INCLUDE_DIRECTORIES(${Example_SOURCE_DIR}/Library)

ADD_LIBRARY(${PROJECT_NAME}
Callbacks.cpp
Callbacks.hpp
DefaultFragmentShader.cpp
DefaultFragmentShader.hpp
DefaultVertexShader.cpp
DefaultVertexShader.hpp
DiffuseQuadScene.cpp
DiffuseQuadScene.hpp
FragmentShader.cpp
FragmentShader.hpp
Program.cpp
Program.hpp
Scene.cpp
Scene.hpp
Shader.cpp
Shader.hpp
VertexShader.cpp
VertexShader.hpp
)
