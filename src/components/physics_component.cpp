#include "physics_component.hpp"
#include "../models/game_entity.hpp"
#include "../models/vector_2d.hpp"

void PhysicsComponent::update(GameEntity &game_entity) {
  Vector2D &position = game_entity.position();
  Vector2D &velocity = game_entity.velocity();

  position += velocity;

  // TODO replace by proper collision
  if (position.y() < 0.0) {
    position.set_y(0.0);
  }
}

