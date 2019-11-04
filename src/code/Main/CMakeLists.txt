CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

include_directories(${GLFW_SOURCE_DIR}/include)
include_directories(${glxw_BINARY_DIR}/include)
INCLUDE_DIRECTORIES(${Example_SOURCE_DIR}/Library)
include_directories(${Example_SOURCE_DIR}/OpenGL)

LINK_DIRECTORIES(${Example_BINARY_DIR}/Library)
link_directories(${Example_BINARY_DIR}/OpenGL)

SET(LIBRARIES glfw glxw ${GLFW_LIBRARIES} ${GLXW_LIBRARY} ${OPENGL_LIBRARY} ${CMAKE_DL_LIBS} CoreLibrary OpenGLLibrary)

set(projects
Basic
HelloWorld
)

foreach(project ${projects})

project(${project})
add_executable(${project} ${project}.cpp)
target_link_libraries(${project} ${LIBRARIES})

endforeach(project)

