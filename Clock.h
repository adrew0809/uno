#ifndef UNO_CLOCK_H_
#define UNO_CLOCK_H_

namespace uno {

class Clock {
public:
  explicit Clock(const unsigned long cycles_per_tick) :
      cycles_per_tick_(cycles_per_tick) {}

  unsigned long tick() noexcept {
    return cycles_++ / cycles_per_tick_;
  }

private:
  unsigned long cycles_{0};
  unsigned long cycles_per_tick_;
};

}  // namespace uno

#endif  // UNO_CLOCK_H_

