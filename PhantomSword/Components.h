#pragma once
#include "PositionComponent.h"
#include "MoveComponent.h"
#include <vector>

class Components
{
public:
  Components();
  ~Components();
  template<class T> int Add(T) { return -1; }
  template<> int Add<PositionComponent>(PositionComponent positionComponent)
  {
    positionComponents_.push_back(positionComponent);
    return positionComponents_.size() - 1;
  }
  template<> int Add<MoveComponent>(MoveComponent moveComponent)
  {
    moveComponents_.push_back(moveComponent);
    return moveComponents_.size() - 1;
  }

  template<class T> T *Get(int id) { return nullptr; }
  template<> PositionComponent *Get<PositionComponent>(int id) { return &positionComponents_[id]; }
  template<> MoveComponent *Get<MoveComponent>(int id) { return &moveComponents_[id]; }
private:
  std::vector<PositionComponent> positionComponents_;
  std::vector<MoveComponent> moveComponents_;
};