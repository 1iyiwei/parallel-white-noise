/*
  Texture.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include "Texture.hpp"
#include "Exception.hpp"

Texture::Texture(void)
{
    // nothing else to do
}

Texture::Texture(const Texture & rhs)
{
    throw Exception("Texture::Texture(const Texture & rhs) shouldn't be called");
}

Texture::~Texture(void)
{
    // nothing else to do
}

GLenum Texture::Type(void) const
{
    throw Exception("Texture::Type() shouldn't be called");
    return 0;
}

GLuint Texture::ID(void) const
{
    throw Exception("Texture::ID() shouldn't be called");
    return 0;
}
