#ifndef UNO_UNO_SRC_UNO_TIME_H
#define UNO_UNO_SRC_UNO_TIME_H

namespace uno {

struct Milliseconds { unsigned long value; };

namespace operators {

constexpr Milliseconds operator""_ms(unsigned long long n) noexcept {
  return Milliseconds{n};
}

}  // namespace operators

class Clock {
public:
  explicit Clock(const unsigned long interval) noexcept;
  bool tick() noexcept;

private:
  unsigned long interval_;
  unsigned long next_timeout_;
};

void wait_for(Milliseconds ms) noexcept;

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_TIME_H
