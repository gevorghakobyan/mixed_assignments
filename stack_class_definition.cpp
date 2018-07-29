#include <iostream>
#include "stack_class.h"

Stack::Stack()
{
	int size = 100;
	int * arr = new int [size];
	int top = 0;
};

void Stack::push (int num)
{
	if (top == size)
	{
		size += 100;
		int * new_arr = new int [size];

		for (int i = 0; i < top; ++i)
		{
			new_arr[i] = arr[i];
		};
		
		delete [] arr;		

		arr = new_arr;
	};
	
	arr[top] = num;
	++top;
};

void Stack::pop()
{
	if (top == 0)
	{
		std::cout << "Nothing in the stack." << std::endl;
		return;
	};	
	
	std::cout << arr[top - 1] << std::endl;
	--top;
};


Stack::~Stack()
{
	delete [] arr;
};
