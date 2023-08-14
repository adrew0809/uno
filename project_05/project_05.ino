#include <uno.h>
#include <uno/AnalogReader.h>
#include <uno/Board.h>
#include <uno/Servo.h>
#include <uno/util.h>

int main() {
  using namespace uno::operators;

  const uno::Board board;
  const uno::AnalogReader potentiometer(pin_A0(board));
  const uno::Servo servo(pin_9(board));
  const auto ss = open_serial_stream(board, 9600_Bd);

  for(;;) {
    const auto val = potentiometer.read();
    const auto angle = uno::to_angle(val);
    servo.move_to(angle);
    ss << "potVal: " << val << " angle: " << angle << '\n';
    wait_for(15_ms);
  }
}
