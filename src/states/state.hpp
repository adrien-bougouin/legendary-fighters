#ifndef __STATES_STATE_HPP__
#define __STATES_STATE_HPP__

#include "../models/input.hpp"

class GameEntity;
class StandingState;
class WalkingState;
class JumpingState;

class AState {
  public:
    // TODO remove
    static StandingState standing_state;
    // TODO
    static WalkingState walking_state;
    static JumpingState jumping_state;

    virtual AState *handle_input(GameEntity &game_entity, Input &input) = 0;
    virtual AState *update(GameEntity &game_entity) = 0;
    // TODO render???

    virtual void enter(GameEntity &game_entity) {};
    virtual void leave(GameEntity &game_entity) {};
};

#endif // __STATES_STATE_HPP__

