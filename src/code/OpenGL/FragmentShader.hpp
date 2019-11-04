/*
  FragmentShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _FRAGMENT_SHADER_HPP
#define _FRAGMENT_SHADER_HPP

#include "Shader.hpp"

class FragmentShader: public Shader
{
public:
    FragmentShader(void);
    FragmentShader(const string & shader_code);
    virtual ~FragmentShader(void) = 0;

protected:
    GLenum Type(void) const; 
};

#endif
