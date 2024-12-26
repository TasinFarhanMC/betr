#ifndef BETR_CONCEPTS_HPP
#define BETR_CONCEPTS_HPP

#include <type_traits>

namespace betr {
template <typename T> constexpr T &&forward(std::remove_reference_t<T> &value) noexcept { return static_cast<T &&>(value); };
template <typename T> constexpr T &&forward(std::remove_reference_t<T> &&value) noexcept { return static_cast<T &&>(value); }

template <typename T, typename U> concept SameAs = std::is_same_v<T, U>;
template <typename T> concept Integral = std::is_integral_v<T>;
template <typename T> concept FloatingPoint = std::is_floating_point_v<T>;
template <typename T> concept SignedIntegral = Integral<T> && std::is_signed_v<T>;
template <typename T> concept UnsignedIntegral = Integral<T> && std::is_unsigned_v<T>;
template <typename T, typename U> concept ConvertibleTo = std::is_convertible_v<T, U> && requires { static_cast<U>(std::declval<T>()); };
template <typename T, typename U> concept BaseOf = std::is_base_of_v<T, U>;
template <typename T, typename U> concept DerivedFrom = BaseOf<U, T> && ConvertibleTo<const volatile T *, const volatile U *>;
template <typename T> concept Destructible = std::is_destructible_v<T>;

template <typename T, typename U> concept CommonReferenceWith = SameAs<std::common_reference_t<T, U>, std::common_reference_t<U, T>> &&
                                                                ConvertibleTo<T, std::common_reference_t<T, U>> &&
                                                                ConvertibleTo<U, std::common_reference_t<T, U>>;

template <typename T, typename U> concept CommonWith =
    SameAs<std::common_type_t<T, U>, std::common_type_t<U, T>> &&
    requires {
      static_cast<std::common_type_t<T, U>>(std::declval<T>());
      static_cast<std::common_type_t<T, U>>(std::declval<U>());
    } && CommonReferenceWith<std::add_lvalue_reference_t<const T>, std::add_lvalue_reference_t<const U>> &&
    CommonReferenceWith<
        std::add_lvalue_reference_t<std::common_type_t<T, U>>,
        std::common_reference_t<std::add_lvalue_reference_t<const T>, std::add_lvalue_reference_t<const U>>>;

template <typename T, typename U> concept AssignableFrom =
    std::is_lvalue_reference_v<T> && CommonReferenceWith<const std::remove_reference_t<T> &, const std::remove_reference_t<U> &> &&
    requires(T lhs, U &&rhs) {
      { lhs = forward<U>(rhs) } -> SameAs<T>;
    };

template <typename T, typename... Args> concept ConstructibleFrom = Destructible<T> && std::is_constructible_v<T, Args...>;

template <typename T> concept DefaultInitializable = ConstructibleFrom<T> && requires {
  T {};
  (void)::new T;
};

template <typename T> concept MoveConstructible = ConstructibleFrom<T, T> && ConvertibleTo<T, T>;
template <typename T> concept CopyConstructible = MoveConstructible<T> && ConstructibleFrom<T, T &> && ConvertibleTo<T &, T> &&
                                                  ConstructibleFrom<T, const T &> && ConvertibleTo<const T &, T> && ConstructibleFrom<T, const T> &&
                                                  ConvertibleTo<const T, T>;
namespace ranges {
  namespace detail {
    template <typename _Tp> void swap(_Tp &, _Tp &) = delete;
    template <typename T> concept ClassOrEnum = std::is_class_v<T> || std::is_enum_v<T>;
    template <typename T, typename U> concept SameAs = std::is_same_v<T, U>;

    template <typename T, typename U> concept ADLSwapType = (ClassOrEnum<std::remove_reference_t<T>> || ClassOrEnum<std::remove_reference_t<U>>) &&
                                                            requires(T &&t, U &&u) { swap(static_cast<T &&>(t), static_cast<U &&>(u)); };

    struct Swap {
    private:
      template <typename T, typename U> static constexpr bool is_noexcept() {
        if constexpr (ADLSwapType<T, U>) {
          return noexcept(swap(std::declval<T>(), std::declval<U>()));
        } else {
          return std::is_nothrow_move_constructible_v<std::remove_reference_t<T>> && std::is_nothrow_move_assignable_v<std::remove_reference_t<T>>;
        }
      }

    public:
      template <typename T, typename U>
        requires ADLSwapType<T, U> || (SameAs<T, U> && std::is_lvalue_reference_v<T> && MoveConstructible<std::remove_reference_t<T>> &&
                                       AssignableFrom<T, std::remove_reference_t<T>>)
      constexpr void operator()(T &&t, U &&u) const noexcept(is_noexcept<T, U>()) {
        if constexpr (ADLSwapType<T, U>)
          swap(static_cast<T &&>(t), static_cast<U &&>(u));
        else {
          auto tmp = static_cast<std::remove_reference_t<T> &&>(t);
          t = static_cast<std::remove_reference_t<T> &&>(u);
          u = static_cast<std::remove_reference_t<T> &&>(tmp);
        }
      }

      template <typename T, typename U, std::size_t Num>
        requires requires(const Swap &swap, T &e1, U &e2) { swap(e1, e2); }
      constexpr void operator()(T (&e1)[Num], U (&e2)[Num]) const noexcept(noexcept(std::declval<const Swap &>()(*e1, *e2))) {
        for (std::size_t n = 0; n < Num; ++n) (*this)(e1[n], e2[n]);
      }
    };
  } // namespace detail

  inline namespace {
    inline constexpr detail::Swap swap {};
  }
} // namespace ranges

template <typename T> concept Swappable = requires(T &a, T &b) { ranges::swap(a, b); };
template <typename T, typename U> concept SwappableWith = CommonReferenceWith<T, U> && requires(T &&t, U &&u) {
  ranges::swap(static_cast<T &&>(t), static_cast<T &&>(t));
  ranges::swap(static_cast<U &&>(u), static_cast<U &&>(u));
  ranges::swap(static_cast<T &&>(t), static_cast<U &&>(u));
  ranges::swap(static_cast<U &&>(u), static_cast<T &&>(t));
};

template <typename T> concept EqualityComparable = requires(const std::remove_reference_t<T> &t, const std::remove_reference_t<T> &u) {
  { t == u } -> SameAs<bool>;
  { t != u } -> SameAs<bool>;
  { u == t } -> SameAs<bool>;
  { u != t } -> SameAs<bool>;
};

template <typename T> concept Movable = std::is_object_v<T> && MoveConstructible<T> && AssignableFrom<T &, T> && Swappable<T>;
template <typename T> concept Copyable =
    CopyConstructible<T> && Movable<T> && AssignableFrom<T &, T &> && AssignableFrom<T &, const T &> && AssignableFrom<T &, const T>;

template <typename T> concept Semiregular = Copyable<T> && DefaultInitializable<T>;
template <typename T> concept Regular = Semiregular<T> && EqualityComparable<T>;

template <typename Fn, typename... Args> concept Invocable = std::is_invocable_v<Fn, Args...>;
template <typename Fn, typename... Args> concept RegularInvocable = Invocable<Fn, Args...>;

template <typename Fn, typename... Args> concept Predicate = RegularInvocable<Fn, Args...> && requires(Fn fn, Args... args) {
  { std::invoke_result_t<Fn, Args...>() } -> ConvertibleTo<bool>;
};

template <typename Rel, typename T, typename U> concept Relation =
    Predicate<Rel, T, T> && Predicate<Rel, U, U> && Predicate<Rel, T, U> && Predicate<Rel, U, T>;

template <typename Rel, typename T, typename U> concept EquivalenceRelation = Relation<Rel, T, U>;
template <typename Rel, typename T, typename U> concept StrictWeakOrder = Relation<Rel, T, U>;

} // namespace betr

#endif
