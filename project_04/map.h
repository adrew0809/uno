#ifndef UNO_PROJECT04_MAP_H_
#define UNO_PROJECT04_MAP_H_

#include <array.h>

namespace uno {

constexpr array<int, 3> map(const array<int, 3>& sensorValues) noexcept {
  return {sensorValues[0]/4,
          sensorValues[1]/4,
          sensorValues[2]/4};
}

}  // namespace uno

#endif  // UNO_PROJECT04_MAP_H_


