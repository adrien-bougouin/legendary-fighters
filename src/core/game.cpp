#include <math.h> // TODO remove

#include "game.hpp"
#include "../utils/time.hpp"

const double Game::FRAME_RATE = 30.0;
const double Game::FRAME_MILLISECONDS = (1.0 / Game::FRAME_RATE) * 1000.0;

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
  int rec_limit = 0; // TODO remove
  double previous_time = utils::time::milliseconds_since_epoch();
  double lag = 0.0;

  game_entities_[0] = GameEntity();

  while (!over_) {
    double current_time = utils::time::milliseconds_since_epoch();
    double elapsed_time = current_time - previous_time;

    previous_time = current_time;
    lag += elapsed_time;

    // process input
    // TODO

    // update
    if (lag >= FRAME_MILLISECONDS) {
      for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
        Vector2D &position = game_entities_[i].position();

        // change position every second
        if (fmod(rec_limit, FRAME_RATE) == 0.0) { // TODO remove
          position.set_x((position.x() * -1.0) + 20.0);
        }
      }

      lag -= FRAME_MILLISECONDS;

      // TODO remove
      ++rec_limit;
      if (rec_limit == FRAME_RATE * 10.0) quit();
    }

    // render
    for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
      Vector2D &position = game_entities_[i].position();

      graphics_engine_.draw_square(position, 80.0);
    }
  }
}

