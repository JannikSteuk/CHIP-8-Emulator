#include "chip8.hpp"
#include <algorithm>
#include <span>

Chip8::Chip8() {
  // Kopieren des Fontsets in den RAM ab kFontStart
  // Erstellen eines memory-views der genau von 0x050-0x09F
  std::span fontset_dest =
      std::span{memory_}.subspan(kFontStart, kFontSet.size());
  std::ranges::copy(kFontSet, fontset_dest.begin());

  for (std::size_t x = 0; x < kDisplayWidth; ++x) {
    display_[pixelIndex(x, x % kDisplayHeight)] = true; // Diagonale
  }
  bDrawFlag_ = true;
}

const Chip8::DisplayBuffer &Chip8::display() { return display_; }

void Chip8::clearDrawFlag() { bDrawFlag_ = false; }

bool Chip8::drawFlag() { return bDrawFlag_; }
