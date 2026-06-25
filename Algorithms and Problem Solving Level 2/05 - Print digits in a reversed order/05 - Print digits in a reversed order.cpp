// Write a program to read a number and print it in a reversed order.
#include <iostream>
#include <string>
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

void PrintDigits(int UserNumbers)
{
	int Remainder = 0;

	while (UserNumbers > 0)
	{
		Remainder = UserNumbers % 10;
		UserNumbers = UserNumbers / 10;
		cout << Remainder << endl;
	}
}

int main()
{

	PrintDigits(ReadPositiveNumber("Please enter your numbers : "));

}