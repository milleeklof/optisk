#include "GUI/EditorLayout.h"
#include "imgui_internal.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Scene;

void EditorLayout::init(GLFWwindow *window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 410");
}

void EditorLayout::beginFrame(const Scene &scene) {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGuiID dockspaceId =
      ImGui::DockSpaceOverViewport(0, nullptr, ImGuiDockNodeFlags_None);

  // Creates the positions of the panels only on the first frame.
  static bool firstFrame = true;
  if (firstFrame) {
    firstFrame = false;

    ImGui::DockBuilderRemoveNode(dockspaceId);
    ImGui::DockBuilderAddNode(dockspaceId, ImGuiDockNodeFlags_DockSpace);
    ImGui::DockBuilderSetNodeSize(dockspaceId, ImGui::GetMainViewport()->Size);

    ImGuiID dockMain = dockspaceId;
    ImGuiID dockLeft = ImGui::DockBuilderSplitNode(dockMain, ImGuiDir_Left,
                                                   0.2f, nullptr, &dockMain);
    ImGuiID dockRight = ImGui::DockBuilderSplitNode(dockMain, ImGuiDir_Right,
                                                    0.25f, nullptr, &dockMain);
    ImGuiID dockBottom = ImGui::DockBuilderSplitNode(dockMain, ImGuiDir_Down,
                                                     0.25f, nullptr, &dockMain);

    ImGui::DockBuilderDockWindow("Scene", dockLeft);
    ImGui::DockBuilderDockWindow("Properties", dockRight);
    ImGui::DockBuilderDockWindow("Analysis", dockBottom);
    ImGui::DockBuilderDockWindow("Viewport", dockMain);

    ImGui::DockBuilderFinish(dockspaceId);
  }

  m_scenePanel.draw(scene);
  m_viewportPanel.draw();
  m_propertiesPanel.draw();
  m_analysisPanel.draw();
}

void EditorLayout::render() {
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void EditorLayout::shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
