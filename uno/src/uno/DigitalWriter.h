#ifndef UNO_UNO_SRC_UNO_DIGITALWRITER_H_
#define UNO_UNO_SRC_UNO_DIGITALWRITER_H_

#include <stdint.h>

namespace uno {
struct AnalogPin;
struct DigitalPin;
struct PWMPin;

class DigitalWriter {
public:
  explicit DigitalWriter(AnalogPin pin) noexcept;
  explicit DigitalWriter(DigitalPin pin) noexcept;
  explicit DigitalWriter(PWMPin pin) noexcept;
  void on() const noexcept;
  void off() const noexcept;
private:
  explicit DigitalWriter(uint8_t pin) noexcept;
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_DIGITALWRITER_H_
