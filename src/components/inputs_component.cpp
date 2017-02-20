#include "inputs_component.hpp"
#include "../models/game_entity.hpp"

void InputsComponent::update(GameEntity &game_entity, Input input) {
  Vector2D &velocity = game_entity.velocity();

  switch (input.type) {
    case InputType::LEFT:
      // TODO set += and -= operators for vector translation
      velocity.set_x(velocity.x() - 20.0); // TODO use acceleration
      break;
    case InputType::RIGHT:
      velocity.set_x(velocity.x() + 20.0); // TODO use acceleration
      break;
    default:
      break;
  }
}

