/* the program has a union that can hold 5 different data types. an array of
 *  the union is created and each element initialized. finally one of the 
 *  elements is altered from bool to int and by the way the new int has 
 *  the value that the bool would have converted to int.*/



#include <iostream>

union diverse
{
	int d_int;
	double d_double;
	char d_char;
	bool d_bool;
	int* d_i_p;

};

int main()
{

	diverse array[5];
	array[0].d_int = 3;
	array[1].d_double = 4.0;
	array[2].d_char = '5';
	array[3].d_bool = false;
	array[4].d_i_p = new int;
	*array[4].d_i_p = 5;

	std::cout << "array[0].d_int = " << array[0].d_int << std::endl;
	std::cout << "array[1].d_double = " << array[1].d_double << std::endl;
	std::cout << "array[2].d_char = " << array[2].d_char << std::endl;
	std::cout << "array[3].d_bool = " << array[3].d_bool << std::endl;
	std::cout << "array[4].d_i_p = " << array[4].d_i_p << std::endl;
	std::cout << "*array[4].d_i_p = " << *array[4].d_i_p << std::endl;

	std::cout << std::endl << "array[3] is beeing changed from d_bool to d_int" << std::endl;
	array[3].d_int = array[3].d_bool;
	std::cout << "array[3].d_int = " << array[3].d_int << std::endl;

	return 0;
};
