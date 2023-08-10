#include "AnalogInput.h"

#include "Arduino.h"

namespace uno {

int AnalogInput::read() const noexcept {
  delay(cooldown_ms_);
  return analogRead(pin_);
}

}  // namespace uno
