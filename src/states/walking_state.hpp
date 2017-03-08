#ifndef __STATES_WALKING_HPP__
#define __STATES_WALKING_HPP__

#include "state.hpp"
#include "../models/game_entity.hpp"
#include "../models/input.hpp"

class WalkingState: public AState {
  public:
    WalkingState(const int &id);

    AState *handle_input(GameEntity &game_entity, Input &input);
    AState *update(GameEntity &game_entity);

    void enter(GameEntity &game_entity);
};

#endif // __STATES_WALKING_HPP__
