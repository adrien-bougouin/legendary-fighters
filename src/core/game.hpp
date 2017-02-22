#ifndef __CORE_GAME_HPP__
#define __CORE_GAME_HPP__

#include "inputs.hpp"
#include "graphics.hpp"
#include "../models/game_entity.hpp"

class Game {
  private:
    static const int GAME_ENTITY_LIMIT = 1;
    GameEntity game_entities_[GAME_ENTITY_LIMIT];

    bool over_;

    Inputs *inputs_;
    // TODO Physics physics_;
    Graphics *graphics_;

    void loop();
    void handle_inputs();
    void update();
    void render();
  public:
    static const double FRAME_RATE;
    static const double FRAME_MILLISECONDS;

    Game(Inputs *inputs, Graphics *graphics);

    void run();
    void stop();
};

#endif // __CORE_GAME_HPP__

