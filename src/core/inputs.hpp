#ifndef __CORE_INPUTS_HPP__
#define __CORE_INPUTS_HPP__

#include <SDL2/SDL.h>

#include "../models/input.hpp"

class Inputs {
  public:
    Input poll() const;
};

#endif // __CORE_INPUTS_HPP__

