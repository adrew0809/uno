#ifndef UNO_WRITE_H_
#define UNO_WRITE_H_

#include <stddef.h>

#include "array.h"

namespace uno {

class Blinking;
class Idle;
class Led;

class Writer {
public:
  Writer(const Led& ready, const array<Led, 2>& blinkers) noexcept;

  void operator()(const Idle& idle) const noexcept;

  void operator()(const Blinking& blinking) const noexcept;

private:
  const Led* ready_;
  const array<Led, 2>* blinkers_;
};

}  // namespace uno

#endif  // UNO_WRITE_H_

