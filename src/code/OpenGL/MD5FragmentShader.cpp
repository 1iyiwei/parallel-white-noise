/*
  MD5FragmentShader.cpp

  Li-Yi Wei
  November 9, 2019

*/

#include <sstream>
using namespace std;

#include "MD5FragmentShader.hpp"
#include "Exception.hpp"

MD5FragmentShader::MD5FragmentShader(void): FragmentShader(Source())
{
    // nothing else to do
}

// https://stackoverflow.com/questions/410980/include-a-text-file-in-a-c-program-as-a-char
string MD5FragmentShader::Source(void) const
{
    constexpr char *frag =
#include "texcoord.frag"
        ;

    return frag;
}
