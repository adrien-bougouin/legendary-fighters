#include "physics_component.hpp"
#include "../models/game_entity.hpp"
#include "../models/vector_2d.hpp"

PhysicsComponent::PhysicsComponent(): max_x_velocity_(5.0), max_y_velocity_(40.0), x_acceleration_(5.0), y_acceleration_(40.0) {
}

void PhysicsComponent::update(GameEntity &game_entity) {
  Vector2D &position = game_entity.position();
  Vector2D &velocity = game_entity.velocity();

  position += velocity;

  // dumb gravity
  position.set_y(position.y() - 8.0);
  if (position.y() < 0.0) {
    position.set_y(0.0);
  }

  // reset
  velocity.set_x(0.0);
  velocity.set_y(0.0);
}

/* TODO remove
void PhysicsComponent::stop_horizontal_motion(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();

  velocity.set_x(0.0);
}

void PhysicsComponent::stop_vertical_motion(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();

  velocity.set_y(0.0);
}

void PhysicsComponent::move_left(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();
  double new_velocity = velocity.x() - x_acceleration_;

  if (new_velocity < -max_x_velocity_) {
    new_velocity = -max_x_velocity_;
  }

  velocity.set_x(new_velocity);
}

void PhysicsComponent::move_right(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();
  double new_velocity = velocity.x() + x_acceleration_;

  if (new_velocity > max_x_velocity_) {
    new_velocity = max_x_velocity_;
  }

  velocity.set_x(new_velocity);
}

void PhysicsComponent::jump(GameEntity &game_entity) {
  Vector2D &velocity = game_entity.velocity();
  double new_velocity = velocity.y() + y_acceleration_;

  if (new_velocity > max_y_velocity_) {
    new_velocity = max_y_velocity_;
  }

  velocity.set_y(new_velocity);
}
*/

