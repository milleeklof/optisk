#include "Core/Window.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/gl.h>

Window::Window() : m_window(nullptr) {}

Window::~Window() {
  if (m_window) {
    glfwDestroyWindow(m_window);
  }

  glfwTerminate();
}

bool Window::create(int width, int height, const char *title) {
  if (!glfwInit()) {
    return false;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

  if (!m_window) {
    return false;
  }

  glfwMakeContextCurrent(m_window);
  if (!gladLoadGL(glfwGetProcAddress)) {
    return false;
  }
  return m_window != nullptr;
}

void Window::pollEvents() { glfwPollEvents(); }

bool Window::shouldClose() const { return glfwWindowShouldClose(m_window); }

void Window::swapBuffers() { glfwSwapBuffers(m_window); }
