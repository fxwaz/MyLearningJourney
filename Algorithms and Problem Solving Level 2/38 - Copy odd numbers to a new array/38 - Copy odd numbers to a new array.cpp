// Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only odd numbers to another array using AddArrayElement, and print it
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enNumberType { Even = 1, Odd };

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

enNumberType CheckNumberType(int UserNumber)
{
	int Result = UserNumber % 2;
	if (Result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::Odd;
	}
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

void AddArrayElement(int Number, int Array[], int& arrLength)
{
	Array[arrLength] = Number;
	arrLength++;
}

void CopyOddNumbers(int SourceArray[], int DestinationArray[], int ArrayLength, int& NewArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (CheckNumberType(SourceArray[i]) == enNumberType::Odd)
		{
			AddArrayElement(SourceArray[i], DestinationArray, NewArrayLength);
		}
		 
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int NewArray[100];
	int ArrayLength;
	int NewArrayLength = 0;

	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "\nArray 1 Elements : \n";
	PrintArray(Array, ArrayLength);

	CopyOddNumbers(Array, NewArray, ArrayLength, NewArrayLength);

	cout << "\nArray 2 Odd Numbers : \n";
	PrintArray(NewArray, NewArrayLength);

}