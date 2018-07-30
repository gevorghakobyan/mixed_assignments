/* program has a void* array, that holds three varying data types which
 * are assigned a respective value and displayed.*/

#include <iostream>

int main()
{
	void* array[3];
	array[0] = new char;
	*(static_cast<char*> (array[0])) = 't';
	array[1] = new double;
	*(static_cast<double*> (array[1])) = 7.1;
	array[2] = new bool;
	*(static_cast<bool*> (array[2])) = true;



	std::cout << "char = " << *(static_cast<char*> (array[0])) << std::endl;
	std::cout << "double = " << *(static_cast<double*> (array[1])) << std::endl;
	std::cout << "bool = " << *(static_cast<bool*> (array[2])) << std::endl;

	for (int i = 0; i < 3; ++i)
	{
		array[i] = nullptr;
	};

	return 0;
};

