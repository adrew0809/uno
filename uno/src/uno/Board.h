#ifndef UNO_UNO_SRC_UNO_BOARD_H_
#define UNO_UNO_SRC_UNO_BOARD_H_

#include <Arduino.h>
#include <stdint.h>

namespace uno {

struct AnalogPin { uint8_t value; };
struct PWMPin { int value; };

struct Baud { unsigned long value; };

namespace operators {

constexpr Baud operator""_Bd(unsigned long long n) noexcept {
  return Baud{n};
}

}  // namespace operators

class Board {
public:
  Board() noexcept;
};

class SerialStream {
  explicit SerialStream(Baud b) noexcept;
  friend SerialStream open_serial_stream(const Board& board,
                                         Baud b) noexcept;
};

template<typename T>
const SerialStream& operator<<(const SerialStream& ss, const T t) noexcept {
  ::Serial.print(t);
  return ss;
}

constexpr AnalogPin pin_A0(const Board&) noexcept { return {A0}; }
constexpr PWMPin pin_9(const Board&) noexcept { return {9}; }
SerialStream open_serial_stream(const Board& board, Baud b) noexcept;

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_BOARD_H_
