#include "Transformer.h"

namespace uno {

Transformer::Transformer(const bool is_pressed,
                         const bool tick) noexcept :
    is_pressed_(is_pressed), tick_(tick) {}

State Transformer::operator()(const Idle& state) const noexcept {
  return is_pressed_ ? State{Blinking{false}}
                     : State{state};
}

State Transformer::operator()(
    const Blinking& state) const noexcept {
  if (!is_pressed_) {
    return Idle{};
  }
  if (tick_) {
    return Blinking{!state.first_led_on};
  }
  return state;
}

}  // namespace uno

