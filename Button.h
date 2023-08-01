#ifndef UNO_BUTTON_H_
#define UNO_BUTTON_H_

#include <stdint.h>

namespace uno {

class Button {
public:
  explicit Button(uint8_t pin) noexcept;
  bool is_pressed() const noexcept;
private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_BUTTON_H_
