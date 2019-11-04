/*
  Shader.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include <vector>
using namespace std;

#include "Shader.hpp"
#include "Exception.hpp"

Shader::Shader(void): _shader_id(0)
{
    // nothing else to do
}

Shader::Shader(const string & shader_source): _shader_id(0)
{
    const string message = Construct(shader_source);

    if(message != "")
    {
        throw Exception("Shader::Shader(): error in building shader: " + message);
    }
}

Shader::Shader(const Shader & rhs): _shader_id(0)
{
    throw Exception("Shader::Shader(const Shader & rhs) shouldn't be called");
}

Shader::~Shader(void)
{
    Destruct();
}

string Shader::Construct(const string & shader_source)
{
    Destruct();

    const char *source = 0;
    int length = 0;
    string message;

    _shader_id = glCreateShader(Type());
    source = shader_source.c_str();
    length = static_cast<int>(shader_source.size());
    glShaderSource(_shader_id, 1, &source, &length); 
    glCompileShader(_shader_id);

    return CheckCompileStatus(_shader_id);
}

void Shader::Destruct(void)
{
    if(_shader_id > 0)
    {
        glDeleteShader(_shader_id);
    }

    _shader_id = 0;
}

string Shader::CheckCompileStatus(GLuint obj) const
{
    GLint status;
    glGetShaderiv(obj, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE) 
    {
        GLint length;
        glGetShaderiv(obj, GL_INFO_LOG_LENGTH, &length);
        vector<char> log(length);
        glGetShaderInfoLog(obj, length, &length, &log[0]);
        
        return string(log.begin(), log.end());
    }
    else
    {
        return "";
    }
}

GLenum Shader::Type(void) const
{
    throw Exception("Shader::Type() shouldn't be called");
    return 0;
}

GLuint Shader::ID(void) const
{
    return _shader_id;
}
