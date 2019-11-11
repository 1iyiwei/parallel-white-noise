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
#if 0
#include "texcoord.frag"
#else
#include "md5.frag"
#endif
        ;

    return frag;
}

string MD5FragmentShader::ResSymbol(void)
{
    return "res";
}

string MD5FragmentShader::KeySymbol(void)
{
    return "key";
}
