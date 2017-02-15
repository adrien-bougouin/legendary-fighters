#include <math.h> // TODO remove

#include "game.hpp"
#include "../utils/time.hpp"

const double Game::FRAME_RATE = 30.0;
const double Game::FRAME_MILLISECONDS = (1.0 / Game::FRAME_RATE) * 1000.0;

Game::Game(const std::string &name): name_(name), over_(true), graphics_(), game_entities_() {
}

void Game::start() {
  over_ = false;

  graphics_.start(name_, 640, 480);
  loop();
}

void Game::stop() {
  over_ = true;

  graphics_.stop();
}

void Game::loop() {
  double previous_time = utils::time::milliseconds_since_epoch();
  double lag = 0.0;

  // TODO should not be here
  game_entities_[0] = GameEntity();

  while (!over_) {
    double current_time = utils::time::milliseconds_since_epoch();
    double elapsed_time = current_time - previous_time;

    previous_time = current_time;
    lag += elapsed_time;

    process_inputs();
    if (lag >= FRAME_MILLISECONDS) {
      update();

      lag -= FRAME_MILLISECONDS;
    }
    render();
  }
}

void Game::process_inputs() {
  for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
    // TODO game_entities_[i].inputs.update(game_entities_[i]);
    game_entities_[i].process_input();
  }
}

void Game::update() {
  for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
    // TODO game_entities_[i].physics.update(game_entities_, physics_); // TODO game_entities_ should be state before any entity's update
    game_entities_[i].update();
  }
}

void Game::render() {
  for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
    // TODO game_entities_[i].graphics.update(game_entities_[i], graphics_);
    game_entities_[i].render(graphics_);
  }
}

