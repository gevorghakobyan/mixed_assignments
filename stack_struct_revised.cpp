/*the program gets integers via push function which it holds in a 2-dimensional
 array inside a struct adding the last number at the end similar to stack in
 RAM. the second row of the array holds the minimum value of
 the main row up to that index. get_minimum function returns the minimum value
 among current elements. pop function displays last element of the arrays main
 row and deletes it.*/


#include <iostream>


struct Stack
{
	int array[100][2] = {{0}};
	int size = 0;
};


void push(Stack * s, int n);
void pop(Stack * s);
int get_minimum(Stack * s);


int main()
{
	Stack s;
	push(&s, 4);
	push(&s, 10);
	push(&s, -3);
	pop(&s);
	get_minimum(&s);
	return 0;
};


void push(Stack * s, int n)
{	
	if (s->size == 100)
	{
		std::cout << "Conventional stack FULL." << std::endl;
	}
	else
	{
		s->array[s->size][0] = n;
		if (s->size == 0)
		{
			s->array[0][1] = n;
		}
		else if (s->array[s->size - 1][1] > n)
		{
			s->array[s->size][1] = s->array[s->size - 1][1];
		}
		else
		{
			s->array[s->size][1] = n;
		};
		++s->size;
	};
};


void pop(Stack * s)
{
	if (s->size == 0)
	{
		std::cout << "No elements in stack." << std::endl;
	}
	else
	{
		std::cout << s->array[s->size - 1][0] << std::endl;
		--s->size;
	}
};


int get_minimum(Stack * s)
{
	if (s->size == 0)
	{
		std::cout << "No elements in stack." << std::endl;
	}
	else
	{
		std::cout << "Minimum value in the array: " <<  s->array[s->size - 1][1] << std::endl;
		return s->array[s->size][1];
	};
};
