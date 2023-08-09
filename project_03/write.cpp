#include "write.h"

#include "DigitalOutput.h"
#include "SerialPort.h"
#include "process.h"

namespace uno {
namespace {

void log(const Output& output,
         const SerialPort& serial_port) noexcept {
  serial_port.print("Sensor Value: ");
  serial_port.print(output.value);
  serial_port.print(", Volts: ");
  serial_port.print(output.voltage);
  serial_port.print(", degrees C: ");
  serial_port.print(output.celsius);
  serial_port.print("\n");
}

void light(Level level,
           const array<DigitalOutput, 3>& leds) noexcept {
  switch (level) {
  case Level::kNone:
    for (const auto& led : leds) {
      led.off();
    }
    break;
  case Level::kLow:
    leds[0].on();
    leds[1].off();
    leds[2].off();
    break;
  case Level::kMedium:
    leds[0].on();
    leds[1].on();
    leds[2].off();
    break;
  default:
    for (const auto& led : leds) {
      led.on();
    }
  }
}

}  // namespace

void write(const Output& output,
           const array<DigitalOutput, 3>& leds,
           const SerialPort& serial_port) noexcept {
  log(output, serial_port);
  light(output.level, leds);
}

}  // namespace uno
