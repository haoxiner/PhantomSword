#pragma once
#include "Entity.h"
#include "System.h"

#include <vector>
class Engine
{
public:
  void Update(float deltaTime);
  void AddEntity(Entity *entity) { entities_.push_back(entity); }
  void AddSystem(System *system) { systems_.push_back(system); }
  void Remove(Entity *entity);
private:
  std::vector<Entity*> entities_;
  std::vector<System*> systems_;
};