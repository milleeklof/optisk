#pragma once
#include "Scene/SceneObject.h"
#include <string>

class Lens : public SceneObject {
public:
  Lens(std::string name);
  void render() override;

private:
  double m_frontRadius = 100.0; // Positive if convex (mm)
  double m_backRadius = -100.0; // Negative if convex (mm)
  double m_diameter = 50.0;
  double m_thickness = 5.0; // Center thickness
  double m_refractiveIndex = 1.5;
};
