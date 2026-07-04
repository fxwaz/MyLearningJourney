// Write a program to read N elements into an array, ask for a number to check, print the array, then print how many times the number appears in the array.
#include <iostream>
using namespace std;

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

void ReadArray(int Array[], int& ArrayLength)
{
	cout << "Please enter number of elements : ";
	cin >> ArrayLength;

	cout << "\nPlease enter array elements : ";
	cout << endl;


	for (int i = 0; i < ArrayLength; i++)
	{
		cout << "Element [" << i + 1 << "]" << " : ";
		cin >> Array[i];
	}
}

void PrintArray(int Array[], int ArrayLength)
{
	cout << "\nOriginal array : ";

	for (int i = 0; i < ArrayLength; i++)
	{
	
		cout << Array[i] << " ";

	}

	cout << endl;
	
}

int TimesRepeated(int Array[], int ArrayLength, int NumberToCheck)
{
	int Count = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (NumberToCheck == Array[i])
			Count = Count + 1;
	}

	return Count;
}


int main()
{
	int Array[100];
	int ArrayLength;

	ReadArray(Array, ArrayLength);

	int NumberToCheck = ReadPositiveNumber("\nPlease enter the number you want to check : ");

	PrintArray(Array, ArrayLength);


	cout << "Number " << NumberToCheck << " is repeated " << TimesRepeated(Array, ArrayLength, NumberToCheck) << " times(s)" << endl;
	
}