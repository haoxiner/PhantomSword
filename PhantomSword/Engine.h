#pragma once
#include "Entity.h"
#include "System.h"

#include <vector>
class Engine
{
public:
  Engine();
  ~Engine();
  void Add(Entity *entity) { entities_.push_back(entity); }
  void Add(System *system) { systems_.push_back(system); }
private:
  std::vector<Entity*> entities_;
  std::vector<System*> systems_;
};