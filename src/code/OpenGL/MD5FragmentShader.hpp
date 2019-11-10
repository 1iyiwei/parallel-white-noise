/*
  MD5FragmentShader.hpp

  Li-Yi Wei
  November 9, 2019

*/

#ifndef _MD5_FRAGMENT_SHADER_HPP
#define _MD5_FRAGMENT_SHADER_HPP

#include "FragmentShader.hpp"

class MD5FragmentShader: public FragmentShader
{
public:
    MD5FragmentShader(void);

    string Source(void) const;
};

#endif

