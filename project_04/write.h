#ifndef UNO_PROJECT04_WRITE_H_
#define UNO_PROJECT04_WRITE_H_

#include "RGB.h"

namespace uno {
class AnalogOutput;

void write(const RGB<AnalogOutput>& led,
           const RGB<char>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_WRITE_H_

