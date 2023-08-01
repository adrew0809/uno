#ifndef UNO_LED_H_
#define UNO_LED_H_

#include <stdint.h>

namespace uno {

class Led {
public:
  explicit Led(uint8_t pin) noexcept;
  void on() const noexcept;
  void off() const noexcept;
private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_LED_H_
