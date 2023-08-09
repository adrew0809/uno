#include "RGB.h"
#include "SerialPort.h"

namespace uno {

void log(const SerialPort& serial_port,
         const RGB<float>& input) noexcept {
  serial_port.print("Raw Sensor Values \t red: ");
  serial_port.print(input.red);
  serial_port.print("\t green: ");
  serial_port.print(input.green);
  serial_port.print("\t blue: ");
  serial_port.print(input.blue);
  serial_port.print("\n");
}

void log(const SerialPort& serial_port,
         const RGB<char>& output) noexcept {
  serial_port.print("Mapped Sensor Values \t red: ");
  serial_port.print(output.red);
  serial_port.print("\t green: ");
  serial_port.print(output.green);
  serial_port.print("\t blue: ");
  serial_port.print(output.blue);
  serial_port.print("\n");
}

}  // namespace uno
