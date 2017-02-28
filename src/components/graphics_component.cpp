#include "graphics_component.hpp"
#include "../models/game_entity.hpp"

void GraphicsComponent::update(GameEntity &game_entity, Graphics *graphics) {
  // TODO render state
  graphics->draw_rectangle(game_entity.position(), 80.0, 80.0);
}

