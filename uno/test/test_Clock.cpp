#include <cassert>

#include "Clock.h"

namespace {

void test_Clock() {
  uno::Clock c(10);
  auto ticks = c.tick();
  assert(ticks == 0);
  for (int i = 0; i < 8; ++i) {
    ticks = c.tick();
    assert(ticks == 0);
  }
	ticks = c.tick();
  assert(ticks == 1);
  for (int i = 0; i < 10; ++i) {
    ticks = c.tick();
  }
	assert(ticks == 2);
}

}  // namespace

int main() {
  test_Clock();
}
