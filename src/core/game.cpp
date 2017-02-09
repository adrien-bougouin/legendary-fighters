#include <unistd.h>

#include "game.hpp"

Game::Game(): over_(true) {
}

void Game::run() {
  over_ = false;

  loop();
}

void Game::quit() {
  over_ = true;
}

void Game::loop() {
  Graphics graphics_engine = Graphics();
  GameEntity game_entity = GameEntity();
  int limit = 0;

  graphics_engine.start();

  while (!over_) {
    Vector2D &position = game_entity.position();

    // process input
    // update
    position.set_x((position.x() * -1.0) + 20.0);
    // render
    graphics_engine.draw_square(position, 80.0);

    sleep(1);

    ++limit;
    if (limit == 10) quit();
  }
}

