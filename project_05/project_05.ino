#include <Arduino.h>
#include <Servo.h>
#include <stdint.h>

namespace uno {

struct AnalogPin { uint8_t value; };
struct PWMPin { uint8_t value; };
struct Baud { int value; };
struct Degrees { int value; };
struct Milliseconds { unsigned long value; };

class SerialStream {
  explicit SerialStream(Baud b) noexcept {
    ::Serial.begin(b.value);
  }
  friend class Board;
};

class Board {
public:
  Board() noexcept { ::init(); }
  constexpr AnalogPin pin_A0() const noexcept { return {A0}; }
  constexpr PWMPin pin_9() const noexcept { return {9}; }
  SerialStream open_serial_stream(Baud b) const noexcept {
    return SerialStream(b);
  };
};

class AnalogReader {
public:
  explicit constexpr AnalogReader(AnalogPin pin) noexcept
      : pin_(pin) {}
  int read() const noexcept { return analogRead(pin_.value); }
private:
  AnalogPin pin_;
};

class Servo {
public:
  explicit Servo(PWMPin pin) noexcept {
    servo_.attach(pin.value);
  }
  void move_to(Degrees angle) const noexcept {
    servo_.write(angle.value);
  }
private:
  ::Servo servo_;
};

namespace operators {

template<typename T>
const SerialStream& operator<<(const SerialStream& ss, const T t) noexcept {
  ::Serial.print(t);
  return ss;
}

constexpr Baud operator""_Bd(unsigned long long n) noexcept {
  return Baud{n};
}

constexpr Milliseconds operator""_ms(unsigned long long n) noexcept {
  return Milliseconds{n};
}

}  // namespace operators

const SerialStream& operator<<(const SerialStream& ss, const Degrees d) noexcept {
  using operators::operator<<;
  return ss << d.value;
}

Degrees to_angle(const int value) noexcept {
  return Degrees{::map(value, 0, 1023, 0, 179)};
}

void wait_for(Milliseconds ms) noexcept {
  delay(ms.value);
}

}  // namespace uno

int main() {
  using namespace uno::operators;

  const uno::Board board;
  const uno::AnalogReader potentiometer(board.pin_A0());
  const uno::Servo servo(board.pin_9());
  const auto ss = board.open_serial_stream(9600_Bd);

  for(;;) {
    const auto val = potentiometer.read();
    const auto angle = uno::to_angle(val);
    servo.move_to(angle);
    ss << "potVal: " << val << " angle: " << angle << '\n';
    wait_for(15_ms);
  }
}
