// Write a program read a number , then print all digit frequency in that number.
#include <iostream>
#include <string>
using namespace std;


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

int CountDigitFrequency(int UserNumber, int DigitToCheck)
{
	int Remainder = 0;
	int HowManyDigit = 0;


	while (UserNumber > 0)
	{
		Remainder = UserNumber % 10;

		if (Remainder == DigitToCheck)
			HowManyDigit++;

		UserNumber = UserNumber / 10;
	}

	return HowManyDigit;
}

void PrintAllDigitsFrequency(int UserNumber)
{

	for (int i = 0; i <= 9; i++)
	{
		int Frequency = CountDigitFrequency(UserNumber, i);

		if (Frequency > 0)
			cout << "Digit " << i << " Frequency is " << Frequency << " Time(s).\n";
	}

}


int main()
{
	PrintAllDigitsFrequency(ReadPositiveNumber("Please enter your number : "));
}