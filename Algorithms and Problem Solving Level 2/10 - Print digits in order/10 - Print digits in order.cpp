// Write a program to read a number and print it in order from left to right.
#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;


	} while (UserNumber <= 0);

	return UserNumber;
}

int ReverseNumber(int UserNumber)
{
	int Remainder = 0;
	int Reverse = 0;

	while (UserNumber > 0)
	{
		Remainder = UserNumber % 10;
		UserNumber = UserNumber / 10;
		Reverse = Reverse * 10 + Remainder;
	}

	return Reverse;

}

void PrintDigits(int UserNumber)
{
	int Remainder = 0;

	while (UserNumber > 0)
	{
		Remainder = UserNumber % 10;
		UserNumber = UserNumber / 10;
		cout << Remainder << endl;
	}
}

int main()
{
	PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number : ")));
}