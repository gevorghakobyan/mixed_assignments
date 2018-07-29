/* the program defines bitset class, that has a private vector holding integers which are used as bit containers. the public methods are set, unset and
get for implementing specific bits.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// prototypes = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

class bitset
{
private:
	std::vector<unsigned int> vec;
	int ULL_size;
public:
	bitset();
	void set(int bit);
	void show();
	void unset(int bit);
	bool get(int bit);
};

// main function = = = = = = = = = = = = = = = = = = = = = = = = = = =

int main()
{
	bitset a;
	a.set(31);
	a.set(124);
	a.set(30);
	a.show();
	std::cout << std::endl;
	a.unset(30);
	a.show();
	std::cout << a.get(124) << " " << a.get(125) << std::endl;
	return 0;
};

// implementation = = = = = = = = = = = = = = = = = = = = = = = = = = = 

bitset::bitset()
{
	vec.push_back(0);
	ULL_size = sizeof(vec[0]) * 8;
};

void bitset::set(int bit)
{
	int ULL_index = ceil(static_cast<double> (bit) / ULL_size) - 1;
	if (ULL_index >= vec.size())
	{
		int size = vec.size();
		for (int i = 0; i < ULL_index + 1 - size; ++i)
		{
			vec.push_back(0);
		};
	};
 	
	vec[ULL_index] = vec[ULL_index] | 1 << (ULL_size - bit % ULL_size);
};

void bitset::unset(int bit)
{
	int ULL_index = ceil(static_cast<double> (bit) / ULL_size) - 1;
	if (ULL_index < vec.size())
	{
		vec[ULL_index] = vec[ULL_index] & (((UINT_MAX - 1) << (ULL_size - bit % ULL_size)) | (UINT_MAX - 1) >> (bit % ULL_size));
	};
};

bool bitset::get(int bit)
{
	int ULL_index = ceil(static_cast<double> (bit) / ULL_size) - 1;
	if (ULL_index < vec.size())
	{
		return vec[ULL_index] & 1 << (ULL_size - bit % ULL_size);
	}
	else
	{
		return false;
	};
};

void bitset::show()
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	};
};

