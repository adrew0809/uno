#ifndef UNO_VARIANT_H_
#define UNO_VARIANT_H_

#include "type_traits.h"
#include "new.h"
#include "utility.h"

namespace uno {
namespace detail {

template <class T, class... Ts>
struct max_size {
  static constexpr size_t value = 
    sizeof(T) > max_size<Ts...>::value ? sizeof(T)
                                       : max_size<Ts...>::value;
};
template <class T>
struct max_size<T> {
  static constexpr size_t value = sizeof(T);
};
template <class T, class... Ts>
static constexpr size_t max_size_v = max_size<T, Ts...>::value;

template <class T, class... Ts>
struct max_align {
  static constexpr size_t value = 
    alignof(T) > max_size<Ts...>::value ? alignof(T)
                                       : max_size<Ts...>::value;
};
template <class T>
struct max_align<T> {
  static constexpr size_t value = alignof(T);
};
template <class T, class... Ts>
static constexpr size_t max_align_v = max_align<T, Ts...>::value;

template <class T, size_t N, class... Ts>
struct find_type_index {
  static constexpr size_t value = -1;
};

template <class T, size_t N, class... Ts>
struct find_type_index<T, N, T, Ts...> {
  static constexpr size_t value = N;
};

template <class T, class U, size_t N, class... Ts>
struct find_type_index<T, N, U, Ts...> :
    find_type_index<T, N + 1, Ts...> {};

}  // namespace detail

template <class... Ts> class variant;

template <class T>
struct variant_size;

template <class... Ts>
struct variant_size<variant<Ts...>> :
    integral_constant<size_t, sizeof...(Ts)> {};

template <class T>
class variant_size<const T> : public variant_size<T> {};

template <class T>
inline constexpr size_t variant_size_v = variant_size<T>::value;

template <size_t I, class T>
struct variant_alternative;

template <class T, class... Ts>
struct variant_alternative<0, variant<T, Ts...>> {
  using type = T;
};

template <size_t I, class T, class... Ts>
struct variant_alternative<I, variant<T, Ts...>> {
  static_assert(I < variant_size_v<variant<T, Ts...>>);
  using type =
      typename variant_alternative<I - 1, variant<Ts...>>::type;
};

template <size_t I, class T>
class variant_alternative<I, const T> :
    public variant_alternative<I, T> {};

template <size_t I, class T>
using variant_alternative_t =
    typename variant_alternative<I, T>::type;

template <class... Ts>
class variant {
public:
  constexpr variant() 
      noexcept(noexcept(variant_alternative_t<0, variant>())) :
      index_{0} {
    new (data_) variant_alternative_t<0, variant>();
  }

  template<class T>
  constexpr variant(T&& t) noexcept(noexcept(T(t)))
      : index_{detail::find_type_index<T, 0, Ts...>::value} {
    new (data_) T(t);
  }

  ~variant() noexcept {
    destroy(
        index_sequence_for<Ts...>(),
        index(),
        static_cast<void*>(data_));
  }

	constexpr size_t index() const noexcept { return index_; }

private:
  template <size_t I>
  void destroy_if(const size_t i, void* const ptr) noexcept {
    if (i == I) {
      using Type = variant_alternative_t<I, variant>;
      static_cast<Type*>(ptr)->~Type();
    }
  }
  
  template <size_t... Is>
  void destroy(index_sequence<Is...>,
               const size_t i, void* const ptr) noexcept {
    (... , destroy_if<Is>(i, ptr));
  }

  alignas (detail::max_align_v<Ts...>)
  char data_[detail::max_size_v<Ts...>];
  size_t index_;

  template<size_t I, class... Us>
  friend constexpr add_pointer_t<variant_alternative_t<
      I, variant<Us...>>>
  get_if(variant<Us...>* pv) noexcept;
};

template<class T, class... Ts>
constexpr bool holds_alternative(const variant<Ts...>& v) noexcept {
  return v.index() == detail::find_type_index<T, 0, Ts...>::value;
}

template<size_t I, class... Us>
constexpr add_pointer_t<variant_alternative_t<I, variant<Us...>>>
get_if(variant<Us...>* pv) noexcept {
  static_assert(I < variant_size_v<variant<Us...>>);
  if (I == pv->index()) {
    using Type = variant_alternative_t<I, variant<Us...>>;
    return static_cast<Type*>(
               static_cast<void*>(pv->data_));
  }
  return nullptr;
}

template<size_t I, class... Us>
constexpr add_pointer_t<const variant_alternative_t<
    I, variant<Us...>>> 
get_if(const variant<Us...>* pv) noexcept {
  return get_if<I, Us...>(const_cast<variant<Us...>*>(pv));
}

}  // namespace uno

#endif  //  UNO_VARIANT_H_
