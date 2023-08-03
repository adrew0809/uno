#ifndef UNO_WRITER_H_
#define UNO_WRITER_H_

#include <stddef.h>

#include "array.h"

namespace uno {

class Blinking;
class DigitalOutput;
class Idle;

class Writer {
public:
  Writer(const DigitalOutput& ready,
         const array<DigitalOutput, 2>& blinkers) noexcept;

  void operator()(const Idle& idle) const noexcept;

  void operator()(const Blinking& blinking) const noexcept;

private:
  const DigitalOutput* ready_;
  const array<DigitalOutput, 2>* blinkers_;
};

}  // namespace uno

#endif  // UNO_WRITER_H_
