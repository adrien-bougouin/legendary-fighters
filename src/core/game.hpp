#ifndef __CORE_GAME_HPP__
#define __CORE_GAME_HPP__

class Game {
  private:
    bool stopped_;

    void loop();
  public:
    Game();
    void start();
    void stop();
};

#endif // __CORE_GAME_HPP__

