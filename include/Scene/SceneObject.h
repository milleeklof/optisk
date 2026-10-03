#pragma once
#include <string>

struct Transform {
  double x = 0, y = 0, z = 0;
  double xrot = 0, yrot = 0, zrot = 0;
};

class SceneObject {
public:
  SceneObject() = default;
  virtual ~SceneObject() = default;
  virtual void render() = 0;

protected:
  std::string m_id;
  std::string m_name;
  Transform m_transform;
};
