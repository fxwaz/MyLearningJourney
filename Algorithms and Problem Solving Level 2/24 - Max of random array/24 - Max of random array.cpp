// Write a program to fill an array (max size 100) with random numbers from 1 to 100, then print the maximum number.
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

int FindMaxNumberInArray(int Array[], int ArrayLength)
{
	int MaxNumber = Array[0];

	for (int i = 0; i < ArrayLength; i++)
	{

		if (Array[i] > MaxNumber)
			MaxNumber = Array[i];

	
	}

	return MaxNumber;

}


int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArrayLength;

	FillArrayWithRandomNumbers(Array, ArrayLength);

	cout << "\nArray Elements : ";
	PrintArray(Array, ArrayLength);

	cout << "Max Number is : " << FindMaxNumberInArray(Array, ArrayLength) << endl;

}