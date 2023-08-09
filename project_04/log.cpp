#include "log.h"

#include "SerialPort.h"

namespace uno {
namespace {

constexpr array<const char*, 3> kColors = {"\t red: ",
                                           "\t green: ",
                                           "\t blue: "};

template<typename T>
void print(const SerialPort& serial_port,
           const char* const intro,
           const array<T, 3>& arr) noexcept {
  serial_port.print(intro);
  for (int i = 0; i < 3; ++i) {
    serial_port.print(kColors[i]);
    serial_port.print(arr[i]);
  }
  serial_port.print("\n");
}

}  // namespace

void log(const SerialPort& serial_port,
         const array<float, 3>& input) noexcept {
  print(serial_port, "Raw Sensor Values ", input);
}

void log(const SerialPort& serial_port,
         const array<char, 3>& output) noexcept {
  print(serial_port, "Mapped Sensor Values ", output);
}

}  // namespace uno
