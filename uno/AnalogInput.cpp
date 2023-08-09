#include "AnalogInput.h"

#include "Arduino.h"

namespace uno {

AnalogInput::AnalogInput(const int pin,
                         const unsigned int cooldown_ms) noexcept :
    pin_(pin), cooldown_ms_(cooldown_ms) {}

float AnalogInput::read() const noexcept {
  delay(cooldown_ms_);
  return analogRead(pin_);
}

}  // namespace uno
