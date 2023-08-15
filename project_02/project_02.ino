#include <uno.h>  // hack to include nested headers
#include <uno/Board.h>
#include <uno/DigitalReader.h>
#include <uno/DigitalWriter.h>
#include <uno/array.h>
#include <uno/time.h>

#include "State.h"
#include "Transformer.h"
#include "Writer.h"

int main() {
  const uno::Board board;

  const uno::DigitalReader button(pin_2(board));
  const uno::DigitalWriter greenLed(pin_3(board));
  const uno::array<uno::DigitalWriter, 2> redLeds = {
      uno::DigitalWriter(pin_4(board)),
      uno::DigitalWriter(pin_5(board))};
  uno::Clock clock(2'000);
  uno::State state;

  for (;;) {
    const auto is_button_pressed = button.is_on();
    const auto ticks = clock.tick();
    state = visit(uno::Transformer(is_button_pressed, ticks), state);
    visit(uno::Writer(greenLed, redLeds), state);
  }
}
