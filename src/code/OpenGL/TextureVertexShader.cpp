/*
  TextureVertexShader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include <sstream>
using namespace std;

#include "TextureVertexShader.hpp"

TextureVertexShader::TextureVertexShader(const int tex_dim): VertexShader(Source(tex_dim))
{
    // nothing else to do
}

string TextureVertexShader::Source(const int tex_dim) const
{
    stringstream ss;
    
    ss << "#version 330\n";
    ss << "layout(location = 0) in vec4 vposition;\n";
    ss << "layout(location = 1) in vec" << tex_dim << " vtexcoord;\n";
    ss << "out vec" << tex_dim << " ftexcoord;\n";
    ss << "void main() {\n";
    ss << "   ftexcoord = vtexcoord;\n";
    ss << "   gl_Position = vposition;\n";
    ss << "}\n";

    return ss.str();
}
