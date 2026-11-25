// display.cpp

#include "display.hpp"

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <stdexcept>

Display::Display(int scale) {
  if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
    throw std::runtime_error(SDL_GetError());
  }

  window_ =
      SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       static_cast<int>(Chip8::kDisplayWidth) * scale,
                       static_cast<int>(Chip8::kDisplayHeight) * scale, 0);

  if (window_ == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  if (renderer_ == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }

  texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               static_cast<int>(Chip8::kDisplayWidth),
                               static_cast<int>(Chip8::kDisplayHeight));

  if (texture_ == nullptr) {
    throw std::runtime_error(SDL_GetError());
  }
}

Display::~Display() {
  SDL_DestroyTexture(texture_);
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Display::draw(const Chip8::DisplayBuffer &pixels) {
  std::array<std::uint32_t, Chip8::kDisplayWidth * Chip8::kDisplayHeight>
      frame{}; // Leer

  constexpr std::uint32_t kOn = 0xFFFFFFFF;
  constexpr std::uint32_t kOff = 0x00000000;

  for (std::size_t i = 0; i < pixels.size(); ++i) {
    frame[i] = pixels[i] ? kOn : kOff;
  }

  SDL_UpdateTexture(
      texture_, nullptr, frame.data(),
      static_cast<int>(Chip8::kDisplayWidth * sizeof(std::uint32_t)));

  SDL_RenderClear(renderer_);
  SDL_RenderCopy(renderer_, texture_, nullptr, nullptr);
  SDL_RenderPresent(renderer_);
}
