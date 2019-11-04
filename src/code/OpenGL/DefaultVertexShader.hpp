/*
  DefaultVertexShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _DEFAULT_VERTEX_SHADER_HPP
#define _DEFAULT_VERTEX_SHADER_HPP

#include "VertexShader.hpp"

class DefaultVertexShader: public VertexShader
{
public:
    DefaultVertexShader(void);

    string Source(void) const;
};

#endif

