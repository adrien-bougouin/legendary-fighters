#include <SDL2/SDL_image.h>

#include "graphics.hpp"

Graphics::Graphics(const std::string &window_title, const double &window_width, const double &window_height): window_width_(window_width), window_height_(window_height), texture_cache_(30) {
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
  free_texture_cache();

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

void Graphics::blit_sprite(const Sprite &sprite, const Vector2D &position) {
  if (renderer_ != NULL) {
    SDL_Texture *texture = get_texture(sprite.sprite_sheet_filepath);
    SDL_Rect extraction_rectangle;
    SDL_Rect display_rectangle;

    extraction_rectangle.x = sprite.column * sprite.width;
    extraction_rectangle.y = sprite.line * sprite.height;
    extraction_rectangle.w = sprite.width;
    extraction_rectangle.h = sprite.height;

    display_rectangle.x = position.x();
    display_rectangle.y = position.y();
    // TODO use scale ratio
    display_rectangle.w = sprite.width * 3;
    display_rectangle.h = sprite.height * 3;

    project_rectangle_on_screen(display_rectangle);

    SDL_RenderCopy(renderer_, texture, &extraction_rectangle, &display_rectangle);
  }
}

SDL_Texture *Graphics::get_texture(const std::string &image_filepath) {
  SDL_Texture *texture = NULL;
  auto kv_texture = texture_cache_.find(image_filepath);

  if (kv_texture == texture_cache_.end()) {
    SDL_Surface *image = IMG_Load(image_filepath.c_str());

    texture = SDL_CreateTextureFromSurface(renderer_, image);
    texture_cache_[image_filepath] = texture;

    SDL_FreeSurface(image);
  } else {
    texture = kv_texture->second;
  }

  return texture;
}

void Graphics::free_texture_cache() {
  for(auto &kv_texture : texture_cache_) {
    SDL_DestroyTexture(kv_texture.second);
    texture_cache_.erase(kv_texture.first);
  }
}

double Graphics::project_y_on_screen(const double &y) const {
  return window_height_ - y;
}

void Graphics::project_rectangle_on_screen(SDL_Rect &rectangle) const {
  rectangle.y = project_y_on_screen(rectangle.y + rectangle.h);
}

