#include "jumping_state.hpp"
#include "../models/vector_2d.hpp"

AState *JumpingState::handle_input(GameEntity &game_entity, Input &input) {
  // TODO should not do like that
  if (game_entity.position().y() == 0.0) {
    if (input.type == InputType::UP && input.method == InputMethod::PUSH) {
      jump(game_entity);
    } else {
      // TODO should be able to come back to standing state by another way
      return AState::standing_state;
    }
  }

  return this;
}

void JumpingState::enter(GameEntity &game_entity) {
  jump(game_entity);
}

void JumpingState::jump(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();

  velocity.set_y(80.0); // TODO use jumping acceleration
}

