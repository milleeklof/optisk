#pragma once
#include "Core/Window.h"
#include "Scene/Scene.h"

class App {
public:
  void run();

private:
  Window m_window;
  Scene m_scene;
};
