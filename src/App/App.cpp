#include "App/App.h"
#include <glad/gl.h>

void App::run() {
  if (!m_window.create(1280, 720, "Optisk")) {
    return;
  }
  while (!m_window.shouldClose()) {
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    m_window.swapBuffers();

    m_window.pollEvents();
  }
}
