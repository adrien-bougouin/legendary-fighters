#include "animation.hpp"

Animation::Animation(): frame_data_(), current_frame_index_(0) {
  // TODO do not hard code
  frame_data_[0] = "./res/sprites/characters/test/daigo_stance_0.png";
  frame_data_[1] = "./res/sprites/characters/test/daigo_stance_0.png";
  frame_data_[2] = "./res/sprites/characters/test/daigo_stance_0.png";
  frame_data_[3] = "./res/sprites/characters/test/daigo_stance_1.png";
  frame_data_[4] = "./res/sprites/characters/test/daigo_stance_1.png";
  frame_data_[5] = "./res/sprites/characters/test/daigo_stance_1.png";
  frame_data_[6] = "./res/sprites/characters/test/daigo_stance_2.png";
  frame_data_[7] = "./res/sprites/characters/test/daigo_stance_2.png";
  frame_data_[8] = "./res/sprites/characters/test/daigo_stance_2.png";
  frame_data_[9] = "./res/sprites/characters/test/daigo_stance_3.png";
  frame_data_[10] = "./res/sprites/characters/test/daigo_stance_3.png";
  frame_data_[11] = "./res/sprites/characters/test/daigo_stance_3.png";
}

std::string &Animation::current_frame() {
  return frame_data_[current_frame_index_];
}

const std::string &Animation::current_frame() const {
  return frame_data_[current_frame_index_];
}

// TODO do not hard code
void Animation::update() {
  ++current_frame_index_;

  if (current_frame_index_ == 12) {
    current_frame_index_ = 0;
  }
}

