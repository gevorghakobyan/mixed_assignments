#include <iostream>

int Sum(int* array, int size)
{
	if (size == 0)
	{
		return 0;
	};
	if (array[size - 1] % 2 == 1)
	{
		return array[size - 1] + Sum(array, size - 1);
	}
	else
	{
		return Sum(array, size - 1);
	};
};

int main()
{
	int array[10] = {0, 1, 1, 3, 4, 5, 6, 7, 8, 9};
	int sum = Sum(array, 10);
	std::cout << sum << std::endl;

	return 0;
}
