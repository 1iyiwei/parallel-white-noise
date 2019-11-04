/*
  FragmentShader.cpp
  
  Li-Yi Wei
  November 6, 2017

*/

#include "FragmentShader.hpp"
#include "Exception.hpp"

FragmentShader::FragmentShader(void)
{
    // nothing else to do
}

FragmentShader::FragmentShader(const string & shader_code)
{
    const string message = Construct(shader_code);

    if(message != "")
    {
        throw Exception("FragmentShader::FragmentShader(): error in building shader - " + message);
    }
}

FragmentShader::~FragmentShader(void)
{
    // nothing else to do
}

GLenum FragmentShader::Type(void) const
{
    return GL_FRAGMENT_SHADER;
}
