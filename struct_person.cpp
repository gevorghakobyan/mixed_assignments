#include <iostream>
#include <string>

//struct Person prototype
struct Person
{
	std::string name;
	int age;
	bool sex;
	std::string email;
};

//function prototypes 
Person& fillPerson(Person & person);
void displayPerson(Person const & person);


int main()
{
	Person chief;
	fillPerson(chief);
	displayPerson(chief);
	return 0;
};

//function that takes Person reference as argeument, fills it with information requesting from the user, and returns the same reference of the person
Person& fillPerson(Person & person)
{
	std::cout << "Enter name: ";
	std::getline(std::cin, person.name);
	std::cout << "Enter age: ";
	std::cin >> person.age;
	std::cout << "Enter sex: 0 for male, any other number for female: ";
	std::cin >> person.sex;
	std::cin.get();
	std::cout << "Enter email: ";
	std::getline(std::cin, person.email);
};


//function that takes person reference as argument and displays its contents
void displayPerson(Person const & person)
{
	std::cout << person.name << " is " << person.age << " years old "; 
	if (person.sex == 0)
	{
		std::cout << " male. His ";
	}
	else
	{
		std::cout << "female. Her ";
	}
	std::cout << "email is " << person.email << std::endl;
};
