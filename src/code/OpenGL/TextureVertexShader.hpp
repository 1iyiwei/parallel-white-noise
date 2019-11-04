/*
  TextureVertexShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _TEXTURE_VERTEX_SHADER_HPP
#define _TEXTURE_VERTEX_SHADER_HPP

#include "VertexShader.hpp"

class TextureVertexShader: public VertexShader
{
public:
    TextureVertexShader(const int texture_dimension);

    string Source(const int texture_dimension) const;
};

#endif

