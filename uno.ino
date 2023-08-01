#include "array.h"

#include "Button.h"
#include "Clock.h"
#include "Led.h"
#include "State.h"
#include "Transformer.h"
#include "Writer.h"

int main() {
  using uno::array;
  using uno::Button;
  using uno::Clock;
  using uno::Idle;
  using uno::Led;
  using uno::State;
  using uno::Transformer;
  using uno::Writer;

  init();

  Button button(2);
  Led greenLed(3);
  array<Led, 2> redLeds = {Led(4), Led(5)};
  Clock clock(2'000);
  State state = Idle{};
  while (true) {
    const auto is_button_pressed = button.is_pressed();
    const auto ticks = clock.tick();
    state = visit(Transformer(is_button_pressed, ticks), state);
    visit(Writer(greenLed, redLeds), state);
  }
}
