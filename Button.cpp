#include "Button.h"

#include "Arduino.h"

namespace uno {

Button::Button(const uint8_t pin) noexcept : pin_(pin) {
  pinMode(pin_, INPUT);
}

bool Button::is_pressed() const noexcept {
  return digitalRead(pin_) == HIGH;
}

}  // namespace uno
