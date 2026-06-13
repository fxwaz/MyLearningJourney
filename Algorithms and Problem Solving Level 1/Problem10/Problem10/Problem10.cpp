// Write a program that asks the user to enter three exam marks, then prints their average.
#include <iostream>
using namespace std;


void ReadMarks(int &mark1, int &mark2, int &mark3)
{

	cout << "Please enter your first mark : ";
	cin >> mark1;

	cout << "Please enter your second mark : ";
	cin >> mark2;

	cout << "Please enter your third mark : ";
	cin >> mark3;

}

int SumMarks(int mark1, int mark2, int mark3)
{
	return mark1 + mark2 + mark3;
}

float CalculateAverage(int mark1, int mark2, int mark3)
{
	return float(SumMarks(mark1, mark2, mark3)) / 3;
}

void PrintResult(float average)
{
	cout << "The Average is : " << average << endl;
}

int main()
{
	int mark1, mark2, mark3;

	ReadMarks(mark1, mark2, mark3);
	PrintResult(CalculateAverage(mark1, mark2, mark3));
}