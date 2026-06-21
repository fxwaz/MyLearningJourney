// Write a program to read a NumberOfHours and calculates the number of weeks, and days included in that number.
#include <iostream>
using namespace std;


struct stDaysAndWeeks
{
	float Days;
	float Weeks;
};

float ReadNumberOfHours()
{
	float NumberOfHours;

	cout << "Please enter number of hours : ";
	cin >> NumberOfHours;

	return NumberOfHours;
}

stDaysAndWeeks ConvertToDaysAndWeeks(float hours)
{
	stDaysAndWeeks Result;
	float HoursPerWeek = 168;
	float HoursPerDay = 24;

	Result.Weeks = hours / HoursPerWeek;
	Result.Days = hours / HoursPerDay;

	return Result;
}

void PrintResult(stDaysAndWeeks result)
{
	cout << result.Weeks << " Weeks " << endl;
	cout << result.Days << " Days " << endl;
}

int main()
{
	PrintResult(ConvertToDaysAndWeeks(ReadNumberOfHours()));
}