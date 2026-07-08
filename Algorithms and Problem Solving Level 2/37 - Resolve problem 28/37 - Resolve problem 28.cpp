// Write a program to fill array with max size 100 with random numbers from 1 to 100, copy it to another array using AddArrayElement, and print it.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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

void AddArrayElement(int Number, int Array[], int& arrLength)
{
	arrLength++;
	Array[arrLength - 1] = Number;
}

void CopyArrayUsingAddArrayElements(int SourceArray[], int DestinationArray[], int ArrayLength, int& NewArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		AddArrayElement(SourceArray[i], DestinationArray, NewArrayLength);
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

	CopyArrayUsingAddArrayElements(Array, NewArray, ArrayLength, NewArrayLength);

	cout << "\nArray 2 Elements after copy : \n";
	PrintArray(NewArray, NewArrayLength);

}