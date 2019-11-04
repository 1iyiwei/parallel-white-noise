/*
  TextureFragmentShader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include <sstream>
using namespace std;

#include "TextureFragmentShader.hpp"
#include "Exception.hpp"

TextureFragmentShader::TextureFragmentShader(const GLenum type): FragmentShader(Source(type))
{
    // nothing else to do
}

string TextureFragmentShader::Source(const GLenum type) const
{
    stringstream ss;
    ss << "#version 330\n";
    ss << "uniform " << Sampler(type) << " " << TextureSymbol() << ";\n";
    ss << "in vec" << DomainDimension(type) << " ftexcoord;\n";
    ss << "layout(location = 0) out vec4 FragColor;\n";
    ss << "void main() {\n";
    ss << "   FragColor = texture(tex, ftexcoord);\n";
    ss << "}\n";

    return ss.str();
}

string TextureFragmentShader::TextureSymbol(void) const
{
    return "tex";
}

string TextureFragmentShader::Sampler(const GLenum type)
{
    string answer;

    switch(type)
    {
    case GL_TEXTURE_2D:
        answer = "sampler2D";
        break;

    case GL_TEXTURE_2D_ARRAY:
        answer = "sampler2DArray";
        break;

    default:
        throw Exception("TextureFragmentShader::Sampler(): unknown type");
    }

    return answer;
}

int TextureFragmentShader::DomainDimension(const GLenum type)
{
    int answer = 0;

    switch(type)
    {
    case GL_TEXTURE_2D:
        answer = 2;
        break;

    case GL_TEXTURE_2D_ARRAY:
        answer = 3;
        break;

    default:
        throw Exception("TextureFragmentShader::DomainDimension(): unknown type");
    }

    return answer;
}
