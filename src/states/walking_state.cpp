#include "walking_state.hpp"
#include "standing_state.hpp"
#include "jumping_state.hpp"

AState *WalkingState::handle_input(GameEntity &game_entity, Input &input) {
  switch (input.type) {
    case InputType::LEFT:
      if (input.method == InputMethod::RELEASE) {
        return &AState::standing_state;
      }
      break;
    case InputType::RIGHT:
      if (input.method == InputMethod::RELEASE) {
        return &AState::standing_state;
      }
      break;
    case InputType::UP:
      if (input.method == InputMethod::PUSH) {
        return &AState::jumping_state;
      }
      break;
    default:
      break;
  }

  return this;
}

AState *WalkingState::update(GameEntity &game_entity) {
  return this;
}

void WalkingState::enter(GameEntity &game_entity) {
  double oriented_velocity = game_entity.direction() * game_entity.walk_velocity();

  game_entity.velocity().set_x(oriented_velocity);
}

