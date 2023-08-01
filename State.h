#ifndef UNO_STATE_H_
#define UNO_STATE_H_

#include "utility.h"

namespace uno {

struct Idle {};
struct Blinking {
  bool first_led_on;
  unsigned long ticks;
};

class State {
public:
  constexpr State(const Idle& idle) noexcept :
      idle_(idle), tag_(Tag::kIdle) {}

  constexpr State(const Blinking& blinking) noexcept :
      blinking_(blinking), tag_(Tag::kBlinking) {}

  State& operator=(const Idle& idle) noexcept {
    idle_ = idle;
    tag_ = Tag::kIdle;
    return *this;
  }

  State& operator=(const Blinking& blinking) noexcept {
    blinking_ = blinking;
    tag_ = Tag::kBlinking;
    return *this;
  }

  ~State() noexcept {
    if (tag_ == Tag::kIdle) {
      idle_.~Idle();
    } else {
      blinking_.~Blinking();
    }
  }

  constexpr const Idle* get_if_idle() const noexcept {
    return tag_ == Tag::kIdle ? &idle_
                              : nullptr;
  }

  constexpr const Blinking* get_if_blinking() const noexcept {
    return tag_ == Tag::kBlinking ? &blinking_
                                  : nullptr;
  }

private:
  union {
    Idle idle_;
    Blinking blinking_;
  };
  enum class Tag : char { kIdle, kBlinking };
  Tag tag_;
};

template <class F>
auto visit(F&& f, const State& state) -> decltype(forward<F>(f)(Idle{})) {
  if (const auto* const idle = state.get_if_idle()) {
    return forward<F>(f)(*idle);
  } else if (const auto* const blinking =
                 state.get_if_blinking()) {
    return forward<F>(f)(*blinking);
  }
}

}  // namespace uno

#endif  // UNO_STATE_H_


