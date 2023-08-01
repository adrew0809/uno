#ifndef UNO_TRANSFORMER_H_
#define UNO_TRANSFORMER_H_

#include "State.h"

namespace uno {

class Transformer {
public:
  Transformer(bool is_pressed, unsigned long ticks) noexcept;

  State operator()(const Idle& idle) const noexcept;

  State operator()(const Blinking& blinking) const noexcept;

private:
  bool is_pressed_;
  unsigned long ticks_;
};

}  // namespace uno

#endif  // UNO_TRANSFORMER_H_
