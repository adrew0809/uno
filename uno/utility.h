#ifndef UNO_UTILITY_H_
#define UNO_UTILITY_H_

#include <stddef.h>

#include "type_traits.h"

namespace uno {
namespace detail {

template<class T, class... Ts>
constexpr size_t find_uniq_type_in_pack() noexcept {
  constexpr size_t N = sizeof...(Ts);
  constexpr bool found[N] = { is_same_v<T, Ts> ... };
  size_t n = N;
  for (size_t i = 0; i < N; ++i) {
    if (found[i]) {
      if (n < N) {
        return N;
      }
      n = i;
    }
  }
  return n;
}

}  // namespace detail

template<class T, T... Ints>
class integer_sequence {
public:
  using value_type = T;

  static constexpr size_t size() noexcept {
    return sizeof...(Ints);
  }
};

template<size_t... Ints>
using index_sequence = integer_sequence<size_t, Ints...>;

namespace detail {

template<class T, size_t N, T... Is>
struct make_helper : make_helper<T, N - 1, Is..., N - 1> {};

template<class T, T... Is>
struct make_helper<T, 0, Is...> {
  using type = integer_sequence<T, Is...>;
};

}  // namespace detail

template<typename T, T N>
using make_integer_sequence =
    typename detail::make_helper<T, N>::type;

template<size_t N>
using make_index_sequence = make_integer_sequence<size_t, N>;

template<class... Ts>
using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

template<class T>
constexpr remove_reference_t<T>&& move(T&& t) noexcept {
  return static_cast<remove_reference_t<T>&&>(t);
}

template<class T>
constexpr T&& forward(remove_reference_t<T>& t) noexcept {
  return static_cast<T&&>(t);
}
template<class T>
constexpr T&& forward(remove_reference_t<T>&& t) noexcept {
  static_assert(!is_lvalue_reference_v<T>,
	  "forward must not be used to convert an rvalue to an lvalue");
  return static_cast<T&&>(t);
}

}  // namespace uno

#endif  // UNO_UTILITY_H_
