#ifndef __MODELS_GAME_ENTITY_HPP__
#define __MODELS_GAME_ENTITY_HPP__

#include "vector_2d.hpp"
#include "animation.hpp"
#include "../states/state.hpp"
#include "../components/frame_data_component.hpp"
#include "../components/inputs_component.hpp"
#include "../components/physics_component.hpp"
#include "../components/graphics_component.hpp"

class GameEntity {
  private:
    double walk_velocity_;
    double jump_velocity_;

    double direction_;
    Vector2D position_;
    Vector2D velocity_;

    AState *state_;
    // TODO do not hard code
    Animation animations_[3];

    FrameDataComponent frame_data_component_;
    InputsComponent inputs_component_;
    PhysicsComponent physics_component_;
    GraphicsComponent graphics_component_;

  public:
    GameEntity();

    // TODO tests
    double &walk_velocity();
    const double &walk_velocity() const;
    double &jump_velocity();
    const double &jump_velocity() const;

    double &direction();
    const double &direction() const;
    void set_direction(const double &direction);
    Vector2D &position();
    const Vector2D &position() const;
    Vector2D &velocity();
    const Vector2D &velocity() const;

    AState *state();
    const AState *state() const;
    void set_state(AState *state);

    Animation &current_animation();
    const Animation &current_animation() const;

    FrameDataComponent &frame_data_component();
    InputsComponent &inputs_component();
    PhysicsComponent &physics_component();
    GraphicsComponent &graphics_component();
};

#endif // __MODELS_GAME_ENTITY_HPP__

