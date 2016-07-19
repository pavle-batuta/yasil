#pragma once
class yasil_string
{
public:
	static const size_t MAX_STRING_LEN = 65536;

	// Constructors and destructor:
	yasil_string();
	~yasil_string();
	explicit yasil_string(const char*);
	yasil_string(const yasil_string&);
	yasil_string(yasil_string&&) noexcept;

	// Data management operations:
	void allocate(const size_t);  // Allocate zeroed memory for the content.
	void reset();  // Clear and deallocate string content.
	void copy(const char*);  // Override content with c-string.
	void copy(const yasil_string&);  // Override content with another yasil_string.
	const char* c_str() const;  // Get the char string from yasil.
	friend void swap(yasil_string& lhs, yasil_string& rhs);  // Swap contents of strings.

	// Assignment operator:
	yasil_string& operator=(const yasil_string& other);

	// Concatenation:
	yasil_string& operator+=(const yasil_string& other);
	yasil_string& operator+=(const char* other);

	// Access element, brackets operator:
	char operator[](size_t index) const;

	// Access element, checked:
	char at(size_t index) const;



private:
	char* content_;
	size_t size_;
};

