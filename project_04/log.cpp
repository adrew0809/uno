#include "log.h"

#include "SerialPort.h"

namespace uno {

constexpr array<const char*, 3> kColors = {"\t red: ",
                                           "\t green: ",
                                           "\t blue: "};

void log(const SerialPort& serial_port,
           const char* const intro,
           const array<int, 3>& arr) noexcept {
  serial_port.print(intro);
  for (int i = 0; i < 3; ++i) {
    serial_port.print(kColors[i]);
    serial_port.print(arr[i]);
  }
  serial_port.print('\n');
}

}  // namespace uno
