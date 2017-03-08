#include "state.hpp"
#include "standing_state.hpp"
#include "walking_state.hpp"
#include "jumping_state.hpp"

StandingState AState::standing_state = StandingState(0);
WalkingState AState::walking_state = WalkingState(1);
JumpingState AState::jumping_state = JumpingState(2);

AState::AState(const int &id): id_(id) {
}

const int AState::id() const {
  return id_;
}

