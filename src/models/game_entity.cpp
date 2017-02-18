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

void GameEntity::process_input() {
  // TODO
}

void GameEntity::update() {
  // TODO
  position_.set_x((position_.x() * -1.0) + 20.0);
}

void GameEntity::render(Graphics &graphics) {
  // TODO
  graphics.draw_square(position_, 80.0);
}

