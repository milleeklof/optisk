#include "App/App.h"
#include "GUI/EditorLayout.h"
#include "Scene/Lens.h"
#include <glad/gl.h>

void App::run() {
  if (!m_window.create(1280, 720, "Optisk")) {
    return;
  }

  EditorLayout Editor;
  Editor.init(m_window.nativeHandle());

  m_scene.add(std::make_unique<Lens>("Lens 1"));

  while (!m_window.shouldClose()) {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Editor.beginFrame(m_scene);
    Editor.render();

    m_window.swapBuffers();
    m_window.pollEvents();
  }

  Editor.shutdown();
}
