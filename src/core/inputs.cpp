#include "inputs.hpp"

InputType Inputs::poll() const {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        return InputType::QUIT;
    }
  }

  return InputType::NONE;
}

