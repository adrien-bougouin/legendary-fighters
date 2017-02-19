#include "graphics_component.hpp"
#include "../models/game_entity.hpp"

void GraphicsComponent::update(GameEntity &game_entity, Graphics &graphics) {
  graphics.draw_square(game_entity.position(), 80.0);
}

