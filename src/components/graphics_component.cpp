#include "graphics_component.hpp"
#include "../models/game_entity.hpp"
#include "../models/vector_2d.hpp"

void GraphicsComponent::update(GameEntity &game_entity, Graphics *graphics, const double &elapsed_frames) {
  // TODO render state
  Vector2D interpolated_position = game_entity.position();

  interpolated_position += game_entity.velocity() * elapsed_frames;

  // TODO image size
  graphics->blit_image(game_entity.animation(game_entity.state()->id()).current_frame(), 192.0, 192.0, interpolated_position);
}

