#pragma once


class BaseStream
{
    protected:
    size_t size;
    size_t capactity;
    char* data;

public:

BaseStream();
BaseStream(size_t size);
BaseStream(BaseStream && other)noexcept;
~BaseStream();

const char* Data()const;
size_t Size()const;
bool Empty()const;
size_t Capacity()const;
void Clear();
void Resize(size_t size);
void Reserver();
void Swap(BaseStream & other);

//opterator


BaseStream& Append();
BaseStream& Append(const std::string& value);
BaseStream& Append(char value);


};

#include "Stream/BaseStream-inl.h"