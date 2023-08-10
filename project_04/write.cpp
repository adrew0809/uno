#include "write.h"

#include <AnalogOutput.h>

namespace uno {

void write(const array<AnalogOutput, 3>& led,
           const array<int, 3>& output) noexcept {
  for (int i = 0; i < 3; ++i) {
		led[i].write(output[i]); 
  }
}

}  // namespace uno
