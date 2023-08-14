#include <uno/util.h>

#include <Arduino.h>
#include <uno/Board.h>

namespace uno {

const SerialStream& operator<<(const SerialStream& ss, Degrees d) noexcept {
  return ss << d.value;
}

unsigned long Clock::tick() noexcept {
  return ++cycles_ / cycles_per_tick_;
}

void wait_for(Milliseconds ms) noexcept {
  delay(ms.value);
}

Degrees to_angle(const int value) noexcept {
  return Degrees{::map(value, 0, 1023, 0, 179)};
}

}  // namespace uno
