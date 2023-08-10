#ifndef UNO_PROJECT04_LOG_H_
#define UNO_PROJECT04_LOG_H_

#include <array.h>

namespace uno {

class SerialPort;

void log(const SerialPort& serial_port,
         const char* intro,
         const array<int, 3>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_LOG_H_

