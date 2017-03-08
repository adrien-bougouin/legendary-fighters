#include "game_entity.hpp"
#include "../states/standing_state.hpp"

GameEntity::GameEntity(): walk_velocity_(20.0), jump_velocity_(160.0), // TODO send to constructor
                          direction_(1.0),
                          position_(0.0, 0.0), velocity_(0.0, 0.0),
                          state_(&AState::standing_state), // TODO should not be static
                          animations_(),
                          inputs_component_(),
                          physics_component_(),
                          graphics_component_() {
  animations_[0] = Animation();
  animations_[1] = Animation();
  animations_[2] = Animation();
}

const double &GameEntity::walk_velocity() const {
  return walk_velocity_;
}

double &GameEntity::walk_velocity() {
  return walk_velocity_;
}

const double &GameEntity::jump_velocity() const {
  return jump_velocity_;
}

double &GameEntity::jump_velocity() {
  return jump_velocity_;
}

double &GameEntity::direction() {
  return direction_;
}

const double &GameEntity::direction() const {
  return direction_;
}

void GameEntity::set_direction(const double &direction) {
  direction_ = direction;
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

AState *GameEntity::state() {
  return state_;
}

const AState *GameEntity::state() const {
  return state_;
}

void GameEntity::set_state(AState *state) {
  if (state_ != state) {
    state_->leave(*this);

    // TODO handle pointer if states are not static
    state_ = state;

    state_->enter(*this);
  }
}

// TODO error check
Animation &GameEntity::animation(const int &id) {
  return animations_[id];
}

// TODO error check
const Animation &GameEntity::animation(const int &id) const {
  return animations_[id];
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

