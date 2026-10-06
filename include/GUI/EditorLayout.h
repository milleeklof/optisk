#pragma once

#include "GUI/AnalysisPanel.h"
#include "GUI/PropertiesPanel.h"
#include "GUI/ScenePanel.h"
#include "GUI/ViewportPanel.h"

struct GLFWwindow;

class Scene;

class EditorLayout {
public:
  void init(GLFWwindow *window);
  void beginFrame(const Scene &scene);
  void render();
  void shutdown();

private:
  ScenePanel m_scenePanel;
  PropertiesPanel m_propertiesPanel;
  AnalysisPanel m_analysisPanel;
  ViewportPanel m_viewportPanel;
};
