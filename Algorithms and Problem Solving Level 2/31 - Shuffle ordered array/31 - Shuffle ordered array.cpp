// Write a program to fill array with ordered numbers from 1 to N, then print it, after that shuffle this array and print it after shuffle.
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

void Swap(int& a, int& b)
{
	int SwapBox;

	SwapBox = a; 
	a = b;
	b = SwapBox;
}

void FillArrayFrom1toN(int Array[], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = i + 1;
	}
}

void ShuffleArray(int Array[], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		Swap(Array[RandomNumber(1, ArrayLength) - 1], Array[RandomNumber(1, ArrayLength) - 1]);
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

	FillArrayFrom1toN(Array, ArrayLength);

	cout << "\nArray elements before shuffle : \n";
	PrintArray(Array, ArrayLength);

	ShuffleArray(Array, ArrayLength);

	cout << "\nArray elements after shuffle : \n";
	PrintArray(Array, ArrayLength);

}