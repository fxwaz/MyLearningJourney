// Write a program to read a number and print inverted letter pattern.
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

void PrintInvertedLettersPattern(int UserNumber)
{

	int Letters = 65 + UserNumber - 1;

	for (int i = UserNumber; i >= 1; i--)
	{

		for (int j = i; j >= 1; j--)
		{
			cout << char(Letters);
		}

		Letters--;
		cout << endl;

	}

}


int main()
{
	PrintInvertedLettersPattern(ReadPositiveNumber("Please enter a positive number : "));
}