#ifndef UNO_PROJECT04_MAP_H_
#define UNO_PROJECT04_MAP_H_

#include "RGB.h"

namespace uno {

constexpr RGB<char> map(const RGB<float>& sensorValues) noexcept {
  return {sensorValues.red/4,
          sensorValues.green/4,
          sensorValues.blue/4};
}

}  // namespace uno

#endif  // UNO_PROJECT04_MAP_H_


