#pragma once
#include "Entity.h"
#include "PositionComponent.h"
#include "MoveComponent.h"

class Player : public Entity
{
public:
  Player();
  virtual void Update(float deltaTime);
private:
  PositionComponent *positionComponent_;
  MoveComponent *moveComponent_;
};