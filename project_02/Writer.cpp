#include "Writer.h"

#include <uno/DigitalWriter.h>

#include "State.h"

namespace uno {

Writer::Writer(const DigitalWriter& ready,
               const array<DigitalWriter, 2>& blinkers) noexcept :
    ready_(&ready), blinkers_(&blinkers) {}

void Writer::operator()(const Idle&) const noexcept {
	ready_->on();
	for (auto& led : (*blinkers_)) { led.off(); }
}

void Writer::operator()(const Blinking& blinking) const noexcept {
	ready_->off();
	if (blinking.first_led_on) {
		(*blinkers_)[0].on();
		(*blinkers_)[1].off();
	} else {
		(*blinkers_)[0].off();
		(*blinkers_)[1].on();
	}
}

}  // namespace uno
