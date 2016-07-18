#include "yasil_string.hpp"
#include <string.h>

yasil_string::yasil_string() : content_(nullptr), size_(0)
{
	reset();
}

yasil_string::~yasil_string()
{
	delete[] content_;
}

yasil_string::yasil_string(const char* other) : content_(nullptr), size_(0)
{
	copy(other);
}

yasil_string::yasil_string(const yasil_string& other) : content_(nullptr), size_(0)
{
	copy(other);
}

void yasil_string::allocate(const size_t amount)
{
	reset();
	size_ = (amount > MAX_STRING_LEN) ? MAX_STRING_LEN : amount;
	content_= new char[amount + 1]();  // Zero fill the memory.
}

void yasil_string::reset()
{
	if (content_)
	{
		delete[] content_;
	}
	content_ = nullptr;
	size_ = 0;
}

void yasil_string::copy(const char* str)
{
	if (str)
	{
		size_t len = strnlen(str, MAX_STRING_LEN);
		allocate(len);
		strncpy(content_, str, len);
	}
}

void yasil_string::copy(const yasil_string& other)
{
	copy(other.c_str());
}

const char* yasil_string::c_str() const
{
	return content_;
}
