/* Parent class A, child class B.
Program simply created a single object of the two classes and
demonstrates their constructors and destructors being called.*/

#include <iostream>

class A
{
public:
	A();
	~A();
};

class B: public A
{
public:
	B();
	~B();
};

int main()
{
	std::cout << "Creating A class object:\n";
	A a;
	std::cout << "Creating B class object:\n";
	B b;
	return 0;
};

A::A()
{
	std::cout << "A constructor called" << std::endl;
};

A::~A()
{
	std::cout << "A destructor called" << std::endl;
};

B::B()
{
	std::cout << "B constructor called" << std::endl;
};

B::~B()
{
	std::cout << "B destructor called" << std::endl;
};
