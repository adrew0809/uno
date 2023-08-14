#ifndef UNO_UNO_SRC_UNO_BOARD_H_
#define UNO_UNO_SRC_UNO_BOARD_H_

#include <Arduino.h>
#include <stdint.h>

namespace uno {

struct AnalogPin { uint8_t value; };
struct DigitalPin { uint8_t value; };
struct PWMPin { uint8_t value; };

struct Baud { unsigned long value; };

namespace operators {

constexpr Baud operator""_Bd(unsigned long long n) noexcept {
  return Baud{n};
}

}  // namespace operators

class Board {
public:
  Board() noexcept { ::init(); }
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
constexpr AnalogPin pin_A1(const Board&) noexcept { return {A1}; }
constexpr AnalogPin pin_A2(const Board&) noexcept { return {A2}; }
constexpr DigitalPin pin_2(const Board&) noexcept { return {2}; }
constexpr PWMPin pin_3(const Board&) noexcept { return {3}; }
constexpr DigitalPin pin_4(const Board&) noexcept { return {4}; }
constexpr PWMPin pin_5(const Board&) noexcept { return {5}; }
constexpr PWMPin pin_9(const Board&) noexcept { return {9}; }
constexpr PWMPin pin_10(const Board&) noexcept { return {10}; }
constexpr PWMPin pin_11(const Board&) noexcept { return {11}; }
SerialStream open_serial_stream(const Board& board, Baud b) noexcept;

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_BOARD_H_
