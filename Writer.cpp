#include "Writer.h"

#include "Led.h"
#include "State.h"

namespace uno {

Writer::Writer(Led& ready, array<Led, 2>& blinkers) noexcept :
		ready_(&ready), blinkers_(&blinkers) {}

void Writer::operator()(const Idle&) const noexcept {
	ready_->on();
	for (auto& led : (*blinkers_)) { led.off(); }
}

void Writer::operator()(const Blinking& blinking) const noexcept {
	ready_->off();
	if (blinking.on) {
		(*blinkers_)[0].on();
		(*blinkers_)[1].off();
	} else {
		(*blinkers_)[0].off();
		(*blinkers_)[1].on();
	}
}

}  // namespace uno
