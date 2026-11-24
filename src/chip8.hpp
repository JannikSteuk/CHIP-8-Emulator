#include <array>
#include <cstdint>

class Cip8 {
public:
  // Durch constexpr steht direkt zur compilezeit fest für alle klassen gleiches
  // Objekt

  // k hier wegen konstante
  static constexpr std::size_t kMemorySize = 4096;
  static constexpr std::uint16_t kProgramStart = 0x200;
  static constexpr std::uint16_t kFontStart = 0x050;

private:
  // ohne constexpr würde hier kMemorySize nicht funktionieren
  // memory_ zeigt, dass private member
  std::array<std::uint8_t, kMemorySize> memory_{};
};
