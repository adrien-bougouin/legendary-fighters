#include <signal.h>

#include "core/game.hpp"

int main (int argc, char **argv) {
  Game game = Game();

  signal(SIGINT, exit);

  game.run();

  return 0;
}

