#include "game.hpp"

Game::Game(): stopped_(true) {
}

void Game::start() {
  stopped_ = false;

  loop();
}

void Game::stop() {
  stopped_ = true;
}

void Game::loop() {
  while (!stopped_) { // TODO !stopped
    // process input
    // update
    // render
  }
}

