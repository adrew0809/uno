#include "array.h"

#include "Clock.h"
#include "DigitalInput.h"
#include "DigitalOutput.h"
#include "State.h"
#include "Transformer.h"
#include "Writer.h"

int main() {
  using uno::Clock;
  using uno::DigitalInput;
  using uno::DigitalOutput;
  using uno::Idle;
  using uno::State;
  using uno::Transformer;
  using uno::Writer;
  using uno::array;

  init();

  const DigitalInput button(2);
  const DigitalOutput greenLed(3);
  const array<DigitalOutput, 2> redLeds = {DigitalOutput(4), DigitalOutput(5)};
  Clock clock(2'000);
  State state = Idle{};

  while (true) {
    const auto is_button_pressed = button.is_on();
    const auto ticks = clock.tick();
    state = visit(Transformer(is_button_pressed, ticks), state);
    visit(Writer(greenLed, redLeds), state);
  }
}
