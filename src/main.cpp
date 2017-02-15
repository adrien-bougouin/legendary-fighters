#include <signal.h>

#include "core/game.hpp"

int main (int argc, char **argv) {
  Game game = Game("Legendary Fighters");

  signal(SIGINT, exit);
  game.start();

  return 0;
}

