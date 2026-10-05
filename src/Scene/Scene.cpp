#include "Scene/Scene.h"

void Scene::add(std::unique_ptr<SceneObject> object) {
  m_objects.push_back(std::move(object));
}

const std::vector<std::unique_ptr<SceneObject>> &Scene::objects() const {
  return m_objects;
}
