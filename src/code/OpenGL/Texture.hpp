/*
  Texture.hpp

  the base class of all textures

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

#include <GLXW/glxw.h>
#include <GLFW/glfw3.h>

class Texture
{
public:
    Texture(void);
    virtual ~Texture(void) = 0;

    // target type
    virtual GLenum Type(void) const;

    virtual GLuint ID(void) const;

private:
    Texture(const Texture & rhs);
};

#endif
