#include <uno/DigitalWriter.h>

#include <Arduino.h>
#include <uno/Board.h>

namespace uno {

DigitalWriter::DigitalWriter(const AnalogPin pin) noexcept
    : DigitalWriter(pin.value) {}

DigitalWriter::DigitalWriter(const DigitalPin pin) noexcept
    : DigitalWriter(pin.value) {}

DigitalWriter::DigitalWriter(const PWMPin pin) noexcept
    : DigitalWriter(pin.value) {}

DigitalWriter::DigitalWriter(const uint8_t pin) noexcept : pin_(pin) {
  pinMode(pin_, OUTPUT);
  digitalWrite(pin_, LOW);
}

void DigitalWriter::on() const noexcept {
  digitalWrite(pin_, HIGH);
}

void DigitalWriter::off() const noexcept {
  digitalWrite(pin_, LOW);
}

}  // namespace uno
