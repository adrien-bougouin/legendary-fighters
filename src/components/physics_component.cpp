#include "physics_component.hpp"
#include "../models/game_entity.hpp"
#include "../models/vector_2d.hpp"

void PhysicsComponent::update(GameEntity &game_entity) {
  Vector2D &position = game_entity.position();

  position.set_x((position.x() * -1.0) + 20.0);
}

