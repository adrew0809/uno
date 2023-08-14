#ifndef UNO_UNO_SRC_UNO_DIGITALREADER_H
#define UNO_UNO_SRC_UNO_DIGITALREADER_H

#include <stdint.h>

namespace uno {
struct AnalogPin;
struct DigitalPin;
struct PWMPin;

class DigitalReader {
public:
  explicit DigitalReader(AnalogPin pin) noexcept;
  explicit DigitalReader(DigitalPin pin) noexcept;
  explicit DigitalReader(PWMPin pin) noexcept;
  bool is_on() const noexcept;
private:
  explicit DigitalReader(uint8_t pin) noexcept;
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_DIGITALREADER_H
