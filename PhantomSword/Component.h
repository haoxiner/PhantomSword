#pragma once
// include entity.h caused a dependent loop
class Entity;

class Component
{
public:
  enum ComponentType
  {
    POSITION = 0,
    MOVE,
    MODEL,
    NUM_OF_COMPONENTS
  };
  Entity *entity_;
protected:
  Component() {}
private:
};