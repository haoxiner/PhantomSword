#include "Player.h"

Player::Player()
{
  moveComponent_ = GetComponent<MoveComponent>();
}

void Player::Update(float deltaTime)
{
  moveComponent_->velocity_ = glm::vec3(0.0f, 0.0f, -1.0f);
}
