/* program creates class A and class B which is a child to A. class A has it's otherwise private members made protected in this particular example to make them accessible in class B. In main() two objects are created and displayed. */

#include <iostream>

class A
{
protected:
	 int a;
public:
	A(int num = 5);
	void show();
};

class B: public A
{
	int b;
public:
	B(int num1 = 6, int num2 = 7);
	void display();
};

int main()
{
	A allah(3);
	B ballah(8, 9);
	std::cout << "class A objects protected member displayed: ";
	allah.show();
	std::cout << "class B objects inherited member displayed using parent class's member funcion: ";
	ballah.show();
	std::cout << "class B objects both inherited and indigenous members displayed using class B's own function for displaying: ";
	ballah.display();		
	return 0;
};

A::A(int num)
{
	a = num;
};

B::B(int num1, int num2)
{
	a = num1;
	b = num2;
};

void A::show()
{
	std::cout << a << std::endl;
};

void B::display()
{
	std::cout << a << " " << b << std::endl;
};
