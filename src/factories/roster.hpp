#ifndef __FACTORIES_ROSTER_HPP__
#define __FACTORIES_ROSTER_HPP__

#include "../models/game_entity.hpp"

class Roster {
  public:
    // TODO should probably move on to pointer
    static GameEntity create_daigo();
};

#endif // __FACTORIES_ROSTER_HPP__

