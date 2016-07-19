#include "yasil_string.hpp"
#include <string.h>
#include <mutex>

// Constructors:

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

// Move semantics.
yasil_string::yasil_string(yasil_string&& other) noexcept : content_(nullptr), size_(0)
{
	// In order to do proper move semantics do the following:
	// Copy the pointer:
	size_ = other.size_;
	content_ = other.content_;
	// Invalidate the other pointer:
	other.content_ = nullptr;
	other.size_ = 0;
}

void yasil_string::allocate(const size_t amount)
{
	delete[] content_;
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

void swap(yasil_string& lhs, yasil_string& rhs)
{
	using std::swap;
	swap(lhs.content_, rhs.content_);
	swap(lhs.size_, rhs.size_);
}

yasil_string& yasil_string::operator=(const yasil_string& other)
{
	yasil_string temp(other);
	swap(*this, temp);
	return *this;
}

char yasil_string::operator[](size_t index) const
{
	return content_[index];
}

char yasil_string::at(size_t index) const
{
	if (index <= size_)
	{
		return operator[](index);
	}
	throw std::out_of_range("Index out of bounds");
}

