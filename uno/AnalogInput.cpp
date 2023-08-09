#include "AnalogInput.h"

#include "Arduino.h"

namespace uno {

float AnalogInput::read() const noexcept {
  delay(cooldown_ms_);
  return analogRead(pin_);
}

}  // namespace uno
