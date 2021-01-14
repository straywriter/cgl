#pragma once

#if __cplusplus >= 201103L

template <typename Type> struct IsVoid :std::is_void <Type>
{
};

#endif


// bit_cast is C++ 20 if is C++ 20 please use std::bit_cast
template <typename _Tp, _Tp __v> struct integral_constant
{
    static constexpr _Tp value = __v;
    typedef _Tp value_type;
    typedef integral_constant<_Tp, __v> type;
    constexpr operator value_type() const noexcept
    {
        return value;
    }
};

template <typename T> class is_trivially_copyable_impl
{
    using ExtentsRemoved = typename std::remove_all_extents<T>::type;
    static constexpr bool kIsCopyOrMoveConstructible =
        std::is_copy_constructible<ExtentsRemoved>::value || std::is_move_constructible<ExtentsRemoved>::value;
    static constexpr bool kIsCopyOrMoveAssignable =
        std::is_copy_assignable<ExtentsRemoved>::value || std::is_move_assignable<ExtentsRemoved>::value;

  public:
    static constexpr bool kValue = (__has_trivial_copy(ExtentsRemoved) || !kIsCopyOrMoveConstructible) &&
                                   (__has_trivial_assign(ExtentsRemoved) || !kIsCopyOrMoveAssignable) &&
                                   (kIsCopyOrMoveConstructible || kIsCopyOrMoveAssignable) &&
                                   std::is_trivially_destructible<ExtentsRemoved>::value &&
                                   // We need to check for this explicitly because otherwise we'll say
                                   // references are trivial copyable when compiled by MSVC.
                                   !std::is_reference<ExtentsRemoved>::value;
};

template <typename T> struct is_trivially_copyable : integral_constant<bool, is_trivially_copyable_impl<T>::kValue>
{
};

template <typename To, typename From>
struct is_bitcastable
    : integral_constant<bool, sizeof(To) == sizeof(From) && is_trivially_copyable<From>::value &&
                                  is_trivially_copyable<To>::value && std::is_default_constructible<To>::value>
{
};

template <typename To, typename From, typename std::enable_if<is_bitcastable<To, From>::value, int>::type>
inline To bit_cast(const From &from)
{
    To to;
    memcpy(static_cast<void *>(std::addressof(to)), static_cast<const void *>(std::addressof(from)), sizeof(to));
    return to;
}
