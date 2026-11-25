#include "chip8.hpp"
#include <algorithm>
#include <span>

Chip8::Chip8() {
  // Kopieren des Fontsets in den RAM ab kFontStart
  // Erstellen eines memory-views der genau von 0x050-0x09F
  std::span fontset_dest =
      std::span{memory_}.subspan(kFontStart, kFontSet.size());
  std::ranges::copy(kFontSet, fontset_dest.begin());
}
