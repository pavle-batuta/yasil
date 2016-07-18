#include "yasil_string.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Begin test" << std::endl;
	std::cout << yasil_string("TEST COPY").c_str() << std::endl;
	std::cout << yasil_string(yasil_string("TEST OTHER COPY")).c_str() << std::endl;
	std::cout << yasil_string(std::move(yasil_string("MOVED"))).c_str() << std::endl;
	return 0;
}
