// Write a program to calculate the task duration in seconds and print it on screen
#include <iostream>
using namespace std;


struct stTaskDuration
{
	int NumberOfDays;
	int NumberOfHours;
	int NumberOfMinutes;
	int NumberOfSeconds;
};


int ReadPositiveNumber(string message)
{
	int UserNumber;

	do
	{
		cout << message;
		cin >> UserNumber;

	} while (UserNumber <= 0);

	return UserNumber;
}


stTaskDuration ReadTaskDuration()
{

	stTaskDuration result;

	result.NumberOfDays = ReadPositiveNumber("Please enter number of days : ");
	result.NumberOfHours = ReadPositiveNumber("Please enter number of hours : ");
	result.NumberOfMinutes = ReadPositiveNumber("Please enter number of minutes : ");
	result.NumberOfSeconds = ReadPositiveNumber("Please enter number of seconds : ");

	return result;

}

int ConvertToSeconds(stTaskDuration numbers)
{
	int DayPerSeconds = 86400;
	int HourPerSeconds = 3600;
	int MinutePerSeconds = 60;
	int AllinSeconds;

	AllinSeconds = numbers.NumberOfDays* DayPerSeconds;
	AllinSeconds += numbers.NumberOfHours* HourPerSeconds;
	AllinSeconds += numbers.NumberOfMinutes* MinutePerSeconds;
	AllinSeconds += numbers.NumberOfSeconds;
	
	return AllinSeconds;
}

void PrintResult(int result)
{
	cout << "Task duration in Seconds = " << result << endl;
}

int main()
{
	PrintResult(ConvertToSeconds(ReadTaskDuration()));
}
