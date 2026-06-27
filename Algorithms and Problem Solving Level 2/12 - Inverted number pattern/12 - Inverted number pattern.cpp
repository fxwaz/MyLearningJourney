// Write a program to read a number and print an inverted number pattern.
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

void PrintInvertedNumberPattern(int UserNumber)
{

	for (int i = UserNumber; i >= 1; i--)
	{

		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}

		cout << endl;

	}
}

int main()
{
	PrintInvertedNumberPattern(ReadPositiveNumber("Please enter a positive number : "));
}

