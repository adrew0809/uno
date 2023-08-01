#ifndef UNO_TYPE_TRAITS_H_
#define UNO_TYPE_TRAITS_H_

namespace uno {

template<class T, T v>
struct integral_constant {
  static constexpr T value = v;
  using value_type = T;
  using type = integral_constant;
  constexpr operator value_type() const noexcept {
    return value;
  }
  constexpr value_type operator()() const noexcept {
    return value;
  }
};

template<bool v>
using bool_constant = integral_constant<bool, v>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template<class T>
struct is_lvalue_reference : false_type {};
template<class T>
struct is_lvalue_reference<T&> : true_type {};
template<class T>
inline constexpr bool is_lvalue_reference_v =
    is_lvalue_reference<T>::value;

template<class T> struct remove_reference { using type = T; };
template<class T> struct remove_reference<T&> { using type = T; };
template<class T> struct remove_reference<T&&> { using type = T; };
template<class T>
using remove_reference_t = typename remove_reference<T>::type;

namespace detail {

template<class T>
struct type_identity { using type = T; };
 
template<class T>
auto try_add_pointer(int) ->
    type_identity<typename remove_reference<T>::type*>;
template<class T>
auto try_add_pointer(...) -> type_identity<T>;

} // namespace detail
 
template<class T>
struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};
template<class T>
using add_pointer_t = typename add_pointer<T>::type;

}  // namespace uno

#endif  // UNO_TYPE_TRAITS_H_
