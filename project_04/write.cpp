#include "write.h"

#include "AnalogOutput.h"

namespace uno {

void write(const RGB<AnalogOutput>& led,
           const RGB<char>& output) noexcept {
  led.red.write(output.red); 
  led.green.write(output.green); 
  led.blue.write(output.blue); 
}

}  // namespace uno
