#include "game_entity.hpp"

GameEntity::GameEntity(): position_(0.0, 0.0), velocity_(0.0, 0.0) {
}

Vector2D &GameEntity::position() {
  return position_;
}

const Vector2D &GameEntity::position() const {
  return position_;
}

Vector2D &GameEntity::velocity() {
  return velocity_;
}

const Vector2D &GameEntity::velocity() const {
  return velocity_;
}

