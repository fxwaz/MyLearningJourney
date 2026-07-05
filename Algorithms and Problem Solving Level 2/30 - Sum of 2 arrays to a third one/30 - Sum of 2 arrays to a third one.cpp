// Write a program to fill two arrays with random numbers from 1 to 100, sum their elements in a third array, and print the results.
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

void SumTwoArrayElements(int FirstArray[], int SecondArray[], int ArrayLength, int ArraySum[])
{
	for (int i = 0; i < ArrayLength; i++)
	{
		ArraySum[i] = FirstArray[i] + SecondArray[i];
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int Array2[100];
	int ArraySum[100];
	int ArrayLength = ReadNumberBetween("Please enter number of elements: ", 1, 100);
	

	FillArrayWithRandomNumbers(Array, ArrayLength);
	FillArrayWithRandomNumbers(Array2, ArrayLength);
	SumTwoArrayElements(Array, Array2, ArrayLength, ArraySum);

	cout << "\nArray 1 Elements : \n";
	PrintArray(Array, ArrayLength);

	cout << "\nArray 2 Elements : \n";
	PrintArray(Array2, ArrayLength);

	cout << "\nSum of Array 1 and Array 2 Elements : \n";
	PrintArray(ArraySum, ArrayLength);

}