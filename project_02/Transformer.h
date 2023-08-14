#ifndef UNO_PROJECT_02_TRANSFORMER_H_
#define UNO_PROJECT_02_TRANSFORMER_H_

#include "State.h"

namespace uno {

class Transformer {
public:
  Transformer(bool is_pressed, unsigned long ticks) noexcept;

  State operator()(const Idle& state) const noexcept;

  State operator()(const Blinking& state) const noexcept;

private:
  bool is_pressed_;
  unsigned long ticks_;
};

}  // namespace uno

#endif  // UNO_PROJECT_02_TRANSFORMER_H_
