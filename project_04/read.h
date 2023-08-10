#ifndef UNO_PROJECT04_READ_H_
#define UNO_PROJECT04_READ_H_

#include <array.h>

namespace uno {
class AnalogInput;

array<int, 3> read(const array<AnalogInput, 3>& photoresisters) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_READ_H_
