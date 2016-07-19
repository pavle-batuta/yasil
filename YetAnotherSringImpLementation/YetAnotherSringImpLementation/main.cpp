#include "yasil_string.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Begin test" << std::endl;
	std::cout << yasil_string("TEST COPY").c_str() << std::endl;
	std::cout << yasil_string(yasil_string("TEST OTHER COPY")).c_str() << std::endl;
	std::cout << yasil_string(std::move(yasil_string("MOVED"))).c_str() << std::endl;
	yasil_string left;
	yasil_string right("RIGHT");
	left = right;
	std::cout << left.c_str() << " = " << right.c_str() << std::endl;
	return 0;
}
