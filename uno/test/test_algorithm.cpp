#include <cassert>

#include <uno/algorithm.h>

void test_transform() {
  const int in[3] = {1, 2, 3};
  long int out[3] = {};
  const auto result =
      uno::transform(in, in + 3,
                     out,
                     [](const int i) {
                       return 2 * i;
                     });
                                  
  assert(out[0] == 2);
  assert(out[1] == 4);
  assert(out[2] == 6);
  assert(result == (out + 3));
}

int main() {
  test_transform();
}

