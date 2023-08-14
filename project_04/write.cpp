#include "write.h"

#include <uno/AnalogWriter.h>

namespace uno {

void write(const array<AnalogWriter, 3>& leds,
           const array<int, 3>& output) noexcept {
  for (int i = 0; i < 3; ++i) {
		leds[i].write(output[i]); 
  }
}

}  // namespace uno
