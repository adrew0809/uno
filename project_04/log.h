#ifndef UNO_PROJECT04_LOG_H_
#define UNO_PROJECT04_LOG_H_

#include <uno/array.h>

namespace uno {

class SerialStream;

void log(const SerialStream& ss,
         const char* intro,
         const array<int, 3>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_LOG_H_

