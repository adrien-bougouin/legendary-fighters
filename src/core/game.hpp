#ifndef __CORE_GAME_HPP__
#define __CORE_GAME_HPP__

#include "graphics.hpp"
#include "../model/game_entity.hpp"

class Game {
  private:
    bool over_;

    void loop();
  public:
    Game();
    void run();
    void quit();
};

#endif // __CORE_GAME_HPP__

