#include "AnalogInput.h"
#include "AnalogOutput.h"
#include "SerialPort.h"
#include "array.h"
#include "log.h"
#include "map.h"
#include "read.h"
#include "write.h"

int main() {
  using uno::AnalogInput;
  using uno::AnalogOutput;
  using uno::SerialPort;
  using uno::array;

  init();

  const array<AnalogInput, 3> photoresisters =
      {AnalogInput(A0, 0), AnalogInput(A1, 5), AnalogInput(A2, 5)};
  const array<AnalogOutput, 3> led =
      {AnalogOutput(9), AnalogOutput(10), AnalogOutput(11)};
  const SerialPort serial_port(9600);

  while (true) {
    const auto input = read(photoresisters);
    log(serial_port, input);
    const auto output = map(input);
    log(serial_port, output);
    write(led, output);
  }
}
