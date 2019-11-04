/*
  VertexShader.cpp
  
  Li-Yi Wei
  November 6, 2017

*/

#include "VertexShader.hpp"
#include "Exception.hpp"

VertexShader::VertexShader(void)
{
    // nothing else to do
}

VertexShader::VertexShader(const string & shader_code)
{
    const string message = Construct(shader_code);

    if(message != "")
    {
        throw Exception("VertexShader::VertexShader(): error in building shader - " + message);
    }
}

VertexShader::~VertexShader(void)
{
    // nothing else to do
}

GLenum VertexShader::Type(void) const
{
    return GL_VERTEX_SHADER;
}
