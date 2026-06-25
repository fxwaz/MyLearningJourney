// Write a program to print all prime numbers from 1 to N
#include <iostream>
using namespace std;

enum enPrimeOrNotPrime { Prime = 1, NotPrime};

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

enPrimeOrNotPrime CheckIfPrime(int UserNumber)
{
	if (UserNumber < 2)
		return enPrimeOrNotPrime::NotPrime;
	
	for (int i = 2; i < UserNumber; i++)
	{		
		if (UserNumber % i == 0)
			return enPrimeOrNotPrime::NotPrime;
	}

	return enPrimeOrNotPrime::Prime;
}

void PrintAllPrimeNumbers(int UserNumber)
{
	cout << "\nPrime Numbers from " << 1 << " to " << UserNumber << " are : " << endl;

	for (int i = 2; i <= UserNumber; i++)
	{
		if (CheckIfPrime(i) == enPrimeOrNotPrime::Prime)
			cout << i << endl;
	}
}

int main()
{
	PrintAllPrimeNumbers(ReadPositiveNumber("Please enter positive number : "));
}
