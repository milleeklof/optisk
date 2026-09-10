#pragma once

struct GLFWwindow;

class Window {
public:
  Window();
  ~Window();

  bool create(int width, int height, const char *title);
  void pollEvents();
  bool shouldClose() const;
  void swapBuffers();
  GLFWwindow *nativeHandle() const;

private:
  GLFWwindow *m_window;
};
