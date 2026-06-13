# Optisk - A free, open source program for rapid prototyping and visualization of optical systems
Optisk is a modern open-source optical design and visualization platform.

It allows students, researchers and engineers to rapidly prototype optical systems through an interactive graphical interface, combining real-time visualization, ray tracing and optical analysis in a single environment.

The goal is not to replace industrial optical design software, but to provide a more intuitive and visually-driven workflow for exploring, understanding and developing optical systems.



### File hierarchy
- src/App: Starts the program, runs the loop, shutdown
- src/GUI: Imgui, panels, Menus
- src/Scene: Objects in the scene
- src/Renderer: OpenGL, camera, meshes, renderers
- src/Optics: Lenses, mirrors, materials, ray tracing
- src/Core: Things that don't go anywhere else

