/*
  Shader.hpp

  the base class for all vertex/fragment/etc shaders

  Li-Yi Wei
  November 5, 2017

*/

#ifndef _SHADER_HPP
#define _SHADER_HPP

#include <string>
using namespace std;

#include <GLXW/glxw.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
    Shader(void);
    virtual ~Shader(void) = 0;

    virtual string Construct(const string & shader_source);
    virtual void Destruct(void);

    GLuint ID(void) const;

protected:

    virtual string CheckCompileStatus(GLuint obj) const;

    // vertex, fragment, etc.
    virtual GLenum Type(void) const;

private:

    // would not work during constructor
    Shader(const string & shader_source);

    // no copy
    Shader(const Shader & rhs);

protected:
    GLuint _shader_id;
};

#endif
