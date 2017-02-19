#ifndef __COMPONENTS_INPUTS_COMPONENT_HPP__
#define __COMPONENTS_INPUTS_COMPONENT_HPP__

#include "../core/inputs.hpp"

class GameEntity;

class InputsComponent {
  public:
    void update(GameEntity &game_entity, InputType input_type);
};

#endif // __COMPONENTS_INPUTS_COMPONENT_HPP__

