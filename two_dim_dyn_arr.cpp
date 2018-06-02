#include <iostream>
#include <cstdlib>
#include <ctime>

//function prototypes for creating, deleting, filling and showing 2-dimensional dynamic array of integers in range 0-100
int ** createArr(int row_count, int col_count);
void deleteArr(int ** array, int row_count);
void fillArr(int ** array, int row_count, int col_count);
void showArr(int * const * array, int row_count, int col_count);


int main()
{

//row and column numbers of the array
	int row = 3;
	int col = 4;

//time seed for random number generator
	srand(time(0));

//function calls to create 2-dimensional dynamic array, fill it, show the elements and delete
	int ** arr = createArr(3, 4);
	fillArr(arr, 3, 4);
	showArr(arr, 3, 4);
	deleteArr(arr, row);

	return 0;
};

//function definition to create 2-dimensinal dynamic array of integers
int ** createArr(int row_count, int col_count)
{
	int ** array = new int * [row_count];
	for (int i = 0; i < row_count; ++i)
	{
		array[i] = new int[col_count];
	};
	return array;
};

//function definition to delete dynamically allocated 2-dimensional
void deleteArr(int ** array, int row_count)
{
	for (int i = 0; i < row_count; ++i)
	{
		delete [] array[i];
	};
		delete [] array;
};

//function definition to fill 2-dimensional dynamic array with integers in range 0 - 100
void fillArr(int ** array, int row_count, int col_count)
{
	for (int ir = 0; ir < row_count; ++ir)
	{
		for (int ic = 0; ic < col_count; ++ic)
		{
			array[ir][ic] = rand() % 101;
		};
	};
};

//function definition to show 2-dimensional dynamic array elements
void showArr(int * const * array, int row_count, int col_count)
{
	for (int ir = 0; ir < row_count; ++ir)
	{
		for (int ic = 0; ic < col_count; ++ic)
		{
			std::cout << array[ir][ic] << " ";
		};
		std::cout << std::endl;
	};
};
