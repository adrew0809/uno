#ifndef UNO_PROJECT04_READ_H_
#define UNO_PROJECT04_READ_H_

#include <uno/array.h>

namespace uno {
class AnalogReader;

array<int, 3> read(const array<AnalogReader, 3>& photoresisters) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_READ_H_
