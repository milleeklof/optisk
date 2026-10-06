#include "GUI/ScenePanel.h"
#include "Scene/Scene.h"
#include "imgui.h"

class Scene;

void ScenePanel::draw(const Scene &scene) {
  ImGui::Begin("Scene");

  for (const auto &obj : scene.objects()) {
    ImGui::Selectable(obj->name().c_str());
  }

  ImGui::End();
}
