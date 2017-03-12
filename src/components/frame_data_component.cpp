#include "frame_data_component.hpp"
#include "../models/game_entity.hpp"

void FrameDataComponent::update(GameEntity &game_entity) {
  // TODO use current state's frame data to setup velocity
}

void FrameDataComponent::goto_next_frame(GameEntity &game_entity) {
  game_entity.set_state(game_entity.state()->update(game_entity));
  game_entity.current_animation().update();
}

