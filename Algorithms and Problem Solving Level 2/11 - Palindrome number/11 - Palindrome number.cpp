// Write a program to read a number and check if it is Palindrome
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

bool IsPalindrome(int UserNumber)
{
	return UserNumber == ReverseNumber(UserNumber);
}

void PrintResult(int UserNumber)
{
	if (IsPalindrome(UserNumber))
		cout << "\nYes, It's a Palindrome number\n";
	else
		cout << "\nNo, It's not a Palindrome number\n";
}

int main()
{
	PrintResult(ReadPositiveNumber("Please enter a positive number : "));
}