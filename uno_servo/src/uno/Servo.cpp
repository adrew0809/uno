#include <uno/Servo.h>

#include <uno/Board.h>
#include <uno/util.h>

namespace uno {

Servo::Servo(const PWMPin pin) noexcept {
  servo_.attach(pin.value);
}
void Servo::move_to(const Degrees angle) const noexcept {
  servo_.write(angle.value);
}

}  // namespace uno
