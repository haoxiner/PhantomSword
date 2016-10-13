#pragma once
#include "Component.h"
#include <glm/glm.hpp>

class MoveComponent : public Component
{
public:
  MoveComponent();
  ~MoveComponent();
  virtual ComponentType GetType() { return MOVE; }
  glm::vec3 velocity_;
};