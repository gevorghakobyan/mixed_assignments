/* the program defines an abstract base class and two derived classes.
 * then an array of abstract class objects is created, 
 * the first element of which is of first derived class, 
 * and the second of the second derived class. 
 * Derived classes have show() function, 
 * which diplays the only private member of its class's object in a different style. 
 * Using pointers to abstract class objects 
 * the program calls show() function iteratively for two different 
 * class objects, displaying divergent results. 
 */

#include <iostream>

// prototypes ============================================================

class Abstract
{
public:
	virtual void show() = 0;
};

class Derived1 : public Abstract
{
private:
	int i = 34;
public:
	void show();
};

class Derived2 :public Abstract
{
private:
	int j = 7;
public:
	void show();
};

// main function ========================================================

int main()
{
	Abstract** array = new Abstract*[2];
	array[0] = new Derived1;
	array[1] = new Derived2;
	for (int i = 0; i < 2; ++i)
	{
		array[i]->show();
	};
	for (int i = 0; i < 2; ++i)
	{
		delete array[i];
		array[i] = nullptr;
	};
	delete [] array;
	array = nullptr;
	return 0;
};

// function definitions =================================================

void Derived1::show()
{
	std::cout << "First derived: " << i << std::endl;
};

void Derived2::show()
{
	std::cout << "Second derived: " << j << std::endl;
};
