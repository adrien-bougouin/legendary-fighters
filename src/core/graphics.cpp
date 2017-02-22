#include "graphics.hpp"

Graphics::Graphics(const std::string &window_title, const double &window_width, const double &window_height): window_width_(window_width), window_height_(window_height) {
  window_ = SDL_CreateWindow(
    window_title.c_str(),
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    window_width,
    window_height,
    SDL_WINDOW_SHOWN
  );

  if (window_ != NULL) {
    renderer_ = SDL_CreateRenderer(window_, -1, 0);

    if (renderer_ != NULL) {
      init_renderer();
      render();
    } else {
      SDL_DestroyWindow(window_);
    }
  }
}

Graphics::~Graphics() {
  if (renderer_ != NULL) {
    SDL_DestroyRenderer(renderer_);
  }

  if (window_ != NULL) {
    SDL_DestroyWindow(window_);
  }
}

bool Graphics::ready() const {
  return window_ != NULL && renderer_ != NULL;
}

void Graphics::init_renderer() {
  if (renderer_ != NULL) {
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
  }
}

void Graphics::render() {
  if (renderer_ != NULL) {
    SDL_RenderPresent(renderer_);
    init_renderer();
    SDL_RenderClear(renderer_);
  }
}

void Graphics::draw_rectangle(const Vector2D &position, const double &width, const double &height) {
  if (renderer_ != NULL) {
    SDL_Rect rectangle;

    rectangle.x = position.x();
    rectangle.y = position.y();
    rectangle.w = width;
    rectangle.h = height;

    project_rectangle_on_screen(rectangle);

    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer_, &rectangle);
  }
}

double Graphics::project_y_on_screen(const double &y) const {
  return window_height_ - y;
}

void Graphics::project_rectangle_on_screen(SDL_Rect &rectangle) const {
  rectangle.y = project_y_on_screen(rectangle.y + rectangle.h);
}

