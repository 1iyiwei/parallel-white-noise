/*
  DiffuseQuadScene.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include "DiffuseQuadScene.hpp"
#include "Exception.hpp"

DiffuseQuadScene::DiffuseQuadScene(void): _vao(0), _vbo(0)
{
    // generate and bind the vao
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    
    // generate and bind the buffer object
    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            
    // data for a fullscreen quad
    GLfloat vertexData[] = {
        //  X     Y     Z           R     G     B
        1.0f, 1.0f, 0.0f,       1.0f, 0.0f, 0.0f, // red
        -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // green
        1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // blue
        1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // blue
        -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // green
        -1.0f,-1.0f, 0.0f,       1.0f, 1.0f, 0.0f, // yellow
    }; // 6 vertices with 6 components (floats) each
    
    // fill with data
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);
                    
    // set up generic attrib pointers
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (char*)0 + 0*sizeof(GLfloat));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (char*)0 + 3*sizeof(GLfloat));
}

DiffuseQuadScene::~DiffuseQuadScene(void)
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
}

void DiffuseQuadScene::Render(void) const
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBindVertexArray(_vao);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}
