#include <cassert>
#include <cmath>

#include "process.h"

namespace uno {
namespace {

constexpr float kEps = 0.0000001;

constexpr bool is_near(float value, float expected, float eps) noexcept {
  return std::abs(value - expected) < eps;
}

void test_process_none() {
  const auto output = process(-50.0, 0.0);
  assert(output.value == 0.0);
  assert(output.voltage == 0.0);
  assert(is_near(output.celsius, -50.0, kEps));
  assert(output.level == Level::kNone);
}

void test_process_low() {
  const auto output = process(73.0, 256.0);
  assert(output.value == 256.0);
  assert(output.voltage == 1.25);
  assert(is_near(output.celsius, 75.0, kEps));
  assert(output.level == Level::kLow);
}

void test_process_medium() {
  const auto output = process(196.0, 512.0);
  assert(output.value == 512.0);
  assert(output.voltage == 2.5);
  assert(is_near(output.celsius, 200.0, kEps));
  assert(output.level == Level::kMedium);
}

void test_process_high() {
  const auto output = process(442.0, 1024.0);
  assert(output.value == 1024.0);
  assert(output.voltage == 5.0);
  assert(is_near(output.celsius, 450.0, kEps));
  assert(output.level == Level::kHigh);
}

}  // namespace
}  // namespace uno

int main() {
  uno::test_process_none();
  uno::test_process_low();
  uno::test_process_medium();
  uno::test_process_high();
}
