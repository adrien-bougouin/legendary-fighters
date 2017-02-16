#include <signal.h>
#include <SDL2/SDL.h>

#include "core/game.hpp"

int main (int argc, char **argv) {
  if (SDL_VideoInit(NULL) == 0) {
    Game game = Game("Legendary Fighters");

    atexit(SDL_Quit);
    signal(SIGINT, exit);

    game.start();
  }

  return 0;
}

