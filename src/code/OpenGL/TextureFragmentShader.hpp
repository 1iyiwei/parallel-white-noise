/*
  TextureFragmentShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _TEXTURE_FRAGMENT_SHADER_HPP
#define _TEXTURE_FRAGMENT_SHADER_HPP

#include "FragmentShader.hpp"

class TextureFragmentShader: public FragmentShader
{
public:
    TextureFragmentShader(const GLenum type);

    string Source(const GLenum type) const;

    string TextureSymbol(void) const;

    static string Sampler(const GLenum type);
    static int DomainDimension(const GLenum type);
};

#endif

