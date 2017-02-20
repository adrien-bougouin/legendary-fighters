#include "inputs.hpp"

Input Inputs::poll() const {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        return Input(InputType::QUIT);
      case SDL_KEYDOWN:
        SDL_KeyboardEvent key = event.key;
        switch (key.keysym.sym) {
          case SDLK_q:
            return Input(InputType::LEFT);
          case SDLK_d:
            return Input(InputType::RIGHT);
        }
    }
  }

  return Input(InputType::NONE);
}

