#include <unistd.h>

#include "core/graphics.hpp"

int main (int argc, char **argv) {
  Graphics graphics = Graphics();

  graphics.start();
  sleep(5);

  return 0;
}

