#include <uno/DigitalReader.h>

#include <Arduino.h>
#include <uno/Board.h>

namespace uno {

DigitalReader::DigitalReader(const AnalogPin pin) noexcept :
    DigitalReader(pin.value) {}

DigitalReader::DigitalReader(const DigitalPin pin) noexcept :
    DigitalReader(pin.value) {}

DigitalReader::DigitalReader(const PWMPin pin) noexcept :
    DigitalReader(pin.value) {}

DigitalReader::DigitalReader(const uint8_t pin) noexcept :
    pin_(pin) {
  pinMode(pin_, INPUT);
}

bool DigitalReader::is_on() const noexcept {
  return digitalRead(pin_) == HIGH;
}

}  // namespace uno
