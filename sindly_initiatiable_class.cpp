//class that can be initiated only once

#include <iostream>

// prototypes ----------------------------------------------------------------------------
class A
{
private:
	int a;
	static A* pA;
	A();
	A(int num);
	virtual ~A();
public:
	static A* get_p();
	static A* get_p(int num);
	static void free_p();
	int get_a();
};

// main function -------------------------------------------------------------------------
int main()
{


//creates and displays the first object
	A* obj = A::get_p(3);
	std::cout << obj->get_a() << std::endl;


//creates the second object and while displaying first and second objects,
//it turns out that the second one has overwritten the first one and now
//they are the same
	A* obj2 = A::get_p(4);
	std::cout << obj->get_a() << std::endl << obj2->get_a() << std::endl;
	return 0;
};

// class implementation ------------------------------------------------------------------
A* A::pA = nullptr;

A::A()
{
};

A::A(int num)
{
	a = num;
};

A::~A()
{
	free_p(); 
};

A* A::get_p()
{
	if (pA == nullptr)
	{
		pA = new A();
		return pA;
	}
	return pA;
};

A* A::get_p(int num)
{
	if (pA == nullptr)
	{
		pA = new A(num);
	}
	else
	{
		pA->a = num;
	};
	return pA;
};

void A::free_p()
{
	delete pA;
	pA = nullptr;
};

int A::get_a()
{
	return a;
};
