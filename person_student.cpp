#include <iostream>


// prototypes ============================================================
class Person
{
private:
	std::string m_name;
public:
	Person(std::string const & name = "no name");
	~Person();
	void setName(std::string const & name);
	std::string getName();
	virtual void sayHello();
};

class Student : public Person
{
private:
	
public:
	Student(std::string const & name = "no name");
//	~Student();
	void sayHello();
};


// main ==================================================================
int main()
{
	Person* arrayStudent = new Student[3];
	std::string name_input;
	for (int i = 0; i < 3; ++i)
	{
		std::cout << "Enter the name: ";
		std::cin >> name_input;
		arrayStudent[i].setName(name_input);
	};
	for (int i = 0; i < 3; ++i)
	{
		arrayStudent[i].sayHello();
	};
	delete [] arrayStudent;
	arrayStudent = nullptr;
	return 0;
};



// implementation ========================================================
Person::Person(std::string const & name) : m_name(name)
{
};

Person::~Person()
{
};

void Person::setName(std::string const & name)
{
	m_name = name;
};

std::string Person::getName()
{
	return m_name;
};

void Person::sayHello()
{
	std::cout << "Hello! My name is " << getName() << "." << std::endl;
};

Student::Student(std::string const & name) : Person(name)
{
//	Person::setName(name);
};

/*
Student::~Student()
{
};
*/

void Student::sayHello()
{
	std::cout << "Hi. I'm a student - " << getName() << "." << std::endl;
};
