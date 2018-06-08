/* program requests integers from the user and returns the reverse of it following fashion: 75 => 57,
 -1303 => -3031, 40 => 4 and so on. program terminates in case of any non-integer input or 0.*/


#include <iostream>


int reverse(int a);


int main()
{
//int to hold the input
	int input_int = 0;
	std::cout << "Enter an integer to get the reverse of it. Enter anything other than an integer or 0 to quit: ";
	std::cin >> input_int;


//request integers and displays the reverse until an irrelevant input 
	while (input_int)
	{
		std::cout << "Reverse: " << reverse(input_int) << std::endl;
		std::cout << "Enter an integer: ";
		std::cin >> input_int;
	};


	std::cout << "Bye." << std::endl;
	return 0;
};


//integer reversing function. takes an int as input and returns the reverse as int
int reverse(int a)
{
	int reverse = 0;
	while (a / 10 != 0 || a % 10 != 0)
	{
		reverse = reverse * 10 + (a % 10);
		a = a / 10;
	};
	return reverse;
};
