cmake_minimum_required(VERSION 3.20)

project(Optisk)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/glfw)

add_executable(Optisk
    src/App/main.cpp
    src/App/App.cpp
    src/Core/Window.cpp
    src/GUI/EditorLayout.cpp
    src/GUI/ScenePanel.cpp
    src/GUI/AnalysisPanel.cpp
    src/GUI/ViewportPanel.cpp
    src/GUI/PropertiesPanel.cpp

    external/glad/src/gl.c

    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_demo.cpp

external/imgui/backends/imgui_impl_glfw.cpp
external/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(Optisk PRIVATE
    include

    external/glad/include

    external/imgui
    external/imgui/backends
)

target_link_libraries(Optisk PRIVATE glfw)
