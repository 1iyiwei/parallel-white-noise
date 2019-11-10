/*
  TextureCoordinateFragmentShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _TEXTURE_COORDINATE_FRAGMENT_SHADER_HPP
#define _TEXTURE_COORDINATE_FRAGMENT_SHADER_HPP

#include "FragmentShader.hpp"

class TextureCoordinateFragmentShader: public FragmentShader
{
public:
    TextureCoordinateFragmentShader(const GLenum type);

    string Source(const GLenum type) const;

    static string Sampler(const GLenum type);
    static int DomainDimension(const GLenum type);
};

#endif

