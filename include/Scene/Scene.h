#pragma once
#include "Scene/SceneObject.h"
#include <memory>
#include <vector>

class Scene {
public:
  void add(std::unique_ptr<SceneObject> object);
  const std::vector<std::unique_ptr<SceneObject>> &objects() const;

private:
  std::vector<std::unique_ptr<SceneObject>> m_objects;
};
