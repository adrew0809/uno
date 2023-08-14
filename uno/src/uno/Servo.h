#ifndef UNO_UNO_SRC_UNO_SERVO_H_
#define UNO_UNO_SRC_UNO_SERVO_H_

#include <uno/Board.h>

#include <Servo.h>

namespace uno {

struct Degrees;
struct PWMPin;

class Servo {
public:
  explicit Servo(PWMPin pin) noexcept;
  void move_to(Degrees angle) const noexcept;
private:
  ::Servo servo_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_SERVO_H_
