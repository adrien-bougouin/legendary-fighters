#include "inputs.hpp"

Input Inputs::poll() const {
  SDL_Event event;

  if (SDL_PollEvent(&event)) {
    return Input(input_type(event), input_method(event));
  } else {
    return Input(InputType::NONE, InputMethod::NONE);
  }
}

InputType Inputs::input_type(SDL_Event &event) const {
  InputType type = InputType::NONE;

  switch (event.type) {
    case SDL_QUIT:
      type = InputType::QUIT;
      break;
    case SDL_KEYDOWN:
    case SDL_KEYUP:
      SDL_KeyboardEvent key = event.key;

      switch (key.keysym.sym) {
        case SDLK_a:
          type = InputType::LEFT;
          break;
        case SDLK_d:
          type = InputType::RIGHT;
          break;
        case SDLK_w:
          type = InputType::UP;
          break;
      }
      break;
  }

  return type;
}

InputMethod Inputs::input_method(SDL_Event &event) const {
  InputMethod method = InputMethod::OTHER;

  if (event.type == SDL_KEYDOWN) {
    method = InputMethod::PUSH;
  } else if (event.type == SDL_KEYUP) {
    method = InputMethod::RELEASE;
  }

  return method;
}

