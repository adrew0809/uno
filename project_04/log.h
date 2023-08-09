#ifndef UNO_PROJECT04_LOG_H_
#define UNO_PROJECT04_LOG_H_

#include "array.h"

namespace uno {

class SerialPort;

void log(const SerialPort& serial_port,
         const array<float, 3>& input) noexcept;

void log(const SerialPort& serial_port,
         const array<char, 3>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_LOG_H_

