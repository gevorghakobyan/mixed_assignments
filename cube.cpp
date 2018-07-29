//the program requests the text input that is going to be encrypted or decrypted
//then it requests the flags -- e or E for encryption -- d or D for decryption
//then requests the moves for every single cube
//moves are requested as many times as is the dividend of input text size and 8
//move combination of one cube is separated from the next one by ENTER
//the program automatically requests the required number of move combinations
//for a single cube can be inserted as many moves as YOU wish (YOUR HIGHNESS)
//moves are -- l or L for left -- r of R for right -- u or U for up -- d or D for down
//other symbols than this are kindly ignored
//after all the necessary requests are made the program returns the final text
//encrypted or decrypted


#include <iostream>
#include <string>
#include <vector>


//Cube class prototype
class Cube
{
	private:
//this string stores the symbols kept in a particular cube
		std::string cube_str;
//functions for turning the cube
		void right();
		void left();
		void up();
		void down();
//functions to perform cube manipulations based on the fact whether the initial code is beeing encrypted or decrypted
		void decode(std::string moves);
		void encode(std::string moves);
	public:
		Cube();
//the preferred constructor(not the default one)
		Cube(std::string input, std::string moves, char encode_decode, int cube_num);
		~Cube();
//displays cubes private string property
		void show();
};




int main()
{
//requests the text that is going to be encrypted or decrypted
	std::string str;
	std::cout << "Enter the string: \n			 ";
	std::getline(std::cin, str);

//requests the flag of encryption or decryption
	char encode_decode;
	std::cout << "'e' for encoding, 'd' for decoding:\n			";
	std::cin.get(encode_decode);
//the loop checks whether the input flag is valid (requests a new one if not)
	while (encode_decode != 'E' && encode_decode != 'e' && encode_decode != 'D' && encode_decode != 'd')
	{
		std::cin.get();
		std::cout << "wrong input\n			";
		std::cin.get(encode_decode);
	};

//vector to hold number of cubes corresponding the lenght of the input text due to be encrypted or decrypted
	std::vector<Cube> v;
	std::cout << "Move combinations for every 8 symbols\n(u -- up\nd -- down\nl -- left\nr -- right\nother symbols will be ignored?)\n";
//this string is going to hold the combination of moves for cubes
	std::string moves;

//loop to request the moves for consequent cube, create the cube based on the moves, encryption-decryption flag and the part of the input text that corresponds to that consequent cube. after creating the cube the loop adds it at the end of the vector
	for (int i = 0; i < (str.size() % 8 == 0 ? str.size() / 8 : (str.size() / 8) + 1); ++i)
	{	
		std::cout << "			";
		std::cin >> moves;
		Cube cube(str, moves, encode_decode, i);
		v.push_back(cube);
	};

//loop to display the output text iterating alond the vector and concatenating individual final strings of cubes
	std::cout << "The output string is: ";
	for (Cube n : v)
	{
		n.show();
	};
	
	return 0;
};




//default constructor of cubes
Cube::Cube()
{
	cube_str = "^^^^^^^^";
};

//preferred constructor -- has 4 parameters -- the part of the input text that corresponds to the given cube based on number of order the cube has -- second parameter is the combination of moves -- encryption-decryption flag -- the number of order of a particular cube
Cube::Cube(std::string input, std::string moves, char encode_decode, int cube_num)
{
//cube string is set to carrets, then its replaced by the function argument 'input' and if 'input' has less than 8 characters, then the rest are filled with asterisks '*'
	cube_str = "^^^^^^^^";
	int size = input.size() - cube_num * 8;
	for (int i = 0; i < size && i < 8; ++i)
	{
		cube_str[i] = input[i + cube_num * 8];
	};
	if (size < 8)
	{
		for (int i = size; i < 8; ++i)
		{
			cube_str[i] = '*';
		};
	};

//this switch calls encode or decode functions based on encryption-decryption flag
	switch (encode_decode)
	{
		case 'e':
		case 'E': encode(moves);
			break;
		case 'd':
		case 'D': decode(moves);
			break;
		default: break;
	};
};


Cube::~Cube()
{	
};

//displays given cubes final string
void Cube::show()
{
	std::cout << cube_str;
};

//next 4 functions turn the cube along the direction mentioned by the name of the function. this functions shift given cubes strings elements according to how they would be changed in reality
void Cube::right()
{
	cube_str[8] = cube_str[6];
	cube_str[6] = cube_str[7];
	cube_str[7] = cube_str[3];
	cube_str[3] = cube_str[2];
	cube_str[2] = cube_str[8];
	cube_str[8] = cube_str[5];
	cube_str[5] = cube_str[4];
	cube_str[4] = cube_str[0];
	cube_str[0] = cube_str[1];
	cube_str[1] = cube_str[8];
	cube_str[8] = '\0';
};


void Cube::left()
{
	cube_str[8] = cube_str[6];
	cube_str[6] = cube_str[2];
	cube_str[2] = cube_str[3];
	cube_str[3] = cube_str[7];
	cube_str[7] = cube_str[8];
	cube_str[8] = cube_str[5];
	cube_str[5] = cube_str[1];
	cube_str[1] = cube_str[0];
	cube_str[0] = cube_str[4];
	cube_str[4] = cube_str[8];
	cube_str[8] = '\0';
};


void Cube::up()
{
	cube_str[8] = cube_str[0];
	cube_str[0] = cube_str[4];
	cube_str[4] = cube_str[7];
	cube_str[7] = cube_str[3];
	cube_str[3] = cube_str[8];
	cube_str[8] = cube_str[1];
	cube_str[1] = cube_str[5];
	cube_str[5] = cube_str[6];
	cube_str[6] = cube_str[2];
	cube_str[2] = cube_str[8];
	cube_str[8] = '\0';
};


void Cube::down()
{
	cube_str[8] = cube_str[0];
	cube_str[0] = cube_str[3];
	cube_str[3] = cube_str[7];
	cube_str[7] = cube_str[4];
	cube_str[4] = cube_str[8];
	cube_str[8] = cube_str[1];
	cube_str[1] = cube_str[2];
	cube_str[2] = cube_str[6];
	cube_str[6] = cube_str[5];
	cube_str[5] = cube_str[8];
	cube_str[8] = '\0';
};

//encode function that reads the moves for given cube and performs in corresponding order
void Cube::encode(std::string moves)
{
	for (int i = 0; i < moves.size(); ++i)
	{
		switch (moves[i])
		{
			case 'L':
			case 'l': left();
				break;
			case 'R':
			case 'r': right();
				break;
			case 'U':
			case 'u': up();
				break;
			case 'D':
			case 'd': down();
				break;
			default: break; 
		};	
	};
};

//decrypt function that reads the moves backwards and performs the opposite of a given move
void Cube::decode(std::string moves)
{
	for (int i = moves.size() - 1; i >= 0; --i)
	{
		switch (moves[i])
		{
			case 'L':
			case 'l': right();
				break;
			case 'R':
			case 'r': left();
				break;
			case 'U':
			case 'u': down();
				break;
			case 'D':
			case 'd': up();
				break;
			default: break; 
		};	
	};

};
