#include <signal.h>
#include <SDL2/SDL.h>

#include "core/inputs.hpp"
// TODO physics
#include "core/graphics.hpp"
#include "core/game.hpp"

int main (int argc, char **argv) {
  if (SDL_VideoInit(NULL) == 0) {
    atexit(SDL_Quit);

    Inputs inputs = Inputs();
    // TODO physics engine
    Graphics graphics = Graphics("Legendary Fighters", 640, 480);

    if (graphics.ready()) {
      Game game = Game(&inputs, &graphics);

      game.run();
    }
  }

  return 0;
}

