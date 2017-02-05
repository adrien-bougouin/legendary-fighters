#include "graphics.hpp"

Graphics::Graphics(): window_(NULL), renderer_(NULL) {
  if (SDL_VideoInit(NULL) != 0) {
    // TODO initialisation error
  }
}

Graphics::~Graphics() {
  stop();
  SDL_VideoQuit();
}

void Graphics::start() {
  // TODO customize
  window_ = SDL_CreateWindow("Legendary Fighters", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

  if (window_ == NULL) {
    // TODO error
  }

  renderer_ = SDL_CreateRenderer(window_, -1, 0);

  if (renderer_ == NULL) {
    // TODO error
  }
}

void Graphics::stop() {
  if (renderer_ != NULL) {
    SDL_DestroyRenderer(renderer_);
  }

  if (window_ != NULL) {
    SDL_DestroyWindow(window_);
  }
}

