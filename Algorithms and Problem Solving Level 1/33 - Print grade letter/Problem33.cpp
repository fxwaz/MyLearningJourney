// Write a program to ask the user to enter a grade, then print the grade letter.
#include <iostream>
using namespace std;


int ReadGradeInRange(int from, int to)
{

	int UserGrade;

	do
	{

		cout << "Please enter your grade number from " << from << " To " << to << " : ";
		cin >> UserGrade;

	} while (UserGrade < from || UserGrade > to);


	return UserGrade;

}

char GetGradeLetter(int UserGrade)
{
	if (UserGrade >= 90)
		return 'A';
	else if (UserGrade >= 80)
		return 'B';
	else if (UserGrade >= 70)
		return 'C';
	else if (UserGrade >= 60)
		return 'D';
	else if (UserGrade >= 50)
		return 'E';
	else
		return 'F';
}

void PrintResult(char grade)
{
	cout << "Your grade is : " << grade << endl;
}

int main()
{
	PrintResult(GetGradeLetter(ReadGradeInRange(0, 100)));
}

