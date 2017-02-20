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
  HIGH_PUNCH,
  LIGHT_KICK,
  MEDIUM_KICK,
  HIGH_KICK
};

struct Input {
  InputType type;

  Input(InputType input_type);
};

#endif // __MODELS_INPUT_HPP__

