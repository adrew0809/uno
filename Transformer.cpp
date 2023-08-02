#include "Transformer.h"

namespace uno {

Transformer::Transformer(const bool is_pressed,
                         const unsigned long ticks) noexcept :
    is_pressed_(is_pressed), ticks_(ticks) {}

State Transformer::operator()(const Idle& state) const noexcept {
  return is_pressed_ ? State{Blinking{false, ticks_}}
                     : State{state};
}

State Transformer::operator()(
    const Blinking& state) const noexcept {
  if (!is_pressed_) {
    return Idle{};
  }
  if (ticks_ != state.ticks) {
    return Blinking{!state.first_led_on, ticks_};
  }
  return state;
}

}  // namespace uno

