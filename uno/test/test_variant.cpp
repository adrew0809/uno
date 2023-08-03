#include <cassert>
#include <type_traits>

#include "variant.h"

namespace {
struct A {
  A() : x(12) { ctor_calls++; }
  ~A() noexcept { dtor_calls++; }
  int x; 
  
  static int ctor_calls;
  static int dtor_calls;
};
int A::ctor_calls = 0;
int A::dtor_calls = 0;

struct B {
  B() : x(13) { ctor_calls++; }
  ~B() noexcept { dtor_calls++; }
  int x; 
  
  static int ctor_calls;
  static int dtor_calls;
};
int B::ctor_calls = 0;
int B::dtor_calls = 0;
}  // namespace

int main() {
  static_assert(uno::detail::max_size_v<short, double, char> ==
                sizeof(double));
  static_assert(uno::detail::max_align_v<short, double, char> ==
                alignof(double));

  static_assert(uno::variant_size_v<uno::variant<short, double, char>> == 3);
  static_assert(uno::variant_size_v<const uno::variant<short, double, char>> == 3);
  static_assert(uno::variant_size_v<uno::variant<short>> == 1);
  static_assert(uno::variant_size_v<uno::variant<const short, const char*>> == 2);

  static_assert(std::is_same_v<
      uno::variant_alternative_t<
          1, uno::variant<double, char, short>>,
      char>);
  static_assert(std::is_same_v<
      uno::variant_alternative_t<
          0, uno::variant<double, char, short>>,
      double>);
  static_assert(std::is_same_v<
      uno::variant_alternative_t<
          2, uno::variant<double, char, short>>,
      short>);

  {
    uno::variant<A, B> v;
    assert(v.index() == 0);
  }
  assert(A::ctor_calls == 1);
  assert(A::dtor_calls == 1);
  assert(B::ctor_calls == 0);
  assert(B::dtor_calls == 0);


  assert(!uno::holds_alternative<int>(
      uno::variant<bool, int, double>()));
  assert(!uno::holds_alternative<int>(
      uno::variant<bool, double>()));
  assert(uno::holds_alternative<bool>(
      uno::variant<bool, int, double>()));

  {
    uno::variant<A, B> v;
    assert(uno::get_if<0>(&v) != nullptr);
    assert(uno::get_if<1>(&v) == nullptr);
    assert(uno::get_if<0>(&v)->x == 12);
  }
  {
    const uno::variant<int, double> v;
    assert(uno::get_if<0>(&v) != nullptr);
    assert(*uno::get_if<0>(&v) == 0);
  }

	A::ctor_calls = 0;
	A::dtor_calls = 0;
  {
    uno::variant<A, int> v(int{100});
		assert(v.index() == 1);
		assert(!uno::holds_alternative<A>(v));
		assert(uno::holds_alternative<int>(v));
    assert(uno::get_if<0>(&v) == nullptr);
    assert(uno::get_if<1>(&v) != nullptr);
    assert(*uno::get_if<1>(&v) == 100);
  }
	assert(A::ctor_calls == 0);
	assert(A::dtor_calls == 0);


  {
    uno::variant<A, int> u;
    uno::variant<A, int> v(int{100});
    u = v;
		assert(u.index() == 1);
		assert(!uno::holds_alternative<A>(u));
		assert(uno::holds_alternative<int>(u));
    assert(uno::get_if<0>(&u) == nullptr);
    assert(uno::get_if<1>(&u) != nullptr);
    assert(*uno::get_if<1>(&u) == 100);
  }
  
}
