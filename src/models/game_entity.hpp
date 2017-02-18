#ifndef __MODEL_GAME_ENTITY_HPP__
#define __MODEL_GAME_ENTITY_HPP__

#include "../core/graphics.hpp" // TODO replace by GraphicsComponent
#include "vector_2d.hpp" // TODO move to PhysicsComponent

class GameEntity {
  private:
    Vector2D position_; // TODO move to PhysicsComponent
    Vector2D velocity_; // TODO move to PhysicsComponent

  public:
    GameEntity();

    Vector2D &position();
    const Vector2D &position() const;
    Vector2D &velocity();
    const Vector2D &velocity() const;

    // TODO replace by component getters
    void process_input();
    void update();
    void render(Graphics &graphics);
};

#endif // __MODEL_GAME_ENTITY_HPP__

