#ifndef UNO_TRANSFORMER_H_
#define UNO_TRANSFORMER_H_

#include "State.h"

namespace uno {

class Transformer {
public:
Transformer(const bool is_pressed,
            const unsigned long ticks) noexcept;

State Transformer::operator()(const Idle& idle) const noexcept;

State Transformer::operator()(
    const Blinking& blinking) const noexcept;

private:
  bool is_pressed_;
  unsigned long ticks_;
};

}  // namespace uno

#endif  // UNO_TRANSFORMER_H_
