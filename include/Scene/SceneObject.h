#pragma once
#include <string>
#include <utility> // For std::move

struct Transform {
  double x = 0, y = 0, z = 0;
  double xrot = 0, yrot = 0, zrot = 0;
};

class SceneObject {
public:
  virtual ~SceneObject() = default;
  virtual void render() = 0;

  explicit SceneObject(std::string name) : m_name(std::move(name)) {}
  const std::string &name() const { return m_name; }
  void setName(std::string name) { m_name = std::move(name); }

protected:
  std::string m_id;
  std::string m_name;
  Transform m_transform;
};
