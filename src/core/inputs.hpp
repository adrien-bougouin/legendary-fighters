#ifndef __CORE_INPUTS_HPP__
#define __CORE_INPUTS_HPP__

#include <SDL2/SDL.h>

// TODO probably creat an Input model including this type as attribute
enum class InputType {
  NONE,
  QUIT
};

class Inputs {
  public:
    InputType poll() const;
};

#endif // __CORE_INPUTS_HPP__

