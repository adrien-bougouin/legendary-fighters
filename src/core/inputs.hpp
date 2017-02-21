#ifndef __CORE_INPUTS_HPP__
#define __CORE_INPUTS_HPP__

#include <SDL2/SDL.h>

#include "../models/input.hpp"

class Inputs {
  private:
    InputType input_type(SDL_Event event) const;
    InputMethod input_method(SDL_Event event) const;
  public:
    Input poll() const;
};

#endif // __CORE_INPUTS_HPP__

