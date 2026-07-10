// Write a program to fill array with numbers, then check if it is palindrome array or not, Note: Palindrome array can be read the same from right to left and from left to right.
#include <iostream>
#include <string>
using namespace std;


void FillArrayWithNumbers(int Array[])
{

	Array[0] = 10;
	Array[1] = 20;
	Array[2] = 30;
	Array[3] = 30;
	Array[4] = 20;
	Array[5] = 10;

}

void PrintArray(int Array[], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		cout << Array[i] << " ";

	}

	cout << endl;

}

bool IsPalindromeArray(int Array[], int ArrayLength)
{
	int LastIndex = ArrayLength - 1;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] != Array[LastIndex])
		{
			return false;
		}

		LastIndex--;

	}

	return true;
	
}

void PrintResult(int Array[], int ArrayLength)
{
	if (IsPalindromeArray(Array, ArrayLength))
		cout << "\nYes, It's a Palindrome Array\n";
	else
		cout << "\nNo, It's not a Palindrome Array\n";
}


int main()
{
	int Array[10];
	int ArrayLength = 6;

	FillArrayWithNumbers(Array);

	cout << "\nArray elements : \n";
	PrintArray(Array, ArrayLength);


	cout << "\nIs the array Palindrome? : \n";
	PrintResult(Array, ArrayLength);

}