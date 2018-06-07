#include <iostream>

//structure prototype
struct Stack
{
	int array[100] = {0};
//actual number of elements input by the user
	int size = 0;
};


//function prototypes
void push(Stack * s, int n);
void pop(Stack * s);



int main()
{
	Stack s;
	push(&s, 4);
	push(&s, 10);
	push(&s, -3);
	pop(&s);
	return 0;
};


//push function which pushes the input number into the stack and increments the
//size of the array (which expresses the actual number of elements in the array)
void push(Stack * s, int n)
{	
	if (s->size == 100)
	{
		std::cout << "Conventional stack FULL." << std::endl;
	}
	else
	{
	s->array[s->size] = n;
	++s->size;
	};
};


//displays the last element in the stack and "deletes" it (actually it just
// forgets about the element decrementing the size of the array)
void pop(Stack * s)
{
	if (s->size == 0)
	{
		std::cout << "No elements in stack." << std::endl;
	}
	else
	{
	std::cout << s->array[s->size - 1] << std::endl;
	--s->size;
	}
};
