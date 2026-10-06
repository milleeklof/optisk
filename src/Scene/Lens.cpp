#include "Scene/Lens.h"
#include <iostream>
#include <string>
#include <utility> // For std::move

Lens::Lens(std::string name) : SceneObject(std::move(name)) {}

void Lens::render() { std::cout << "Rendering lens\n"; }
