#pragma once
#include "Component.h"
#include "PositionComponent.h"
#include "MoveComponent.h"
#include "Components.h"
#include <vector>
#include <set>
#include <string>

class Entity
{
public:
  virtual void Update(float deltaTime);
  template<class T> void AddComponent(T component)
  {
    assert(componentIndices_[T.GetType()] != -1);
    componentIndices_[T.GetType()] = components_.Add<T>(component);
  }
protected:
  template<class T> inline T *GetComponent() {
    assert(componentIndices_[T.GetType()] != -1);
    return components_.Get<T>(componentIndices_[T.GetType()]);
  }
private:
  int componentIndices_[Component::NUM_OF_COMPONENTS];
  static Components components_;
};