#include "inputs_component.hpp"
#include "../models/game_entity.hpp"

void InputsComponent::update(GameEntity &game_entity, Input &input) {
  switch (input.type) {
    case InputType::LEFT:
      if (input.method == InputMethod::PUSH) {
        game_entity.physics_component().move_left(game_entity);
      } else if (input.method == InputMethod::RELEASE) {
        game_entity.physics_component().stop_horizontal_motion(game_entity);
      }
      break;
    case InputType::RIGHT:
      if (input.method == InputMethod::PUSH) {
        game_entity.physics_component().move_right(game_entity);
      } else if (input.method == InputMethod::RELEASE) {
        game_entity.physics_component().stop_horizontal_motion(game_entity);
      }
      break;
    case InputType::UP:
      if (input.method == InputMethod::PUSH) {
        // if not already jumping
        if (game_entity.position().y() == 0.0) { // TODO remove this check
          game_entity.physics_component().jump(game_entity);
        } else {
          game_entity.physics_component().stop_vertical_motion(game_entity);
        }
      } else if (input.method == InputMethod::RELEASE) {
        game_entity.physics_component().stop_vertical_motion(game_entity);
      }
      break;
    default:
      break;
  }
}

