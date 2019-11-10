/*
  TextureCoordinateFragmentShader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include <sstream>
using namespace std;

#include "TextureCoordinateFragmentShader.hpp"
#include "Exception.hpp"

TextureCoordinateFragmentShader::TextureCoordinateFragmentShader(const GLenum type): FragmentShader(Source(type))
{
    // nothing else to do
}

string TextureCoordinateFragmentShader::Source(const GLenum type) const
{
    stringstream ss;
    ss << "#version 330\n";
    ss << "in vec" << DomainDimension(type) << " ftexcoord;\n";
    ss << "layout(location = 0) out vec4 FragColor;\n";
    ss << "void main() {\n";
    ss << "   FragColor.xy = ftexcoord.xy;\n";
    ss << "}\n";

    return ss.str();
}

string TextureCoordinateFragmentShader::Sampler(const GLenum type)
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
        throw Exception("TextureCoordinateFragmentShader::Sampler(): unknown type");
    }

    return answer;
}

int TextureCoordinateFragmentShader::DomainDimension(const GLenum type)
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
        throw Exception("TextureCoordinateFragmentShader::DomainDimension(): unknown type");
    }

    return answer;
}
