#pragma once
class yasil_string
{
public:
	yasil_string();
	~yasil_string();

private:
	char* content_;
	size_t size_;
};

