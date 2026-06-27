// Write a program to read a number and print a number pattern.
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

void PrintNumberPattern(int UserNumber)
{
	for (int i = 1; i <= UserNumber; i++)
	{
		for (int j = 1; j <= i; j++)
		{

			cout << i;
			
		}

		cout << endl;

	}
}

int main()
{
	PrintNumberPattern(ReadPositiveNumber("Please enter a positive number : "));
}