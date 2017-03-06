#ifndef __CORE_GRAPHICS_HPP__
#define __CORE_GRAPHICS_HPP__

#include <string>
#include <SDL2/SDL.h>

#include "../models/vector_2d.hpp"

class Graphics {
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;

    double window_width_;
    double window_height_;

    void init_renderer();

    double project_y_on_screen(const double &y) const;
    void project_rectangle_on_screen(SDL_Rect &rectangle) const;
  public:
    Graphics(const std::string &window_title, const double &window_width, const double &window_height);
    ~Graphics();

    bool ready() const;

    void render();
    void draw_rectangle(const Vector2D &position, const double &width, const double &height);
};

#endif // __CORE_GRAPHICS_HPP__

