#include <iostream>

//prototypes for array merging and array displaying functions
int * mergeArr(int const * array1, int const * array2, int size1, int size2);
void showArr(int const * array, int size);


int main()
{

//two initial arrays
	int arr1[] = {0, 2, 4, 5, 8, 10};
	int arr2[] = {1, 3, 6, 7, 8, 9, 11};
//initial array sizes
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

//pointer addressing the merged array
	int * p_merg_arr = mergeArr(arr1, arr2, size1, size2);

//prints two initial arrays and the final one comprised of the previous two merged to each other
	std::cout << "First array: ";
	showArr(arr1, size1);
	std::cout << "Second array: ";
	showArr(arr2, size2);
	std::cout << "Merged array: ";
	showArr(p_merg_arr, size1 + size2);

//deletes merged array which has been allocated dynamically and sets the pointer to NULL
	delete [] p_merg_arr;
	p_merg_arr = NULL;
	
	return 0;
};

//function definition which takes 2 pointers to arrays and 2 int-s for array sizes as arguments, merges the arrays in growing order in a dynamically allocated array and returns a pointer to int of the resulting array
int * mergeArr(int const * array1, int const * array2, int size1, int size2)
{
	int * p_merged_array = new int [size1 + size2];


	for (int i1 = 0, i2 = 0; i1 <= size1 || i2 <= size2; )
	{
		if ((size1 - i1) == 0 && (size2 - i2) == 0)
		{
			return p_merged_array;
		}
		else if ((size1 - i1) == 0)
		{
			p_merged_array[i1 + i2] = array2[i2];
			++i2;
		}
		else if ((size2 - i2) == 0)
		{
			p_merged_array[i1 + i2] = array1[i1];
			++i1;
		}
		else if (array1[i1] <= array2[i2])
		{
			p_merged_array[i1 + i2] = array1[i1];
			++i1;
		}
		else
		{
			p_merged_array[i1 + i2] = array2[i2];
			++i2;
		};
	};
	
};

//function definition of displaying array elements taking pointer to the array and array size as arguments
void showArr(int const * array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	};
	std::cout << std::endl;
};
