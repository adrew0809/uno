#include <uno/AnalogReader.h>

#include <Arduino.h>

namespace uno {

int AnalogReader::read() const noexcept {
  return analogRead(pin_);
}

}  // namespace uno
