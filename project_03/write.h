#ifndef UNO_PROJECT_03_WRITE_H_
#define UNO_PROJECT_03_WRITE_H_

#include "array.h"

namespace uno {

class DigitalOutput;
class SerialPort;
struct Output;

void write(const Output& output,
           const array<DigitalOutput, 3>& leds,
           const SerialPort& serial_port) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT_03_WRITE_H_
