#include <unistd.h>

#include "game.hpp"

Game::Game(): graphics_engine_(), game_entities_(), over_(true) {
}

void Game::run() {
  over_ = false;

  graphics_engine_.start("Legendary Fighters", 640, 480);
  loop();
}

void Game::quit() {
  over_ = true;

  graphics_engine_.stop();
}

void Game::loop() {
  int rec_limit = 0;

  game_entities_[0] = GameEntity();

  while (!over_) {
    // process input

    // update
    for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
      Vector2D &position = game_entities_[i].position();

      position.set_x((position.x() * -1.0) + 20.0);
    }

    // render
    for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
      Vector2D &position = game_entities_[i].position();

      graphics_engine_.draw_square(position, 80.0);
    }

    sleep(1);

    ++rec_limit;
    if (rec_limit == 10) quit();
  }
}

