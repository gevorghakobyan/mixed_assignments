/* parent class A, child class B.
class A friend function -- A* as argument.
calling the above function for class A and B objects using.*/

#include <iostream>

class A
{
	int a = 0;
public:
	friend void show(A* a_obj);	
};

class B: public A
{
	int b = 1;
};

int main()
{
	A a;
	show(&a);
	B b;
	show(&b);
	return 0;
};

void show(A* a_obj)
{
	std::cout << a_obj->a << std::endl;
};
