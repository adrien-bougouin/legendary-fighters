#include <assert.h>

#include "game.hpp"
#include "../models/input.hpp"
#include "../utils/time.hpp"

const double Game::FRAME_RATE = 30.0;
const double Game::FRAME_MILLISECONDS = (1.0 / Game::FRAME_RATE) * 1000.0;

Game::Game(Inputs *inputs, Graphics *graphics): over_(true), inputs_(inputs), graphics_(graphics), entities_(), num_entities_(0) {
  // TODO from menus???
  add_entity(GameEntity());
}

void Game::run() {
  over_ = false;

  loop();
}

void Game::stop() {
  over_ = true;
}

void Game::add_entity(const GameEntity &entity) {
  assert(num_entities_ < GAME_ENTITY_LIMIT);

  entities_[num_entities_] = entity;
  ++num_entities_;
}

void Game::loop() {
  double previous_time = utils::time::milliseconds_since_epoch();
  double lag = 0.0;

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
    render(lag);
  }
}

void Game::handle_inputs() {
  if (inputs_ != NULL) {
    Input input = inputs_->poll();

    if (input.type != InputType::NONE) {
      if (input.type == InputType::QUIT) {
        stop();
      } else {
        for (int i = 0; i < num_entities_; ++i) {
          GameEntity &entity = entities_[i];

          entity.inputs_component().update(entity, input);
        }
      }
    }
  }
}

void Game::update() {
  // TODO if (physics_ != NULL) {
    for (int i = 0; i < num_entities_; ++i) {
      GameEntity &entity = entities_[i];

      // TODO add physics engine and every entities for collision detection
      entity.physics_component().update(entity);
      entity.set_state(entity.state()->update(entity));
    }
  // TODO }
}

void Game::render(const double &lag) {
  if (graphics_ != NULL) {
    for (int i = 0; i < num_entities_; ++i) {
      GameEntity &entity = entities_[i];

      entity.graphics_component().update(entity, graphics_, lag / FRAME_MILLISECONDS);
    }
    graphics_->render();
  }
}

