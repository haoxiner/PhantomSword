#pragma once
#include "Component.h"
#include <vector>
#include <set>
#include <string>
class Entity
{
public:
  inline std::vector<Component*> &GetComponents() { return components_; }
  inline bool CheckSystem(const std::string &system) const { return relatedSystems_.find(system) != relatedSystems_.end(); }
protected:
  inline void Add(Component *component) { components_.push_back(component); }
  inline void Register(const std::string &system) { relatedSystems_.insert(system); }
private:
  std::vector<Component*> components_;
  std::set<const std::string> relatedSystems_;
};