#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "osx" ]
then
  brew update
  brew install cppunit
  brew install sdl2 sdl2_image
fi

