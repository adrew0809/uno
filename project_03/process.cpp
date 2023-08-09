#include "process.h"

namespace uno {

Output process(float baseline, float reading) noexcept {
  Output output;
  output.value = reading;
  output.voltage = (reading / 1024.0) * 5.0;
  output.celsius = 100.0 * (output.voltage - 0.5);
  if (output.celsius < baseline + 2) {
    output.level = Level::kNone;
  } else if (output.celsius < baseline + 4) {
    output.level = Level::kLow;
  } else if (output.celsius < baseline + 6) {
    output.level = Level::kMedium;
  } else {
    output.level = Level::kHigh;
  }
  return output;
}

}  // namespace uno
