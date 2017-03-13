#ifndef __CORE_GRAPHICS_HPP__
#define __CORE_GRAPHICS_HPP__

#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>

#include "../models/vector_2d.hpp"
// TODO replace by ../models/sprite.hpp
#include "../models/animation.hpp"

class Graphics {
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
    std::unordered_map<std::string, SDL_Texture *> texture_cache_;

    double window_width_;
    double window_height_;

    void init_renderer();

    SDL_Texture *get_texture(const std::string &image_filepath);
    void free_texture_cache();

    double project_y_on_screen(const double &y) const;
    void project_rectangle_on_screen(SDL_Rect &rectangle) const;
  public:
    Graphics(const std::string &window_title, const double &window_width, const double &window_height);
    ~Graphics();

    bool ready() const;

    void render();
    void blit_sprite(const Sprite &sprite, const Vector2D &position);
};

#endif // __CORE_GRAPHICS_HPP__

