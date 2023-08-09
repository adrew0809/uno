#include "read.h"

#include "algorithm.h"

#include "AnalogInput.h"

namespace uno {

array<float, 3> read(const array<AnalogInput, 3>& photoresisters) noexcept {
  array<float, 3> rgb;
  transform(photoresisters.begin(), photoresisters.end(),
            rgb.begin(),
            [](const AnalogInput& in) { return in.read(); });
  return rgb;
}

}  // namespace uno
