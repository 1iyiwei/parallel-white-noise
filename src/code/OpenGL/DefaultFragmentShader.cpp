/*
  DefaultFragmentShader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include "DefaultFragmentShader.hpp"

DefaultFragmentShader::DefaultFragmentShader(void): FragmentShader(Source())
{
    // nothing else to do
}

string DefaultFragmentShader::Source(void) const
{
    const string source =
        "#version 330\n"
        "in vec4 fcolor;\n"
        "layout(location = 0) out vec4 FragColor;\n"
        "void main() {\n"
        "   FragColor = fcolor;\n"
        "}\n";

    return source;
}
