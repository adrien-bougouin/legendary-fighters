#ifndef __MODELS_ANIMATION_HPP__
#define __MODELS_ANIMATION_HPP__

#include <iostream>

#include "../core/graphics.hpp"

class Animation {
  private:
    // TODO do not hard code
    std::string frame_data_[12];
    int current_frame_index_;
  public:
    Animation();

    std::string &current_frame();
    const std::string &current_frame() const;

    void update();
};

#endif // __MODELS_ANIMATION_HPP__
