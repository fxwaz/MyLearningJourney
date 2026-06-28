// Write a program to read a number and print a letter pattern.
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

void PrintLettersPattern(int UserNumber)
{

	int Letter = 65;

	for (int i = 1; i <= UserNumber; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			cout << char(Letter);
		}

		Letter++;
		cout << endl;

	}

}

int main()
{
	PrintLettersPattern(ReadPositiveNumber("Please enter a positive number : "));
}