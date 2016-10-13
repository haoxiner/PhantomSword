#include "Player.h"

Player::Player()
{
  positionComponent_ = GetComponent<PositionComponent>();
  moveComponent_ = GetComponent<MoveComponent>();
  modelComponent_ = GetComponent<ModelComponent>();
}

void Player::Update(float deltaTime)
{
  moveComponent_->velocity_ = glm::vec3(0.0f, 0.0f, -1.0f);
}
