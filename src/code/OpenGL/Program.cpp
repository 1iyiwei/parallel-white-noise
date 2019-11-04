/*
  Program.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include <vector>
using namespace std;

#include "Program.hpp"
#include "Exception.hpp"

Program::Program(const vector<const Shader *> & shaders): _program_id(0), _shaders(shaders)
{
    const string message = Construct();

    if(message != "")
    {
        throw Exception("Program::Program(): cannot construct program - " + message);
    }
}

Program::~Program(void)
{
    Destruct();
}

string Program::Construct(void)
{
    Destruct();
    
    _program_id = glCreateProgram();
    
    for(unsigned int k = 0; k < _shaders.size(); k++)
    {
        glAttachShader(_program_id, _shaders[k]->ID());
    } 

    glLinkProgram(_program_id);
    return CheckLinkStatus(_program_id);
}

void Program::Destruct(void)
{
    if(_program_id > 0)
    {
        for(unsigned int k = 0; k < _shaders.size(); k++)
        {
            glDetachShader(_program_id, _shaders[k]->ID());
        }

        glDeleteProgram(_program_id);
        _program_id = 0;
    }
}

void Program::Use(void) const
{
    glUseProgram(_program_id);
}
 
bool Program::Valid(void) const
{
    return (CheckLinkStatus(_program_id) == "");
}

GLuint Program::ID(void) const
{
    return _program_id;
}

string Program::CheckLinkStatus(GLuint obj) const
{
    GLint status;
    glGetProgramiv(obj, GL_LINK_STATUS, &status);
    if(status == GL_FALSE) 
    {
        GLint length;
        glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &length);
        vector<char> log(length);
        glGetProgramInfoLog(obj, length, &length, &log[0]);
        return string(log.begin(), log.end());
    }
    else
    {
        return "";
    }
}
