// Write a program to read a number and print the sum of its digits.
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


int SumDigits(int UserNumber)
{
	int Remainder = 0;
	int SumBox = 0;


	while (UserNumber > 0)
	{
		
		Remainder = UserNumber % 10;
		SumBox = SumBox + Remainder;
		UserNumber = UserNumber / 10;

	}

	return SumBox;
}

void PrintResult(int Result)
{

	cout << "\nSum of Digits = " << Result << endl;

}

int main()
{
	PrintResult(SumDigits(ReadPositiveNumber("Please Enter a positive numbers : ")));
}