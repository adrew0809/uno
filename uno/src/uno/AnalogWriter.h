#ifndef UNO_UNO_SRC_UNO_ANALOGWRITER_H_
#define UNO_UNO_SRC_UNO_ANALOGWRITER_H_

#include <stdint.h>

namespace uno {
struct PWMPin;

class AnalogWriter {
public:
  explicit AnalogWriter(PWMPin pin) noexcept;

  void write(int value) const noexcept;

private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_ANALOGWRITER_H_
