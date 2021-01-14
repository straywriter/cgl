#pragma once

#include <stddef.h>
#include <type_traits>

// base type

/** checks if a type is void */
template <typename Type> struct IsVoid;

/** checks if a type is an integral type */
template <typename Type> struct IsIntegral;

/** checks if a type is a floating-point type */
template <typename Type> struct IsFloatingPoint;

/** checks if a type is an array type */
template <typename Type> struct IsArray;
template <typename Type> struct IsUnion;
template <typename Type> struct Isclass;
template <typename Type> struct IsFunction;
template <typename Type> struct IsPointer;
template <typename Type> struct IsLValueReference;
template <typename Type> struct IsRValueReference;
// template <typename Type> struct ;



template <typename To, typename From>
struct is_bitcastable;
template <typename To, typename From, typename std::enable_if<is_bitcastable<To, From>::value, int>::type = 0>
inline To bit_cast(const From &from);


//---------------------------------

#include "Base/TypeTraits-inl.h"