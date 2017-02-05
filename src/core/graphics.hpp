#ifndef __CORE_GRAPHICS_HPP__
#define __CORE_GRAPHICS_HPP__

#include <SDL2/SDL.h>

class Graphics {
  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;
  public:
    Graphics();
    ~Graphics();
    void start();
    void stop();
};

#endif // __CORE_GRAPHICS_HPP__

