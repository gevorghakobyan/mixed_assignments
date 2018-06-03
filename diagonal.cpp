#include <iostream>
#include <cstdlib>
#include <ctime>

//Size is the 2 arrays row and column number
int const Size = 5;

//a couple of prototypes
void fillArr(int array[Size][Size]);
int mainDiagonal(int const array[Size][Size]);
int antiDiagonal(int const array[Size][Size]);
bool diagonalCompare(int const array1[Size][Size], int const array2[Size][Size]);


int main()
{


	int arr1[Size][Size] = {};
	int arr2[Size][Size] = {};
	srand(time(0));

	fillArr(arr1);
	fillArr(arr2);
	

	std::cout << "First array main diagonal element sum: " << mainDiagonal(arr1) << std::endl;
	std::cout << "First array antidiagonal element sum: " << antiDiagonal(arr1) << std::endl;
	std::cout << "Second array main diagonal element sum: " << mainDiagonal(arr2) << std::endl;
	std::cout << "Second array antidiagonal element sum: " << antiDiagonal(arr2) << std::endl;

	std::cout << "Sum of the elements of main and secondary diagonals of the first array is greater than of the second array: ";
	diagonalCompare(arr1, arr2);
	return 0;
};

//fills two dimensional arrays with random numbers in range 0-100
void fillArr(int array[Size][Size])
{
	for(int i = 0; i < Size; ++i)
	{
		for (int j = 0; j < Size; ++j)
		{
			array[i][j] = rand() % 101;
		};
	};
};

//count the sum of the elements of the main diagonal 
int mainDiagonal(int const array[Size][Size])
{
	int sum_mdiagonal = 0;
	for (int i = 0; i < Size; ++i)
	{
		sum_mdiagonal += array[i][i];
	};
	return sum_mdiagonal;
};

//calculates sum of secondary diagonal
int antiDiagonal(int const array[Size][Size])
{
	int sum_adiagonal = 0;
	for (int i = 0, j = Size - 1; i < Size; ++i, --j)
	{
		sum_adiagonal += array[i][j];
	};
	return sum_adiagonal;
};

//returns true if first arrays sum of main and secondary diagonal is greater than of the second one, and false otherwise
bool diagonalCompare(int const array1[Size][Size], int const array2[Size][Size])
{
	if (mainDiagonal(array1) + antiDiagonal(array1) > mainDiagonal(array2) + antiDiagonal(array2))
	{
		std::cout << "True" << std::endl;
		return true;
	}
	else
	{
		std::cout << "False" << std::endl;
		return false;
	};	
};
