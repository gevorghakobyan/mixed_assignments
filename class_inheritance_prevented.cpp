/* parent class A final -- can't be inherited
an attempt to inherit causes compile error*/

#include <iostream>

class A final
{
	
};

class B: public A
{

};

int main()
{
	A a;
	B b;
	return 0;
};


