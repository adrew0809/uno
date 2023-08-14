#include <uno.h> // hack to find nedted headers
#include <uno/array.h>
#include <uno/AnalogReader.h>
#include <uno/AnalogWriter.h>
#include <uno/Board.h>

#include "log.h"
#include "map.h"
#include "read.h"
#include "write.h"

int main() {
  using namespace uno::operators;

  const uno::Board board;

  const uno::array<uno::AnalogReader, 3> photoresisters = {
      uno::AnalogReader(pin_A0(board)),
      uno::AnalogReader(pin_A1(board)),
      uno::AnalogReader(pin_A2(board))};
  const uno::array<uno::AnalogWriter, 3> leds = {
      uno::AnalogWriter(pin_9(board)),
      uno::AnalogWriter(pin_10(board)),
      uno::AnalogWriter(pin_11(board))};
  const auto ss = open_serial_stream(board, 9600_Bd);

  for (;;) {
    const auto input = read(photoresisters);
    log(ss, "Raw Sensor Values ", input);
    const auto output = map(input);
    log(ss, "Mapped Sensor Values ", output);
    write(leds, output);
  }
}
