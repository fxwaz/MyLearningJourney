// Write a program to fill array with max size 100 with random numbers from 1 to 100, read number and print if it's found or not (reuse code in prev problem).
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

void FillArrayWithRandomNumbers(int Array[], int ArrayLength)
{

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

int FindNumberIndexInArray(int Array[], int ArrayLength, int NumberToCheck)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] == NumberToCheck)
			return i;
	}

	return -1;
}

bool IsNumberInArray(int Array[], int ArrayLength, int NumberToCheck)
{
	return FindNumberIndexInArray(Array, ArrayLength, NumberToCheck) != -1;
}

void PrintSearchResult(int Array[], int ArrayLength, int NumberToCheck)
{
	cout << "\nNumber you are looking for is : " << NumberToCheck << endl;

	if (IsNumberInArray(Array, ArrayLength, NumberToCheck))
		cout << "Yes, The number is found :) " << endl;
	else
		cout << "No, The number is not found :( " << endl;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArrayLength = ReadNumberBetween("Please enter number of elements : ", 1, 100);

	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array, ArrayLength);

	int NumberToCheck = ReadNumberBetween("\nPlease enter a number to search for : ", 1, 100);

	PrintSearchResult(Array, ArrayLength, NumberToCheck);

}
