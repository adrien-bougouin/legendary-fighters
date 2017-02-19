#include "game_entity.hpp"

GameEntity::GameEntity(): position_(0.0, 0.0), velocity_(0.0, 0.0),
                          inputs_component_(),
                          physics_component_(),
                          graphics_component_() {
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

InputsComponent &GameEntity::inputs_component() {
  return inputs_component_;
}


PhysicsComponent &GameEntity::physics_component() {
  return physics_component_;
}

GraphicsComponent &GameEntity::graphics_component() {
  return graphics_component_;
}

