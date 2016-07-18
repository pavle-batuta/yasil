#pragma once
class yasil_string
{
public:
	static const size_t MAX_STRING_LEN = 65536;

	yasil_string();
	~yasil_string();
	explicit yasil_string(const char*);
	yasil_string(const yasil_string&);

	void allocate(const size_t);  // Allocate zeroed memory for the content.
	void reset();  // Clear and deallocate string content.
	void copy(const char*);  // Override content with c-string.
	void copy(const yasil_string&);  // Override content with another yasil_string.
	const char* c_str() const;  // Get the char string from yasil.

private:
	char* content_;
	size_t size_;
};

