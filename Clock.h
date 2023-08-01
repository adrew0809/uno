#ifndef UNO_CLOCK_H_
#define UNO_CLOCK_H_

namespace uno {

class Clock {
public:
  explicit Clock(const unsigned long factor) : factor_(factor) {}
  unsigned long tick() noexcept {
    return ticks_++ / factor_;
  }

private:
  unsigned long ticks_{0};
  unsigned long factor_;
};

}  // namespace uno

#endif  // UNO_CLOCK_H_

