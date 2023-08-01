#include "Led.h"

#include "Arduino.h"

namespace uno {

Led::Led(const uint8_t pin) noexcept : pin_(pin) {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void Led::on() const noexcept {
  digitalWrite(pin_, HIGH);
}

void Led::off() const noexcept {
  digitalWrite(pin_, LOW);
}

}  // namespace uno
