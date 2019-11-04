/*
  GL Program

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _PROGRAM_HPP
#define _PROGRAM_HPP

#include "Shader.hpp"

class Program
{
public:
    Program(const vector<const Shader *> & shaders);
    virtual ~Program(void);

    void Use(void) const;

    bool Valid(void) const;

    GLuint ID(void) const;

protected:
    string Construct(void);
    void Destruct(void);

    Program(const Program & rhs);

    string CheckLinkStatus(GLuint obj) const;

protected:
    GLuint _program_id;
    const vector<const Shader *> _shaders;
};

#endif
