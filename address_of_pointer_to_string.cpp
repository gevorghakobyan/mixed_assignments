#include <iostream>
#include <string>

int main()
{
	char * p = const "hello";
	std::cout << "Printing p outputs: " << p << std::endl << "To print the data inside p - that is the address of the first letter of the string," << std::endl << " need to add ampersand (&) in front of the pointer name -- &p: " << &p << std::endl;

	return 0;
};
