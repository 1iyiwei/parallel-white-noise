/*
  DefaultVertexShader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include "DefaultVertexShader.hpp"

DefaultVertexShader::DefaultVertexShader(void): VertexShader(Source())
{
    // nothing else to do
}

string DefaultVertexShader::Source(void) const
{
    const string source =
        "#version 330\n"
        "layout(location = 0) in vec4 vposition;\n"
        "layout(location = 1) in vec4 vcolor;\n"
        "out vec4 fcolor;\n"
        "void main() {\n"
        "   fcolor = vcolor;\n"
        "   gl_Position = vposition;\n"
        "}\n";

    return source;
}
