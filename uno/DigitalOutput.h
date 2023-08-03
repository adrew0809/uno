#ifndef UNO_DIGITALOUPUT_H_
#define UNO_DIGITALOUPUT_H_

#include <stdint.h>

namespace uno {

class DigitalOutput {
public:
  explicit DigitalOutput(uint8_t pin) noexcept;
  void on() const noexcept;
  void off() const noexcept;
private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_DIGITALOUPUT_H_
