/*
  DefaultFragmentShader.hpp

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _DEFAULT_FRAGMENT_SHADER_HPP
#define _DEFAULT_FRAGMENT_SHADER_HPP

#include "FragmentShader.hpp"

class DefaultFragmentShader: public FragmentShader
{
public:
    DefaultFragmentShader(void);

    string Source(void) const;
};

#endif

