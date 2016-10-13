#pragma once
#include "PositionComponent.h"
#include "MoveComponent.h"
#include "ModelComponent.h"
#include <vector>

class Components
{
public:
  template<class T> int Add(T) { return -1; }
  template<> int Add<PositionComponent>(PositionComponent positionComponent)
  {
    positionComponents_.push_back(positionComponent);
    return static_cast<int>(positionComponents_.size() - 1);
  }
  template<> int Add<MoveComponent>(MoveComponent moveComponent)
  {
    moveComponents_.push_back(moveComponent);
    return static_cast<int>(moveComponents_.size() - 1);
  }
  template<> int Add<ModelComponent>(ModelComponent modelComponent)
  {
    modelComponent_.push_back(modelComponent);
    return static_cast<int>(modelComponent_.size() - 1);
  }

  template<class T> T *Get(int id) { return nullptr; }
  template<> PositionComponent *Get<PositionComponent>(int id) { return &positionComponents_[id]; }
  template<> MoveComponent *Get<MoveComponent>(int id) { return &moveComponents_[id]; }
  template<> ModelComponent *Get<ModelComponent>(int id) { return &modelComponent_[id]; }
private:
  std::vector<PositionComponent> positionComponents_;
  std::vector<MoveComponent> moveComponents_;
  std::vector<ModelComponent> modelComponent_;
};