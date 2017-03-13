#include "animation.hpp"
// TODO remove after Sprite class creation
#include "../core/graphics.hpp"

Animation::Animation(): frame_data_(), current_frame_index_(0) {
  // TODO do not hard code
  sprite_sheet_filepath_ = "./res/sprites/characters/test/daigo_stance.png";
  sprite_width_ = 64;
  sprite_height_ = 64;
  frame_data_[0] = 0;
  frame_data_[1] = 0;
  frame_data_[2] = 0;
  frame_data_[3] = 1;
  frame_data_[4] = 1;
  frame_data_[5] = 1;
  frame_data_[6] = 2;
  frame_data_[7] = 2;
  frame_data_[8] = 2;
  frame_data_[9] = 3;
  frame_data_[10] = 3;
  frame_data_[11] = 3;
}

Sprite Animation::current_frame() const {
  return Sprite(sprite_sheet_filepath_, 0, frame_data_[current_frame_index_], sprite_width_, sprite_height_);
}

// TODO do not hard code
void Animation::update() {
  ++current_frame_index_;

  if (current_frame_index_ == 12) {
    current_frame_index_ = 0;
  }
}

