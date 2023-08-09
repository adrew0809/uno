#include "AnalogOutput.h"

#include <assert.h>

#include "Arduino.h"

namespace uno {

AnalogOutput::AnalogOutput(const int pin) noexcept : pin_(pin) {
	pinMode(pin_, OUTPUT);
}

void AnalogOutput::write(const int value) const noexcept {
  assert(value >= 0 && value <= 255);
	analogWrite(pin_, value);
}

}  // namespace uno
