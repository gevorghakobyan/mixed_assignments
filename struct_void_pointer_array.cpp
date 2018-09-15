/* array of struct Type.
 * Type has a void pointer and a indicator to what points the void pointer
 * in a specific case.*/

#include <iostream>
#include <string>


enum CASE {INT, BOOL, CHAR};

struct Type
{
	CASE d_type;
	void* tp;
	friend std::ostream& operator<<(std::ostream&, Type& obj);
};

int main()
{
	Type array[3];
	array[0].d_type = INT;
	array[0].tp = new int;
	*(static_cast<int*>(array[0].tp)) = 3;
	array[1].d_type = BOOL;
	array[1].tp = new bool;
	*(static_cast<bool*>(array[1].tp)) = true;
	array[2].d_type = CHAR;
	array[2].tp = new char;
	*(static_cast<char*>(array[2].tp)) = 'f';
	
	for (int i = 0; i < 3; ++i)
	{
		std::cout << array[i];
	};

	for (int i = 0; i < 3; ++i)
	{
		array[i].tp = nullptr;
	};

	return 0;
};

std::ostream& operator<<(std::ostream& cout, Type& obj)
{
	switch(obj.d_type)
	{
		case 0:
			cout << "int = " << *(static_cast<int*> (obj.tp)) << std::endl;
			break;
		case 1:
			cout << "bool = " << *(static_cast<bool*> (obj.tp)) << std::endl;
			break;
		case 2:
			cout << "char = " << *(static_cast<char*> (obj.tp)) << std::endl;
			break;
		default:
			;
	};
};
