#ifndef UNO_PROJECT_02_TRANSFORMER_H_
#define UNO_PROJECT_02_TRANSFORMER_H_

#include "State.h"

namespace uno {

class Transformer {
public:
  Transformer(bool is_pressed, bool tick) noexcept;

  State operator()(const Idle& state) const noexcept;

  State operator()(const Blinking& state) const noexcept;

private:
  bool is_pressed_;
  bool tick_;
};

}  // namespace uno

#endif  // UNO_PROJECT_02_TRANSFORMER_H_
