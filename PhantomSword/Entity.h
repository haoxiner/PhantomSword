#pragma once
#include "PositionComponent.h"
#include "MoveComponent.h"
#include <map>

class Entity
{
public:
  virtual void Update(float deltaTime) = 0;
  template<class T> void AddComponent(T *component)
  {
    assert(components_.find(T::TYPE) != components_.endl());
    component->entity_ = this;
    components_[T::TYPE] = component;
  }
protected:
  template<class T> T *GetComponent() {
    assert(components_.find(T::TYPE) != components_.endl());
    return reinterpret_cast<T*>(components_[T::TYPE]);
  }
private:
  std::map<Component::ComponentType,Component*> components_;
};