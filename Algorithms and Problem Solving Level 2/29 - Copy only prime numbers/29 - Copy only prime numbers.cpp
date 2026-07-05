// Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only prime numbers to another array and print it.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enPrimeOrNot { Prime, NotPrime };

int ReadNumberBetween(string Message, int From, int To)
{
	int UserNumber;

	do
	{
		cout << Message;
		cin >> UserNumber;

		if (UserNumber < From || UserNumber > To)
			cout << "You have to enter a number between " << From << " and " << To << ".\n\n";

	} while (UserNumber < From || UserNumber > To);

	return UserNumber;
}

int RandomNumber(int From, int To)
{
	int Randomnumber = rand() % (To - From + 1) + From;

	return Randomnumber;
}

void FillArrayWithRandomNumbers(int Array[], int& ArrayLength)
{
	ArrayLength = ReadNumberBetween("Please enter number of elements: ", 1, 100);

	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[], int ArrayLength)
{

	for (int i = 0; i < ArrayLength; i++)
	{

		cout << Array[i] << " ";

	}

	cout << endl;

}

enPrimeOrNot CheckIfPrimeOrNot(int UserNumber)
{

	if (UserNumber < 2)
		return enPrimeOrNot::NotPrime;

	for (int i = 2; i < UserNumber; i++)
	{
		if (UserNumber % i == 0)
			return enPrimeOrNot::NotPrime;
	}

	return enPrimeOrNot::Prime;
}

void CopyOnlyPrimeNumbersInArray(int SourceArray[], int DestinationArray[], int ArrayLength, int& NewArrayLength)
{
	NewArrayLength = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckIfPrimeOrNot(SourceArray[i]) == enPrimeOrNot::Prime)
		{
			DestinationArray[NewArrayLength] = SourceArray[i];
			NewArrayLength++;
		}
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int NewArray[100];
	int ArrayLength;
	int NewArrayLength;

	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "\nArray 1 Elements : \n";
	PrintArray(Array, ArrayLength);

	CopyOnlyPrimeNumbersInArray(Array, NewArray, ArrayLength, NewArrayLength);

	cout << "\nPrime Numbers in Array2 : \n";
	PrintArray(NewArray, NewArrayLength);

}