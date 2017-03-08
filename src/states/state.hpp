#ifndef __STATES_STATE_HPP__
#define __STATES_STATE_HPP__

#include "../models/input.hpp"

class GameEntity;
class StandingState;
class WalkingState;
class JumpingState;

class AState {
  private:
    int id_;
  public:
    // TODO remove
    static StandingState standing_state;
    static WalkingState walking_state;
    static JumpingState jumping_state;

    AState(const int &id);

    const int id() const;

    virtual AState *handle_input(GameEntity &game_entity, Input &input) = 0;
    virtual AState *update(GameEntity &game_entity) = 0;
    // TODO render???

    virtual void enter(GameEntity &game_entity) {};
    virtual void leave(GameEntity &game_entity) {};
};

#endif // __STATES_STATE_HPP__

