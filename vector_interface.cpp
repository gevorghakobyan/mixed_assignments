#include <iostream>
#include "vector.h"

int main()
{
	
	Vector v;
	v.push_back(5);
	v.insert_at(0, 4);
	Vector copy(v);
	std::cout << copy.get_at(0) << copy.get_at(1);


	return 0;
};
