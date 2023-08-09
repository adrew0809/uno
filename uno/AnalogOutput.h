#ifndef UNO_UNO_ANALOGOUTPUT_H_
#define UNO_UNO_ANALOGOUTPUT_H_

namespace uno {

class AnalogOutput {
public:
  explicit AnalogOutput(int pin) noexcept;

  void write(int value) const noexcept;

private:
  int pin_;
};

}  // namespace uno

#endif  // UNO_UNO_ANALOGOUTPUT_H_

