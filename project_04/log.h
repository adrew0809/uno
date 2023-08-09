#ifndef UNO_PROJECT04_LOG_H_
#define UNO_PROJECT04_LOG_H_

namespace uno {

template<typename T>
struct RGB;

class SerialPort;

void log(const SerialPort& serial_port,
         const RGB<float>& input) noexcept;

void log(const SerialPort& serial_port,
         const RGB<char>& output) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT04_LOG_H_

