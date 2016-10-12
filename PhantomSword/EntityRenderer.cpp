#include "EntityRenderer.h"
#include <glm/gtc/matrix_transform.hpp>
EntityRenderer::EntityRenderer(StaticShader *staticShader, const glm::mat4 &projectionMatrix)
  :staticShader_(staticShader)
{
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  staticShader_->Use();
  staticShader_->LoadProjectionMatrix(projectionMatrix);
  staticShader_->Release();
}

EntityRenderer::~EntityRenderer()
{
}

void EntityRenderer::Render(std::map<const TexturedModel*, std::vector<const Entity*>> &entities)
{
  for (auto pair : entities)
  {
    const TexturedModel *model = pair.first;
    PrepareTexturedModel(model);
    for (auto entity : pair.second)
    {
      PrepareInstance(*entity);
      glDrawElements(GL_TRIANGLES, model->rawModel_->indicesCount_, GL_UNSIGNED_INT, 0);
    }
    UnbindTexturedModel();
  }
}

void EntityRenderer::PrepareTexturedModel(const TexturedModel * model)
{
  const RawModel *rawModel = model->rawModel_;
  const ModelTexture *texture = model->modelTexture_;
  glBindVertexArray(rawModel->vaoID_);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  glEnableVertexAttribArray(3);
  glEnableVertexAttribArray(4);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->textureID_);
}

void EntityRenderer::UnbindTexturedModel()
{
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
  glDisableVertexAttribArray(3);
  glDisableVertexAttribArray(4);
  glBindVertexArray(0);
}

void EntityRenderer::PrepareInstance(const Entity &entity)
{ 
  glm::mat4 m;
  m = glm::translate(m, entity.position_);
  m = glm::rotate(m, entity.rotation_.y, glm::vec3(0.0f, 1.0f, 0.0f));
  m = glm::rotate(m, entity.rotation_.x, glm::vec3(1.0f, 0.0f, 0.0f));
  m = glm::scale(m, glm::vec3(entity.scale_));
  staticShader_->LoadModelMatrix(m);
  staticShader_->LoadBones(*entity.bones_);
}
