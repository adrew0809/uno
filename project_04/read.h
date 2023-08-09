#ifndef UNO_PROJECT04_READ_H_
#define UNO_PROJECT04_READ_H_

#include "RGB.h"

namespace uno {
class AnalogInput;

RGB<float> read(const RGB<AnalogInput>& photoresisters) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_READ_H_
