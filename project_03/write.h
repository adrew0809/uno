#ifndef UNO_PROJECT_03_WRITE_H_
#define UNO_PROJECT_03_WRITE_H_

#include <uno/array.h>

namespace uno {

class DigitalWriter;
class SerialStream;
struct Output;

void write(const Output& output,
           const array<DigitalWriter, 3>& leds,
           const SerialStream& ss) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT_03_WRITE_H_
