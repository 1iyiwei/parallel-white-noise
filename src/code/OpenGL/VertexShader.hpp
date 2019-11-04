/*
  VertexShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _VERTEX_SHADER_HPP
#define _VERTEX_SHADER_HPP

#include "Shader.hpp"

class VertexShader: public Shader
{
public:
    VertexShader(void);
    VertexShader(const string & shader_code);
    virtual ~VertexShader(void) = 0;

protected:
    GLenum Type(void) const; 
};

#endif
