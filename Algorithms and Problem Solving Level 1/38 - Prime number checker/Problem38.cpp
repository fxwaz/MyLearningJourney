// Write a program to check whether a number is prime or not.
#include <iostream>

using namespace std;

enum enIsPrime { Prime = 1, NotPrime };

int ReadNumber()
{
	int UserNumber;

	do
	{
		cout << "Please enter your number : ";
		cin >> UserNumber;

	} while (UserNumber <= 0);


	return UserNumber;
}

enIsPrime IsPrime(int UserNumber)
{
	if (UserNumber == 1)
		return enIsPrime::NotPrime;

	for (int i = 2; i < UserNumber; i++)
	{
		if (UserNumber % i == 0)
			return enIsPrime::NotPrime;
	}

	return enIsPrime::Prime;
}

void PrintResult(int UserNumber)
{
	if (IsPrime(UserNumber) == enIsPrime::Prime)
		cout << "\nYour number is Prime number\n";
	else
		cout << "\nYour number is Not prime number\n";
}
int main()
{
	PrintResult(ReadNumber());
}