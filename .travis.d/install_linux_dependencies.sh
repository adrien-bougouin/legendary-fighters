#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "linux" ]
then
  sudo add-apt-repository -y ppa:zoogie/sdl2-snapshots
  sudo apt-get update
  sudo apt-get install libsdl2-dev libsdl2-image-dev
  sudo apt-get install libcppunit-dev
fi

