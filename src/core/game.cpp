#include "game.hpp"
#include "../models/input.hpp"
#include "../utils/time.hpp"

const double Game::FRAME_RATE = 30.0;
const double Game::FRAME_MILLISECONDS = (1.0 / Game::FRAME_RATE) * 1000.0;

Game::Game(const std::string &name): name_(name), over_(true), inputs_(), graphics_(), game_entities_() {
}

void Game::run() {
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

    handle_inputs();
    while (lag >= FRAME_MILLISECONDS) {
      update();

      lag -= FRAME_MILLISECONDS;
    }
    render();
  }
}

void Game::handle_inputs() {
  Input input = inputs_.poll();

  if (input.type != InputType::NONE) {
    if (input.type == InputType::QUIT) {
      stop();
    } else {
      for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
        game_entities_[i].inputs_component().update(game_entities_[i], input);
      }
    }
  }
}

void Game::update() {
  for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
    // TODO add physics engine and every entities for collision detection
    game_entities_[i].physics_component().update(game_entities_[i]);
  }
}

void Game::render() {
  for (int i = 0; i < GAME_ENTITY_LIMIT; ++i) {
    game_entities_[i].graphics_component().update(game_entities_[i], graphics_);
  }
}

