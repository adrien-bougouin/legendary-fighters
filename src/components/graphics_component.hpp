#ifndef __COMPONENTS_GRAPHICS_COMPONENT_HPP__
#define __COMPONENTS_GRAPHICS_COMPONENT_HPP__

#include "../core/graphics.hpp"

class GameEntity;

class GraphicsComponent {
  public:
    void update(GameEntity &game_entity, Graphics *graphics, const double &elapsed_frames);
};

#endif //  __COMPONENTS_GRAPHICS_COMPONENT_HPP__

