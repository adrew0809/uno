#include "write.h"

#include <uno/Board.h>
#include <uno/DigitalWriter.h>

#include "process.h"

namespace uno {
namespace {

void log(const Output& output,
         const SerialStream& ss) noexcept {
  ss << "Sensor Value: " << output.value;
  ss << ", Volts: " << output.voltage;
  ss << ", degrees C: " << output.celsius << '\n';
}

void light(Level level,
           const array<DigitalWriter, 3>& leds) noexcept {
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
           const array<DigitalWriter, 3>& leds,
           const SerialStream& ss) noexcept {
  log(output, ss);
  light(output.level, leds);
}

}  // namespace uno
