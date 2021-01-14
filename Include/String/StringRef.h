#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <limits>
#include <string>

template <typename Type> class TStringRef
{
  public:
    using value_type = Type;
    using pointer = Type *;
    using iterator = Type *;
    using const_iterator = const Type *;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    using reference = Type &;
    using const_reference = const Type &;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

  private:
    const Type *mData = nullptr; //<
    size_t mSize = 0;            //<

  public:
    TStringRef() = default;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    value_type *data() noexcept;
    const value_type *data() const noexcept;

    reference operator[](size_type n);
    const_reference operator[](size_type n) const;

    size_type size() const noexcept;
};

#include "Container/StringRef-inl.h"


using StringRef = TStringRef<char>;