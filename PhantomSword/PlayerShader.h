#pragma once
#include "Shader.h"
class PlayerShader : public Shader
{
public:
  PlayerShader();
  ~PlayerShader();
protected:
  virtual void BindAttributes();
  virtual void GetAllUniformLocations();
private:
  GLuint modelLocation_;
  GLuint viewLocation_;
  GLuint projectionLocation_;
  GLuint bonesLocation_;
};

