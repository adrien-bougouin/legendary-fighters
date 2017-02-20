#include "physics_component.hpp"
#include "../models/game_entity.hpp"
#include "../models/vector_2d.hpp"

void PhysicsComponent::update(GameEntity &game_entity) {
  Vector2D &position = game_entity.position();
  Vector2D &velocity = game_entity.velocity();

  // TODO use vector translation instead to do this for y-axis too
  position.set_x((position.x() + velocity.x()));
  // use decelaration?
  velocity.set_x(0.0);
  velocity.set_y(0.0);
}

