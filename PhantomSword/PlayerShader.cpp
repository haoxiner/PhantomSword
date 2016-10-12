#include "PlayerShader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <fstream>
#include <sstream>

PlayerShader::PlayerShader()
{
  std::ifstream vShaderFile("./Shaders/player.vert.glsl");
  std::ostringstream vShaderStream;
  vShaderStream << vShaderFile.rdbuf();
  vShaderFile.close();
  std::string vertexShaderSource(vShaderStream.str());

  std::ifstream fShaderFile("./Shaders/player.frag.glsl");
  std::ostringstream fShaderStream;
  fShaderStream << fShaderFile.rdbuf();
  fShaderFile.close();
  std::string fragmentShaderSource(fShaderStream.str());

  Load(vertexShaderSource, fragmentShaderSource);
}

PlayerShader::~PlayerShader()
{
}

void PlayerShader::BindAttributes()
{
  BindAttribute(0, "position");
  BindAttribute(1, "normal");
  BindAttribute(2, "texCoord");
  BindAttribute(3, "boneIDs");
  BindAttribute(4, "boneWeights");
}

void PlayerShader::GetAllUniformLocations()
{
  modelLocation_ = GetUniformLocation("model");
  viewLocation_ = GetUniformLocation("view");
  projectionLocation_ = GetUniformLocation("projection");
  bonesLocation_ = GetUniformLocation("bones");
}
