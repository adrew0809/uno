#ifndef UNO_DIGITALINPUT_H_
#define UNO_DIGITALINPUT_H_

#include <stdint.h>

namespace uno {

class DigitalInput {
public:
  explicit DigitalInput(uint8_t pin) noexcept;
  bool is_on() const noexcept;
private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_DIGITALINPUT_H_
