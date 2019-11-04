/*
  TextureQuadScene.hpp

  a simple textured quad

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _TEXTURE_QUAD_SCENE_HPP
#define _TEXTURE_QUAD_SCENE_HPP

#include "Scene.hpp"

class TextureQuadScene: public Scene
{
public:
    TextureQuadScene(void);
    virtual ~TextureQuadScene(void);

    virtual void Render(void) const;

protected:
    GLuint _vao, _vbo, _ibo;
};
#endif
