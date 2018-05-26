#include <iostream>
#include <string>

//structure prototype
struct Student
{
	std::string name;
	int age;
	double average;
	std::string univ_name;
};

int main(void)
{
//an array of 3 students
	Student stud_arr[3];
//loop for requesting student information for each of the three
	for (int i = 0; i < 3; i++)
	{
//requests students name
		std::cout << "Enter the " << i + 1 << "th students name: ";
		std::getline(std::cin, stud_arr[i].name);
		std::cout << "Enter the age: ";
		std::cin >> stud_arr[i].age;
//requests the quantity of scores, then each single score and then calculates the average
		double quantity_of_scores;
		std::cout << "Enter how many scores the student has to calculate the average: ";
		std::cin >> quantity_of_scores;
		int score_arr[20] = {0};
		int total_score = 0;
//request each single score
		for (int j = 0; j < quantity_of_scores; j++)
		{
			std::cout << "Enter the " << j + 1 << "th score: ";
			std::cin >> score_arr[j];
			total_score += score_arr[j];
		};
		stud_arr[i].average = total_score / quantity_of_scores;
		std::cout << "The average of this student is " << stud_arr[i].average << std::endl;
//requests students university name
		std::cin.get();
		std::cout << "Finally enter this particular students university name: ";
		std::getline(std::cin, stud_arr[i].univ_name);
		std::cout << stud_arr[i].univ_name << std::endl;
	};
	return 0;
};
