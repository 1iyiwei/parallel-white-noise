/*
  Callbacks.cpp

  Li-Yi Wei
  November 7, 2017

*/

#include "Callbacks.hpp"

void Callbacks::FramebufferSize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
