// Write a program to print all perfect numbers from 1 to N.
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

bool IsPerfectNumber(int UserNumber)
{
	int SumBox = 0;

	for (int i = 1; i < UserNumber; i++)
	{
		if (UserNumber % i == 0)
			SumBox = SumBox + i;
	}

	return SumBox == UserNumber;
}

void PrintAllPerfectNumbers(int UserNumber)
{
	for (int i = 1; i <= UserNumber; i++)
	{
		if (IsPerfectNumber(i))
			cout << i << endl;
	}
}

int main()
{
	PrintAllPerfectNumbers(ReadPositiveNumber("Please enter a positive number : "));
}