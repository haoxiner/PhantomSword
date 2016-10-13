#pragma once
#include "Component.h"
#include <glm/glm.hpp>

class MoveComponent : public Component
{
public:
  static const ComponentType TYPE = MOVE;
  glm::vec3 velocity_;
};