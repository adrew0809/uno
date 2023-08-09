#include "AnalogInput.h"
#include "AnalogOutput.h"
#include "RGB.h"
#include "SerialPort.h"
#include "log.h"
#include "map.h"
#include "read.h"
#include "write.h"

int main() {
  using uno::AnalogInput;
  using uno::AnalogOutput;
  using uno::RGB;
  using uno::SerialPort;

  init();

  const RGB<AnalogInput> photoresisters =
      {AnalogInput(A0, 0), AnalogInput(A1, 5), AnalogInput(A2, 5)};
  const RGB<AnalogOutput> led =
      {AnalogOutput(9), AnalogOutput(11), AnalogOutput(12)};
  const SerialPort serial_port(9600);

  while (true) {
    const auto input = read(photoresisters);
    log(serial_port, input);
    const auto output = map(input);
    log(serial_port, output);
    write(led, output);
  }
}
