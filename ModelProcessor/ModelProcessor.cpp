
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <fstream>
#include <sstream>
#include <random>
#include <queue>
#include <map>
#include <vector>
#include <iostream>

glm::mat4 world2RootBone;
glm::mat4 rootBone2World;
std::vector<glm::mat4> *boneTransform;
std::map<std::string, int> boneMap;
std::vector<glm::mat4> *boneMatrix;
std::map<std::string, aiNodeAnim*> keyFrameMap;

glm::mat4 makeMat4FromMat4(aiMatrix4x4 m)
{
  return glm::mat4(
    m.a1, m.b1, m.c1, m.d1,
    m.a2, m.b2, m.c2, m.d2,
    m.a3, m.b3, m.c3, m.d3,
    m.a4, m.b4, m.c4, m.d4);
}
glm::mat4 makeMat4FromMat3(aiMatrix3x3 m)
{
  return glm::mat4(
    m.a1, m.b1, m.c1, 0.0f,
    m.a2, m.b2, m.c2, 0.0f,
    m.a3, m.b3, m.c3, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f);
}

void exportTextures(aiScene *scene)
{
  if (scene)
  {
    std::cout << "Number Of Meshes: " << scene->mNumMeshes << std::endl;
    std::cout << scene->mNumTextures << std::endl;

    for (int i = 0; i < scene->mNumTextures; i++)
    {
      std::string filename = "D:/";
      std::ostringstream oss;
      oss << i;
      filename += oss.str();
      filename += ".jpg";
      std::ofstream file(filename, std::ios::binary);
      file.write((char*)scene->mTextures[i]->pcData, scene->mTextures[i]->mWidth);
      file.close();
    }
  }
}

void CalcMaxBonesPerVertex(aiScene *scene)
{
  if (scene)
  {
    std::cout << "Number Of Meshes: " << scene->mNumMeshes << std::endl;

    for (int i = 0; i < scene->mNumMeshes; i++)
    {
      auto mesh = scene->mMeshes[i];
      std::map<int, int> total;
      for (int j = 0; j < mesh->mNumBones; j++)
      {
        auto bone = mesh->mBones[j];
        for (int k = 0; k < bone->mNumWeights; k++)
        {
          total[bone->mWeights[k].mVertexId]++;
        }
      }
      int max = -1000;
      for (auto p : total)
      {
        max = std::max(max, p.second);
      }
      std::cout << max << std::endl;
    }
  }
}
int main()
{
  std::cout << "Input File Path: ";
  std::string filepath;
  while (std::cin >> filepath)
  {
    if (filepath == "q")
    {
      break;
    }
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filepath, aiProcessPreset_TargetRealtime_Fast);
    if (scene)
    {
      std::cout << "Number Of Meshes: " << scene->mNumMeshes << std::endl;
      
    }
    else
    {
      std::cout << "Failed To Read" << std::endl;
    }
    std::cout << "Input File Path: ";
  }
  return 0;
}
