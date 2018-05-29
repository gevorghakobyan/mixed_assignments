#include <iostream>
#include <cctype>

void char_unique(char const * pstr);

int main()
{
	std::cout << "Enter the string without non-letter symbols: ";
	char str[30];
	std::cin >> str;
	char_unique(str);
};

void char_unique(char const * pstr)
{
	int total_bit = 0;
	int ch_bit = 0;
	int offset = 0;
	for (int i = 0; *(pstr + 1) != '\0'; ++i)
	{
		offset = std::tolower(*(pstr + 1)) - 'a';
		ch_bit = 1 << offset;
		if (total_bit & ch_bit)
		{
			std::cout << "NOT UNIQUE.";
			return;
		}
		else
		{
			total_bit |= ch_bit;
		};
	};
	std::cout << "CHARACTER UNIQUE STRING.";
};
