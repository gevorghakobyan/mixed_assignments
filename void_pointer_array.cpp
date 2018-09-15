// array of void pointers that holds 3 varying date type values.

#include <iostream>

int main()
{

	void* array[3];
	array[0] = new double;
	array[1] = new bool;
	array[2] = new char;

	*(static_cast<double*>(array[0])) = 3.7;
	*(static_cast<bool*>(array[1])) = false;
	*(static_cast<char*>(array[2])) = 'o';

	std::cout << "double = " << *(static_cast<double*>(array[0])) << std::endl;
	std::cout << "bool = " << *(static_cast<bool*>(array[1])) << std::endl;
	std::cout << "char = " << *(static_cast<char*>(array[2])) << std::endl;

	for (int i = 2; i >= 0; --i)
	{
		array[i] = nullptr;
	};

	return 0;
};
