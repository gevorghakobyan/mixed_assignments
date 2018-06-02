#include <iostream>
#include <string>

//function prototype
void reverse_str(char * ch);

int main(void)
{

//requests the string
	std::cout << "Enter the string: ";
	char str[100];
	std::cin.getline(str, 100);

//reverses the string and displays it
	reverse_str(str);
	std::cout << str << std::endl;
	return 0;
};


//string reversing function definition
void reverse_str(char * ch)
{

//finds string size
	int size = 0;
	while (*(ch + size) != '\0')
	{
		++size;
	};
	size -= 1;

//reverses the string
	for (int i = 0; i <= size / 2; i++)
	{
		char temp = *(ch + i);
		*(ch + i) = *(ch + size - i);
		*(ch + size - i) = temp;
	};
};
