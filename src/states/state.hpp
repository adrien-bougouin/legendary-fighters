#ifndef __STATES_STATE_HPP__
#define __STATES_STATE_HPP__

#include "../models/input.hpp"

class GameEntity;

class AState {
  public:
    // TODO remove
    static AState *standing_state;
    // TODO
    //static AState *walking_state;
    static AState *jumping_state;

    virtual AState *handle_input(GameEntity &game_entity, Input &input) = 0;
    // TODO update???
    // TODO render???

    virtual void enter(GameEntity &game_entity) {};
    virtual void leave(GameEntity &game_entity) {};
};

#endif // __STATES_STATE_HPP__

