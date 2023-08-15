#include <uno/math.h>

#include <Arduino.h>
#include <uno/Board.h>

namespace uno {

const SerialStream& operator<<(const SerialStream& ss, Degrees d) noexcept {
  return ss << d.value;
}

Degrees to_angle(const int value) noexcept {
  return Degrees{::map(value, 0, 1023, 0, 179)};
}

}  // namespace uno
