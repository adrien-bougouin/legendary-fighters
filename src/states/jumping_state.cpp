#include "jumping_state.hpp"
#include "standing_state.hpp"
#include "walking_state.hpp"

AState *JumpingState::handle_input(GameEntity &game_entity, Input &input) {
  return this;
}

AState *JumpingState::update(GameEntity &game_entity) {
  game_entity.velocity().set_y(0.0);

  // TODO use physics component?
  if (game_entity.position().y() == 0.0) {
    return &AState::standing_state;
  }

  return this;
}

void JumpingState::enter(GameEntity &game_entity) {
  game_entity.velocity().set_y(game_entity.jump_velocity());
}

