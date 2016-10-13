#include "Engine.h"

void Engine::Update(float deltaTime)
{
  for (auto system : systems_)
  {
    system->Update(deltaTime);
  }
}

void Engine::Remove(Entity *entity)
{
  
}
