#include "standing_state.hpp"
#include "walking_state.hpp"
#include "jumping_state.hpp"
#include "../models/vector_2d.hpp"

StandingState::StandingState(const int &id): AState(id) {
}

AState *StandingState::handle_input(GameEntity &game_entity, Input &input) {
  switch (input.type) {
    case InputType::LEFT:
      if (input.method == InputMethod::PUSH) {
        game_entity.set_direction(-1);
        return &AState::walking_state;
      }
      break;
    case InputType::RIGHT:
      if (input.method == InputMethod::PUSH) {
        game_entity.set_direction(1);
        return &AState::walking_state;
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

AState *StandingState::update(GameEntity &game_entity) {
  return this;
}

void StandingState::enter(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();

  velocity.set_x(0.0);
  velocity.set_y(0.0);
}

