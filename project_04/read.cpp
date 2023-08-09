#include "read.h"

#include "AnalogInput.h"

namespace uno {

RGB<float> read(const RGB<AnalogInput>& photoresisters) noexcept {
  RGB<float> rgb;
  rgb.red = photoresisters.red.read();
  rgb.green = photoresisters.green.read();
  rgb.blue = photoresisters.blue.read();
  return rgb;
}

}  // namespace uno
