#include "Engine.h"
#include "Display.h"

#include "Player.h"
#include "RawModel.h"
#include "Loader.h"
#include "ModelComponent.h"

#include "RenderSystem.h"
#include "MoveSystem.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int WINAPI wWinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  PWSTR pCmdLine,
  int nCmdShow)
{
  Display display;
  if (!display.Initialize())
  {
    return -1;
  }
  
  ModelComponent modelComponent;
  
  Assimp::Importer importer;
  const aiScene *scene = importer.ReadFile("D:/GameDev/Resources/Akai_E_Espiritu.fbx", aiProcessPreset_TargetRealtime_Fast);
  
  for (int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++)
  {
    aiMesh *mesh = scene->mMeshes[meshIndex];
    std::vector<float> vertices;
    std::vector<int> indices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    for (int i = 0; i < mesh->mNumVertices; i++)
    {
      vertices.push_back(mesh->mVertices[i].x);
      vertices.push_back(mesh->mVertices[i].y);
      vertices.push_back(mesh->mVertices[i].z);

      normals.push_back(mesh->mNormals[i].x);
      normals.push_back(mesh->mNormals[i].y);
      normals.push_back(mesh->mNormals[i].z);

      texCoords.push_back(mesh->mTextureCoords[0][i].x);
      texCoords.push_back(mesh->mTextureCoords[0][i].y);
    }
    for (int i = 0; i < mesh->mNumFaces; i++)
    {
      indices.push_back(mesh->mFaces[i].mIndices[0]);
      indices.push_back(mesh->mFaces[i].mIndices[1]);
      indices.push_back(mesh->mFaces[i].mIndices[2]);
    }
    Loader loader;
    modelComponent.rawModels_.push_back(loader.LoadToVAO(vertices, normals, texCoords, indices));
  }
  PositionComponent positionComponent;
  MoveComponent moveComponent;
  StaticShader staticShader;
  modelComponent.staticShader_ = &staticShader;

  Engine engine;
  Player player;
  engine.Add(&player);
  player.AddComponent(modelComponent);
  player.AddComponent(positionComponent);
  player.AddComponent(moveComponent);
  engine.Add(new RenderSystem());
  engine.Add(new MoveSystem());
  
  while (display.IsRunning())
  {
    float deltaTime = display.GetDelta();
    engine.Update(deltaTime);
    display.Update();
  }
  return 0;
}