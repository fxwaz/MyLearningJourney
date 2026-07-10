// Write a program to fill array with numbers, then print distinct numbers to another array.
#include <iostream>
using namespace std;


void FillArrayWithNumbers(int Array[])
{

	Array[0] = 10;
	Array[1] = 10;
	Array[2] = 10;
	Array[3] = 50;
	Array[4] = 50;
	Array[5] = 70;
	Array[6] = 70;
	Array[7] = 70;
	Array[8] = 70;
	Array[9] = 90;

}

void PrintArray(int Array[], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		cout << Array[i] << " ";

	}

	cout << endl;

}

void AddArrayElement(int Number, int DestinationArray[], int& NewArrayLength)
{
	DestinationArray[NewArrayLength] = Number;
	NewArrayLength++;
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

void CopyDistinctNumbers(int SourceArray[], int DestinationArray[], int ArrayLength, int& NewArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		if (!IsNumberInArray(DestinationArray, NewArrayLength, SourceArray[i]))
		{
			AddArrayElement(SourceArray[i], DestinationArray, NewArrayLength);
		}

	}
}


int main()
{
	int Array[10];
	int NewArray[10];
	int arrLength = 10;
	int NewArrayLength = 0;

	FillArrayWithNumbers(Array);

	cout << "\nArray 1 elements : \n";
	PrintArray(Array, arrLength);

	CopyDistinctNumbers(Array, NewArray, arrLength, NewArrayLength);
	

	cout << "\nArray 2 distinct elements : \n";
	PrintArray(NewArray, NewArrayLength);

}