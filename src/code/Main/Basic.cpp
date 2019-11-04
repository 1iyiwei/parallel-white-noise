/*
  Draw a simple full screen quad

  Li-Yi Wei
  November 5, 2017

 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

#include <stdlib.h>

#include <GLXW/glxw.h>
#include <GLFW/glfw3.h>

#include "DefaultVertexShader.hpp"
#include "DefaultFragmentShader.hpp"

#include "Program.hpp"

#include "DiffuseQuadScene.hpp"

#include "Callbacks.hpp"

#include "Exception.hpp"

bool game_over = false;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
    {
        switch(key)
        {
        case GLFW_KEY_ESCAPE:
            game_over = true;
            break;

        default:
            // do nothing
            break;
        }
    }
}

int Main(int argc, char **argv)
{
    // input arguments
    const int default_win_size = 256;

    int arg_ctr = 0;    
    const int width = (arg_ctr + 1) < argc ? atoi(argv[++arg_ctr]) : default_win_size;
    const int height = (arg_ctr + 1) < argc ? atoi(argv[++arg_ctr]) : width;

    // init
    if(glfwInit() == GL_FALSE) 
    {
        cerr << "failed to init GLFW" << endl;
        return 1;
    }

    // select opengl version 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // create a window
    GLFWwindow *window;
    if((window = glfwCreateWindow(width, height, "hello!", 0, 0)) == 0) 
    {
        cerr << "failed to open window" << endl;
        glfwTerminate();
        return 1;
    }
    
    glfwMakeContextCurrent(window);

    if(glxwInit())
    {
        cerr << "failed to init GL3W" << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // call backs
    glfwSetFramebufferSizeCallback(window, Callbacks::FramebufferSize);
    glfwSetKeyCallback(window, KeyCallback);

    // scope for program and scene objects
    {
        // shader program
        DefaultVertexShader vertex_shader;
        DefaultFragmentShader fragment_shader;

        vector<const Shader *> shaders;
        shaders.push_back(&vertex_shader);
        shaders.push_back(&fragment_shader);

        Program program(shaders);

        DiffuseQuadScene scene;

        while(!glfwWindowShouldClose(window) && !game_over) 
        {
            glfwPollEvents();

            // draw stuff
            program.Use();
            scene.Render();

            // check for errors
            GLenum error = glGetError();
            if(error != GL_NO_ERROR) 
            {
                cerr << "Error: " << error << endl;
                break;
            }

            // finally swap buffers
            glfwSwapBuffers(window);
        }
    }

    // cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

int main(int argc, char **argv)
{
    try
    {
        return Main(argc, argv);
    }
    catch(Exception e)
    {
        cerr << e.Message() << endl;
        return 1;
    }
}
