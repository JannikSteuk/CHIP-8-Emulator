#pragma once
#include "chip8.hpp"
#include "display.hpp"
#include <SDL_events.h>

int main() {
  Chip8 chip8;
  Display display;

  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    if (chip8.drawFlag()) {
      display.draw(chip8.display());
      chip8.clearDrawFlag();
    }

    SDL_Delay(16);
  }
}
