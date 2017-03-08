#ifndef __STATES_JUMPING_HPP__
#define __STATES_JUMPING_HPP__

#include "state.hpp"
#include "../models/game_entity.hpp"
#include "../models/input.hpp"

class JumpingState: public AState {
  public:
    JumpingState(const int &id);

    AState *handle_input(GameEntity &game_entity, Input &input);
    AState *update(GameEntity &game_entity);

    void enter(GameEntity &game_entity);
};

#endif // __STATES_JUMPING_HPP__
