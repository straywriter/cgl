/**
 * @file ArrayRef.h
 *
 * @date 2021-01-09
 *
 * @copyright Copyright (c) 2021
 *
 */
#pragma once

#include <algorithm>
#include <array>
#include <vector>

/**
 * ArrayRef iso
 * to std::vector array c array
 *
 */
template <typename Type> class ArrayRef
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
    Type *mData = nullptr;
    size_t mSize = 0;

  public:
    ArrayRef() = default;
    ArrayRef(Type *data, size_t size);
    ArrayRef(Type *begin, const Type *end);
    template <size_t Size> ArrayRef(std::array<Type, Size> &array);
    template <typename Allocater> ArrayRef(std::vector<Type, Allocater> &vector);
    template <size_t Size> ArrayRef(Type (&array)[Size]);

    // TODO: self chage
    // ArrayRef(const ArrayRef value);

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

    size_type size() const noexcept;
    bool empty();
    template <typename Allocater> ArrayRef<Type> copy(Allocater &A);
    bool equals(ArrayRef &other);
    ArrayRef<Type> slice(size_t begin, size_t end) const;

    // operator
    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    std::vector<Type> make_vector() const;
};

template <typename Type> ArrayRef<Type> MakeArrayRef(Type *begin, Type *end);
template <typename Type, size_t Size> ArrayRef<Type> MakeArrayRef(std::array<Type, Size> &array);
template <typename Type> ArrayRef<Type> MakeArrayRef(std::vector<Type> &vector);
template <typename Type, size_t Size> ArrayRef<Type> MakeArrayRef(Type (&array)[Size]);

template <typename Type> bool operator==(ArrayRef<Type> &first, const ArrayRef<Type> &second);
template <typename Type> bool operator!=(ArrayRef<Type> &first, const ArrayRef<Type> &second);

template <typename Type> class ConstArrayRef
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
    const Type *mData = nullptr;
    size_t mSize = 0;

  public:
    ConstArrayRef() = default;
    ConstArrayRef(const Type *data, size_t size);
    ConstArrayRef(const Type *begin, const Type *end);
    template <size_t Size> ConstArrayRef(const std::array<Type, Size> &array);
    template <typename Allocater> ConstArrayRef(std::vector<Type, Allocater> &vector);
    template <size_t Size> ConstArrayRef(const Type (&array)[Size]);
    ConstArrayRef(const std::initializer_list<Type> &initList);

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

    size_type size() const noexcept;
    bool empty();
    template <typename Allocater> ArrayRef<Type> copy(Allocater &A);
    bool equals(ArrayRef &other);
    ArrayRef<Type> slice(size_t begin, size_t end) const;

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    std::vector<Type> make_vector() const;
};

#include "Container/ArrayRef-inl.h"
