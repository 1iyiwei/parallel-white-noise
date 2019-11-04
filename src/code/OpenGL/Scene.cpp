/*
  Scene.cpp

  Li-Yi Wei
  November 6, 2017

*/

#include "Scene.hpp"
#include "Exception.hpp"

Scene::Scene(void)
{
    // nothing else to do
}

Scene::Scene(const Scene & rhs)
{
    throw Exception("Scene::Scene(const Scene & rhs) shouldn't be called");
}

Scene::~Scene(void)
{
    // nothing else to do
}

void Scene::Render(void) const
{
    throw Exception("Scene::Render() shouldn't be called");
}
