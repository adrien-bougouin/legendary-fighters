#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "osx" ]
then
  bash <(curl -s https://codecov.io/bash) -t ${CODECOV_IO_TOKEN}
fi

