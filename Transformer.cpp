#include "Transformer.h"

namespace uno {

Transformer::Transformer(const bool is_pressed,
                         const unsigned long ticks) noexcept :
    is_pressed_(is_pressed), ticks_(ticks) {}

State Transformer::operator()(const Idle& idle) const noexcept {
  if (is_pressed_) {
    return Blinking{true, ticks_};
  }
  return idle;
}

State Transformer::operator()(
    const Blinking& blinking) const noexcept {
  if (!is_pressed_) {
    return Idle{};
  }
  if (ticks_ != blinking.ticks) {
    return Blinking{!blinking.first_led_on, ticks_};
  }
  return blinking;
}

}  // namespace uno

