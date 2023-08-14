#ifndef UNO_UNO_SRC_UNO_UTIL_H
#define UNO_UNO_SRC_UNO_UTIL_H

namespace uno {

class SerialStream;

struct Degrees { int value; };

const SerialStream& operator<<(const SerialStream& ss, Degrees d) noexcept;

struct Milliseconds { unsigned long value; };

namespace operators {

constexpr Milliseconds operator""_ms(unsigned long long n) noexcept {
  return Milliseconds{n};
}

}  // namespace operators

void wait_for(Milliseconds ms) noexcept;

Degrees to_angle(const int value) noexcept;

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_UTIL_H
