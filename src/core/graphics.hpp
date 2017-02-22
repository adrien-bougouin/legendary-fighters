#ifndef __CORE_GRAPHICS_HPP__
#define __CORE_GRAPHICS_HPP__

#include <string>
#include <SDL2/SDL.h>

#include "../models/vector_2d.hpp"

// TODO double buffering
class Graphics {
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  public:
    Graphics(const std::string &window_title, const int &window_width, const int &window_height);
    ~Graphics();

    bool ready() const;

    void draw_square(const Vector2D &position, const double &width);
};

#endif // __CORE_GRAPHICS_HPP__

