#include "DigitalOutput.h"

#include "Arduino.h"

namespace uno {

DigitalOutput::DigitalOutput(const uint8_t pin) noexcept : pin_(pin) {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void DigitalOutput::on() const noexcept {
  digitalWrite(pin_, HIGH);
}

void DigitalOutput::off() const noexcept {
  digitalWrite(pin_, LOW);
}

}  // namespace uno
