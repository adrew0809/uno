#ifndef UNO_PROJECT04_WRITE_H_
#define UNO_PROJECT04_WRITE_H_

#include <uno/array.h>

namespace uno {
class AnalogWriter;

void write(const array<AnalogWriter, 3>& leds,
           const array<int, 3>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_WRITE_H_

