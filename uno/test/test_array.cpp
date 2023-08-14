

#include <cassert>

#include <uno/array.h>

void test_const_element_access() {
  const uno::array<int, 3> ar = {1, 2, 3};
  assert(ar[0] == 1);
  assert(ar[1] == 2);
  assert(ar[2] == 3);
}

void test_element_access() {
  uno::array<int, 3> ar = {1, 2, 3};
  ar[1] = 22;
  assert(ar[1] == 22);
}

void test_iteration() {
  const uno::array<int, 3> ar = {1, 2, 3};
  int i = 1;
  for (auto e : ar) {
    assert(e == i);
    ++i;
  }
}

void test_size() {
  const uno::array<int, 3> ar = {1, 2, 3};
  assert(ar.size() == 3);
}

int main() {
  test_const_element_access();
  test_element_access();
  test_iteration();
  test_size();
}
