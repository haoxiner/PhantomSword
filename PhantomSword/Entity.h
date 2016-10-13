#pragma once
#include "PositionComponent.h"
#include "MoveComponent.h"
#include "Components.h"
#include <vector>
#include <set>
#include <string>

class Entity
{
public:
  virtual void Update(float deltaTime) = 0;
  template<class T> void AddComponent(T *component)
  {
    component->entity_ = this;
    components_.push_back(component);
    componentIndices_[T::TYPE] = components_.size() - 1;
  }
protected:
  template<class T> T *GetComponent() {
    return reinterpret_cast<T*>(components_[componentIndices_[T::TYPE]]);
  }
private:
  int componentIndices_[Component::NUM_OF_COMPONENTS];
  std::vector<Component*> components_;
};