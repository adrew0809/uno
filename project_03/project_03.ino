#include <uno.h> // hack to include nested headers
#include <uno/AnalogReader.h>
#include <uno/Board.h>
#include <uno/DigitalWriter.h>
#include <uno/array.h>
#include <uno/time.h>

#include "process.h"
#include "write.h"

int main() {
  using namespace uno::operators;

  constexpr float kBaseline = 23.5;

  const uno::Board board;

  const uno::AnalogReader temperature_sensor(pin_A0(board));
  const uno::array<uno::DigitalWriter, 3> redLeds = {
      uno::DigitalWriter(pin_2(board)), uno::DigitalWriter(pin_3(board)), uno::DigitalWriter(pin_4(board))};
  const auto ss = open_serial_stream(board, 9600_Bd);

  for (;;) {
    const auto reading = temperature_sensor.read();
    const auto output = uno::process(kBaseline, reading);
    write(output, redLeds, ss);
    wait_for(1_ms);
  }
}
