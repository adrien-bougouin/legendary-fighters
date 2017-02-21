#include "inputs_component.hpp"
#include "../models/game_entity.hpp"

void InputsComponent::update(GameEntity &game_entity, Input input) {
  Vector2D &velocity = game_entity.velocity();

  switch (input.type) {
    case InputType::LEFT:
      if (input.method == InputMethod::PUSH) {
        velocity.set_x(velocity.x() - 1.0); // TODO use acceleration
      } else if (input.method == InputMethod::RELEASE) {
        velocity.set_x(0.0);
      }
      break;
    case InputType::RIGHT:
      if (input.method == InputMethod::PUSH) {
        velocity.set_x(velocity.x() + 1.0); // TODO use acceleration
      } else if (input.method == InputMethod::RELEASE) {
        velocity.set_x(0.0);
      }
      break;
    default:
      break;
  }
}

