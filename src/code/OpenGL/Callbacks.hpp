/*
  Callbacks.hpp

  Li-Yi Wei
  November 7, 2017

*/

#ifndef _CALLBACKS_HPP
#define _CALLBACKS_HPP

#include <GLXW/glxw.h>
#include <GLFW/glfw3.h>

class Callbacks
{
public:
    static void FramebufferSize(GLFWwindow* window, int width, int height);
};

#endif
