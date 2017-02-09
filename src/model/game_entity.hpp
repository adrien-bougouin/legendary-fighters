#ifndef __MODEL_GAME_ENTITY_HPP__
#define __MODEL_GAME_ENTITY_HPP__

#include "vector_2d.hpp"

class GameEntity {
  private:
    Vector2D position_;
    Vector2D velocity_;

  public:
    GameEntity();

    Vector2D &position();
    const Vector2D &position() const;
    Vector2D &velocity();
    const Vector2D &velocity() const;
};

#endif // __MODEL_GAME_ENTITY_HPP__

