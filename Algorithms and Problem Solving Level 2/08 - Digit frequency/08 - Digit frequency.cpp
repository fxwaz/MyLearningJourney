// Write a program read a digit and a number , then print digit frequency in that number.
#include <iostream>
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

void PrintResult(int DigitToCheck, int HowMany)
{
	cout << "Digit " << DigitToCheck << " Frequency is " << HowMany << " Time(s)" << endl;
}

int main()
{
	int UserNumber = ReadPositiveNumber("Please enter your number : ");
	int DigitToCheck = ReadPositiveNumber("Please enter one digit to check : ");
	int Frequency = CountDigitFrequency(UserNumber, DigitToCheck);

	PrintResult(DigitToCheck, Frequency);
}