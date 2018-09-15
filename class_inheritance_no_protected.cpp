/* parent class A with no protected members, child class B.
 A class object created and displayed,
 B class object created and displayed using class A member function and class B member function.*/

#include <iostream>

class A
{
        int a;
public:
        A(int num = 5);
        void show();
	void set_a(int num);
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
	A a_obj(7);
	std::cout << "A class object printed: \n";
	a_obj.show();
	B b_obj(1, 2);
	std::cout << "B class object's A part printed using A class member function: \n";
	b_obj.show();
	std::cout << "B class object printed using B's member function: \n";
	b_obj.display();

        return 0;
};

A::A(int num)
{
        a = num;
};

void A::set_a(int num)
{
	a = num;
};

void A::show()
{
        std::cout << a << std::endl;
};

B::B(int num1, int num2)
{
        A::set_a(num1);
        b = num2;
};

void B::display()
{
	show();
        std::cout << b << std::endl;
};

		
