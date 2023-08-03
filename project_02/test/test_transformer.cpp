#include <cassert>

#include "State.h"
#include "Transformer.h"

namespace uno {
namespace {

void test_initial_state_is_idle() {
  State state;
  assert(state.get_if_idle() != nullptr);
}

void test_idle_remains_idle_if_no_press() {
  const auto next_state = visit(Transformer(false, 1), Idle{});
  assert(next_state.get_if_idle() != nullptr);
}

void test_idle_changes_to_blinking_if_press() {
  const auto next_state = visit(Transformer(true, 1), Idle{});
  assert(next_state.get_if_blinking() != nullptr);
}

void test_blinking_changes_to_idle_if_no_press() {
  const auto next_state = visit(Transformer(false, 1), Blinking{true, 0});
  assert(next_state.get_if_idle() != nullptr);
}

void test_blinking_remains_blinking_if_press() {
  const auto next_state = visit(Transformer(true, 1), Blinking{true, 0});
  assert(next_state.get_if_blinking() != nullptr);
}

void test_blinking_blinks_on_tick() {
  const auto next_state = visit(Transformer(true, 2), Blinking{true, 1});
  assert(next_state.get_if_blinking() != nullptr);
  assert(!next_state.get_if_blinking()->first_led_on);
  assert(next_state.get_if_blinking()->ticks == 2);
}

}  // namespace
}  // namespace uno

int main() {
  uno::test_initial_state_is_idle();
  uno::test_idle_remains_idle_if_no_press();
  uno::test_idle_changes_to_blinking_if_press();
  uno::test_blinking_changes_to_idle_if_no_press();
  uno::test_blinking_remains_blinking_if_press();
  uno::test_blinking_blinks_on_tick();
  return 0;
}
