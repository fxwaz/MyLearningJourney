// Write a program to fill array with max size 100 with random numbers from 1 to 100, copy it to another array in reverse order and print it.
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
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

void FillArrayWithRandomNumbers(int Array[], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void CopyArrayInReverseOrder(int Array[], int NewArray[], int ArrayLength)
{
	int LastIndex = ArrayLength - 1;

	for (int i = 0; i < ArrayLength; i++)
	{
		NewArray[i] = Array[LastIndex];
		LastIndex--;
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

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int Array2[100];
	int ArrayLength = ReadNumberBetween("Please enter number of elements : ", 1, 100);


	FillArrayWithRandomNumbers(Array, ArrayLength);
	cout << "\nArray 1 elements : \n";
	PrintArray(Array, ArrayLength);


	CopyArrayInReverseOrder(Array, Array2, ArrayLength);
	cout << "\nArray 2 elements after copying array 1 in reversed order : \n";
	PrintArray(Array2, ArrayLength);

}