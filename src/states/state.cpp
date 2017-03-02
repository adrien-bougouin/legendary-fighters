#include "state.hpp"
#include "standing_state.hpp"
#include "walking_state.hpp"
#include "jumping_state.hpp"

StandingState AState::standing_state = StandingState();
WalkingState AState::walking_state = WalkingState();
JumpingState AState::jumping_state = JumpingState();

