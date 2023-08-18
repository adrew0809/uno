#include <uno/time.h>

#include <Arduino.h>

namespace uno {

Clock::Clock(const unsigned long interval) noexcept :
    interval_(interval), next_timeout_(millis() + interval_) {}

bool Clock::tick() noexcept {
  const auto now = millis();
  if (now >= next_timeout_) {
    next_timeout_ = now + interval_;
    return true;
  }
  return false;
}


void wait_for(Milliseconds ms) noexcept {
  delay(ms.value);
}

}  // namespace uno
