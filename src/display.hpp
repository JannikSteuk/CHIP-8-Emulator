// display.hpp

#pragma once
#include <SDL.h>

#include "chip8.hpp"

class Display {
public:
  explicit Display(int scalce = 10);
  ~Display();
  Display(const Display &) = delete;
  Display &operator=(const Display &) = delete;

  void draw(const Chip8::DisplayBuffer &pixels);

private:
  SDL_Window *window_{nullptr};
  SDL_Renderer *renderer_{nullptr};
  SDL_Texture *texture_{nullptr};
};
