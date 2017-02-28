#include "state.hpp"
#include "standing_state.hpp"
//#include "walking_state.hpp"
#include "jumping_state.hpp"

AState *AState::standing_state = new StandingState();
// TODO
//AState *AState::walking_state = new WalkingState();
AState *AState::jumping_state = new JumpingState();

