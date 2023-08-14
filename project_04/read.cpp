#include "read.h"

#include <uno/AnalogReader.h>
#include <uno/algorithm.h>
#include <uno/util.h>

namespace uno {

array<int, 3> read(const array<AnalogReader, 3>& photoresisters) noexcept {
  using namespace uno::operators;
  array<int, 3> rgb;
  rgb[0] = photoresisters[0].read();
  transform(photoresisters.begin() + 1, photoresisters.end(),
            rgb.begin() + 1,
            [](const AnalogReader& in) {
              wait_for(5_ms);
              return in.read();
            });
  return rgb;
}

}  // namespace uno
