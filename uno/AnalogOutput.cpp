#include "AnalogOutput.h"

#include "Arduino.h"

namespace uno {

AnalogOutput::AnalogOutput(const int pin) noexcept : pin_(pin) {
	pinMode(pin_, OUTPUT);
}

void AnalogOutput::write(const char value) const noexcept {
	analogWrite(pin_, value);
}

}  // namespace uno
