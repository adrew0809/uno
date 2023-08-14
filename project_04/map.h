#ifndef UNO_PROJECT04_MAP_H_
#define UNO_PROJECT04_MAP_H_

#include <uno/algorithm.h>
#include <uno/array.h>

namespace uno {

array<int, 3> map(const array<int, 3>& sensorValues) noexcept {
  array<int, 3> result;
  uno::transform(sensorValues.begin(), sensorValues.end(),
                 result.begin(),
                 [](const int x){ return x / 4; });
  return result;
}

}  // namespace uno

#endif  // UNO_PROJECT04_MAP_H_


