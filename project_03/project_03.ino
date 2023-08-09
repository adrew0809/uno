#include "array.h"

#include "AnalogInput.h"
#include "DigitalOutput.h"
#include "SerialPort.h"
#include "process.h"
#include "write.h"

int main() {
  using uno::AnalogInput;
  using uno::DigitalOutput;
  using uno::SerialPort;
  using uno::array;
  using uno::process;
  using uno::write;

  constexpr float kBaseline = 23.5;

  init();

  const AnalogInput temperature_sensor(A0, 1);
  const array<DigitalOutput, 3> redLeds = {
      DigitalOutput(2), DigitalOutput(3), DigitalOutput(4)};
  const SerialPort serial_port(9600);

  while (true) {
    const auto reading = temperature_sensor.read();
    const auto output = process(kBaseline, reading);
    write(output, redLeds, serial_port);
  }
}
