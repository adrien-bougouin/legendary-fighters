#ifndef __MODELS_ANIMATION_HPP__
#define __MODELS_ANIMATION_HPP__

#include <iostream>

// TODO reset after Sprite class
//#include "../core/graphics.hpp"
class Graphics;

// TODO create class
struct Sprite {
  std::string sprite_sheet_filepath;
  int line;
  int column;
  int width;
  int height;

  Sprite(const std::string &ssf, const int &l, const int &c, const int &w, const int &h): sprite_sheet_filepath(ssf), line(l), column(c), width(w), height(h) {}
};

class Animation {
  private:
    // TODO put into SpriteSheet class
    std::string sprite_sheet_filepath_;
    int sprite_width_;
    int sprite_height_;
    // TODO do not hard code
    int frame_data_[12];
    int current_frame_index_;
  public:
    Animation();

    Sprite current_frame() const;

    void update();
};

#endif // __MODELS_ANIMATION_HPP__
