#ifndef __STATES_STANDING_HPP__
#define __STATES_STANDING_HPP__

#include "state.hpp"
#include "../models/game_entity.hpp"
#include "../models/input.hpp"

class StandingState: public AState {
  public:
    AState *handle_input(GameEntity &game_entity, Input &input);
    AState *update(GameEntity &game_entity);

    void enter(GameEntity &game_entity);
};

#endif // __STATES_STANDING_HPP__
