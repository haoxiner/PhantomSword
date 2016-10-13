#pragma once
#include "RawModel.h"
#include "StaticShader.h"

#include <vector>
class ModelComponent : public Component
{
public:
  static const ComponentType TYPE = MODEL;
  std::vector<RawModel*> rawModels_;
  StaticShader *staticShader_;
};