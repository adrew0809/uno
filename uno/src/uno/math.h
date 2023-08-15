#ifndef UNO_UNO_SRC_UNO_MATH_H_
#define UNO_UNO_SRC_UNO_MATH_H_

namespace uno {

class SerialStream;

struct Degrees { int value; };

const SerialStream& operator<<(const SerialStream& ss, Degrees d) noexcept;

// 0-1023 value to 0-179 degrees
Degrees to_angle(const int value) noexcept;

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_MATH_H_
