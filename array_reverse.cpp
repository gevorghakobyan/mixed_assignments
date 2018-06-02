#include <iostream>

//function prototypes
void show(int const array[], int size);
void reverse(int array[], int size);

int main(void)
{
//requests the number of elements the array is going to have, after which the individual elements are requested and stored inside the array.
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter the " << i + 1 << "th element of the array.";
		std::cin >> array[i];
	};

//shows the array, reverses the elements and then displays the result
	show(array, size);
	reverse(array, size);
	show(array, size);


	return 0;
};

//shows the array elements
void show(int const array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	};
	std::cout << std::endl;	
};

//reverses the elements of the function
void reverse(int array[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = array[i];
		array[i] = array[size - 1 - i];
		array[size - 1 - i] = temp;
	};
};
