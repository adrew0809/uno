#include <uno/Board.h>

namespace uno {

SerialStream::SerialStream(Baud b) noexcept {
	::Serial.begin(b.value);
}

SerialStream open_serial_stream(const Board&,
                                const Baud b) noexcept {
	return SerialStream(b);
}

}  // namespace uno
