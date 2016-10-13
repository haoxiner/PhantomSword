#pragma once
class Component
{
public:
  enum ComponentType
  {
    POSITION = 0,
    MOVE,
    NUM_OF_COMPONENTS
  };
  virtual ComponentType GetType() = 0;
private:
  Component(){}
};