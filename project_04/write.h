#ifndef UNO_PROJECT04_WRITE_H_
#define UNO_PROJECT04_WRITE_H_

#include <array.h>

namespace uno {
class AnalogOutput;

void write(const array<AnalogOutput, 3>& led,
           const array<int, 3>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_WRITE_H_

