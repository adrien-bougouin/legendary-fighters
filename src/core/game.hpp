#ifndef __CORE_GAME_HPP__
#define __CORE_GAME_HPP__

#include <string>

#include "inputs.hpp"
#include "graphics.hpp"
#include "../models/game_entity.hpp"

class Game {
  private:
    static const int GAME_ENTITY_LIMIT = 1;

    const std::string name_;
    GameEntity game_entities_[GAME_ENTITY_LIMIT];
    bool over_;

    Inputs inputs_;
    Graphics graphics_;
    // TODO Physics physics_;

    void loop();
    void handle_inputs();
    void update();
    void render();
  public:
    static const double FRAME_RATE;
    static const double FRAME_MILLISECONDS;

    Game(const std::string &name);

    void run();
    void stop();
};

#endif // __CORE_GAME_HPP__

