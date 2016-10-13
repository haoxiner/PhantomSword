#pragma once
#include "Component.h"
#include <glm/glm.hpp>

class PositionComponent : public Component
{
public:
  static const ComponentType TYPE = POSITION;
private:
  glm::vec3 position_;
  float rotateX_, rotateY_, rotateZ_;
};