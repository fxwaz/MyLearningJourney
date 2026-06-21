// Write a program that inputs the number of seconds and changes it to days, hours, minutes, and seconds.
#include <iostream>
using namespace std;

struct stTaskDuration
{
	int Days; 
	int Hours;
	int Minutes;
	int Seconds;
};

int ReadPositiveNumber()
{

	int UserNumber;

	do
	{
		cout << "Please enter your number : ";
		cin >> UserNumber;

	} while (UserNumber <= 0);

	return UserNumber;

}


stTaskDuration ConvertSecondsToDaysHoursMinutesSeconds(int TotalSeconds)
{
	stTaskDuration result;

	int SecondsPerDay = 86400;
	int SecondsPerHour = 3600;
	int SecondsPerMinute = 60;
	int Remainder = 0;

	result.Days = TotalSeconds / SecondsPerDay;
	Remainder = TotalSeconds % SecondsPerDay;

	result.Hours = Remainder / SecondsPerHour;
	Remainder = Remainder % SecondsPerHour;
	
	result.Minutes = Remainder / SecondsPerMinute;
	Remainder = Remainder % SecondsPerMinute;

	result.Seconds = Remainder;

	return result;
}

void PrintResult(stTaskDuration result)
{
	cout << "\n" << result.Days << ":" << result.Hours << ":" << result.Minutes << ":" << result.Seconds << endl;
}


int main()
{
	PrintResult(ConvertSecondsToDaysHoursMinutesSeconds(ReadPositiveNumber()));
}
