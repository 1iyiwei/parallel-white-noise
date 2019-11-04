/*
  Scene.hpp

  the base class for all scenes (geometry and other properties)

  Li-Yi Wei
  November 6, 2017

*/

#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <GLXW/glxw.h>
#include <GLFW/glfw3.h>

class Scene
{
public:
    Scene(void);
    virtual ~Scene(void) = 0;
    virtual void Render(void) const;

private:
    Scene(const Scene & rhs);
};
#endif
