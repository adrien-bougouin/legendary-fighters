#include "graphics.hpp"

Graphics::Graphics(): window_(NULL), renderer_(NULL) {
  if (SDL_VideoInit(NULL) != 0) {
    // TODO initialisation error
  }

  atexit(SDL_Quit);
}

Graphics::~Graphics() {
  stop();
  SDL_VideoQuit();
}

void Graphics::start(const std::string &window_title, const int &window_width, const int &window_height) {
  window_ = SDL_CreateWindow(
    window_title.c_str(),
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    window_width,
    window_height,
    SDL_WINDOW_SHOWN
  );

  if (window_ == NULL) {
    // TODO error
    stop();
  }

  renderer_ = SDL_CreateRenderer(window_, -1, 0);

  if (renderer_ == NULL) {
    // TODO error
    stop();
  }
}

// TODO use a variadic cleanup function for SDL objects???
void Graphics::stop() {
  if (renderer_ != NULL) {
    SDL_DestroyRenderer(renderer_);
  }

  if (window_ != NULL) {
    SDL_DestroyWindow(window_);
  }
}

void Graphics::draw_square(const Vector2D &position, const double &width) {
  if (renderer_ != NULL) {
    SDL_Rect square;

    square.x = position.x();
    square.y = 480.0 + position.y() - width;
    square.w = width;
    square.h = width;

    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    SDL_RenderClear(renderer_);
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer_, &square);
    SDL_RenderPresent(renderer_);
  }
}

