#include <array>
#include <cstdint>

class Chip8 {
public:
  Chip8();

  // Durch constexpr steht direkt zur compilezeit fest für alle klassen gleiches
  // Objekt

  // k hier wegen konstante
  static constexpr std::size_t kMemorySize = 4096;
  static constexpr std::uint16_t kProgramStart = 0x200;
  static constexpr std::uint16_t kFontStart = 0x050;
  static constexpr std::size_t kDisplayWidth = 64;
  static constexpr std::size_t kDisplayHeight = 32;

  [[nodiscard]] static constexpr std::size_t pixelIndex(std::size_t x,
                                                        std::size_t y) {
    return (y * kDisplayWidth) + x;
  }

private:
  // ohne constexpr würde hier kMemorySize nicht funktionieren
  // memory_ zeigt, dass private member
  std::array<std::uint8_t, kMemorySize> memory_{};

  // Flaches Array damit später SDL damit besser umgehen kann. Und damit OP-Code
  // funktioniert
  std::array<bool, kDisplayHeight * kDisplayWidth> display_{};

  static constexpr std::array<std::uint8_t, 80> kFontSet{
      0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
      0x20, 0x60, 0x20, 0x20, 0x70, // 1
      0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
      0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
      0x90, 0x90, 0xF0, 0x10, 0x10, // 4
      0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
      0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
      0xF0, 0x10, 0x20, 0x40, 0x40, // 7
      0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
      0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
      0xF0, 0x90, 0xF0, 0x90, 0x90, // A
      0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
      0xF0, 0x80, 0x80, 0x80, 0xF0, // C
      0xE0, 0x90, 0x90, 0x90, 0xE0, // D
      0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
      0xF0, 0x80, 0xF0, 0x80, 0x80  // F
  };
};
