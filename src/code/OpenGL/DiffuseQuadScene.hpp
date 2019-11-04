/*
  DiffuseQuadScene.hpp

  a simple diffuse colored quad

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _DIFFUSE_QUAD_SCENE_HPP
#define _DIFFUSE_QUAD_SCENE_HPP

#include "Scene.hpp"

class DiffuseQuadScene: public Scene
{
public:
    DiffuseQuadScene(void);
    virtual ~DiffuseQuadScene(void);

    virtual void Render(void) const;

protected:
    GLuint _vao, _vbo;
};
#endif
