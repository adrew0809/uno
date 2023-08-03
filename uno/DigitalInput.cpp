#include "DigitalInput.h"

#include "Arduino.h"

namespace uno {

DigitalInput::DigitalInput(const uint8_t pin) noexcept :
    pin_(pin) {
  pinMode(pin_, INPUT);
}

bool DigitalInput::is_on() const noexcept {
  return digitalRead(pin_) == HIGH;
}

}  // namespace uno
