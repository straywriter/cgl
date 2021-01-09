#include <cassert>

template <typename Type> inline ArrayRef<Type>::ArrayRef(Type *data, size_t size) : mData(data), mSize(size)
{
}

template <typename Type>
inline ArrayRef<Type>::ArrayRef(Type *begin, const Type *end) : mData(begin), mSize(end - begin)
{
}

template <typename Type>
template <size_t Size>
inline ArrayRef<Type>::ArrayRef(std::array<Type, Size> &array) : mData(array.data()), mSize(array.size())
{
}

template <typename Type>
template <typename Allocater>
inline ArrayRef<Type>::ArrayRef(std::vector<Type, Allocater> &vector) : mData(vector.data()), mSize(vector.size())
{
}

template <typename Type>
template <size_t Size>
inline ArrayRef<Type>::ArrayRef(Type (&array)[Size]) : mData(array), mSize(Size)
{
}

template <typename Type> template <typename Allocater> inline ArrayRef<Type> ArrayRef<Type>::copy(Allocater &allocator)
{
    assert(mSize > 0 && mData != nullptr);
    Type *temp = allocator.allocate(mSize);
    std::uninitialized_copy(begin(), end(), temp);
    return ArrayRef<Type>(temp, mSize);
}

template <typename Type> inline Type *ArrayRef<Type>::begin() noexcept
{
    return mData;
}

template <typename Type> inline const Type *ArrayRef<Type>::begin() const noexcept
{
    return mData;
}

template <typename Type> inline Type *ArrayRef<Type>::end() noexcept
{
    return mData + mSize;
}

template <typename Type> inline const Type *ArrayRef<Type>::end() const noexcept
{
    return mData + mSize;
}

template <typename Type> inline std::reverse_iterator<Type *> ArrayRef<Type>::rbegin() noexcept
{
    return mData;
}

template <typename Type> inline std::reverse_iterator<const Type *> ArrayRef<Type>::rbegin() const noexcept
{
    return mData;
}

template <typename Type> inline std::reverse_iterator<Type *> ArrayRef<Type>::rend() noexcept
{
    return mData + mSize;
}

template <typename Type> inline std::reverse_iterator<const Type *> ArrayRef<Type>::rend() const noexcept
{
    return mData + mSize;
}

template <typename Type> inline const Type *ArrayRef<Type>::cbegin() const noexcept
{
    return mData;
}

template <typename Type> inline const Type *ArrayRef<Type>::cend() const noexcept
{
    return mData + mSize;
}

template <typename Type> inline std::reverse_iterator<const Type *> ArrayRef<Type>::crbegin() const noexcept
{
    return mData;
}

template <typename Type> inline std::reverse_iterator<const Type *> ArrayRef<Type>::crend() const noexcept
{
    return mData + mSize;
}

template <typename Type> inline Type &ArrayRef<Type>::front()
{
    assert(mSize > 0 && mData != nullptr);
    return mData[0];
}

template <typename Type> inline const Type &ArrayRef<Type>::front() const
{
    assert(mSize > 0 && mData != nullptr);
    return mData[0];
}

template <typename Type> inline Type &ArrayRef<Type>::back()
{
    assert(mSize > 0 && mData != nullptr);
    return mData[mSize - 1];
}

template <typename Type> inline const Type &ArrayRef<Type>::back() const
{
    assert(mSize > 0 && mData != nullptr);
    return mData[mSize - 1];
}

template <typename Type> inline Type *ArrayRef<Type>::data() noexcept
{
    return mData;
}

template <typename Type> inline const Type *ArrayRef<Type>::data() const noexcept
{
    return mData;
}

template <typename Type> inline size_t ArrayRef<Type>::size() const noexcept
{
    return mSize;
}

template <typename Type> inline bool ArrayRef<Type>::empty()
{
    return mSize == 0 ? true : false;
}

template <typename Type> inline bool ArrayRef<Type>::equals(ArrayRef &other)
{
    if (mSize != other.mSize)
        return false;
    return std::equal(begin(), end(), other.begin());
}

template <typename Type> inline ArrayRef<Type> ArrayRef<Type>::slice(size_t begin, size_t end) const
{
    assert(end > begin && end < mSize);
    return ArrayRef<Type>(mData + begin - 1, end - 1);
}

template <typename Type> inline Type &ArrayRef<Type>::operator[](size_type index)
{
    assert(mSize > 0 && mData != nullptr);
    return mData[index - 1];
}

template <typename Type> inline const Type &ArrayRef<Type>::operator[](size_type index) const
{
    assert(mSize > 0 && mData != nullptr);
    return mData[index - 1];
}

template <typename Type> inline std::vector<Type> ArrayRef<Type>::make_vector() const
{
    return std::vector<Type>(mData, mData + mSize);
}

template <typename Type> inline ArrayRef<Type> MakeArrayRef(Type *begin, Type *end)
{
    return ArrayRef<Type>(begin, end);
}

template <typename Type, size_t Size> inline ArrayRef<Type> MakeArrayRef(std::array<Type, Size> &array)
{
    return ArrayRef<Type>(array);
}

template <typename Type> inline ArrayRef<Type> MakeArrayRef(std::vector<Type> &vector)
{
    return ArrayRef<Type>(vector);
}

template <typename Type, size_t Size> inline ArrayRef<Type> MakeArrayRef(Type (&array)[Size])
{
    return ArrayRef<Type>(array);
}

template <typename Type> inline bool operator==(ArrayRef<Type> &first, ArrayRef<Type> &second)
{
    return first.equals(second);
}

template <typename Type> inline bool operator!=(ArrayRef<Type> &first, ArrayRef<Type> &second)
{
    return !first.equals(second);
}
