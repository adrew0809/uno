#include <uno/AnalogWriter.h>

#include <Arduino.h>
#include <uno/Board.h>

namespace uno {

AnalogWriter::AnalogWriter(const PWMPin pin) noexcept : pin_(pin.value) {
	pinMode(pin_, OUTPUT);
}

void AnalogWriter::write(const int value) const noexcept {
	analogWrite(pin_, value);
}

}  // namespace uno
