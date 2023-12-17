#!/bin/sh

set -xe

CFLAGS="-Wall -Wextra -ggdb `pkg-config --cflags raylib`"
LIBS="`pkg-config --libs raylib` -lm -ldl -lpthread -lrt -lX11"

clang $CFLAGS -o pong src/main.c src/utility.c src/button.c -I./include $LIBS
