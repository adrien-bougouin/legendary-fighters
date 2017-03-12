#ifndef __MODELS_INPUT_HPP__
#define __MODELS_INPUT_HPP__

enum struct InputType {
  NONE,
  QUIT,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  LIGHT_PUNCH,
  MEDIUM_PUNCH,
  HEAVY_PUNCH,
  LIGHT_KICK,
  MEDIUM_KICK,
  HEAVY_KICK
};

enum struct InputMethod {
  NONE,
  PUSH,
  RELEASE,
  OTHER
};

struct Input {
  InputType type;
  InputMethod method;

  Input(InputType input_type, InputMethod input_method);
};

#endif // __MODELS_INPUT_HPP__

