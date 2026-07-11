// Write a program to fill array with max size 100 with random numbers from 1 to 100, then print the count of Even numbers.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int ReadNumberInRange(string message, int from, int to)
{
	int UserNumber;

	do
	{
		cout << message;
		cin >> UserNumber;

	} while (UserNumber < from || UserNumber > to);

	return UserNumber;
}

int RandomNumber(int From, int To)
{
	int RandomNumber;

	RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;
}

void FillArrayWithRandomNumbers(int Array[], int& ArrayLength)
{
	ArrayLength = ReadNumberInRange("Please enter array length from 1 to 100 : ", 1, 100);

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
}

int CountEvenNumbersInArray(int Array[], int ArrayLength)
{
	int HowManyEven = 0;

	for (int i = 0; i < ArrayLength; i++)
	{
		if (Array[i] % 2 == 0)
			HowManyEven = HowManyEven + 1;
	}

	return HowManyEven;
}


int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArrayLength;

	FillArrayWithRandomNumbers(Array, ArrayLength);


	cout << "\nArray Elements : ";
	PrintArray(Array, ArrayLength);


	cout << "\nEven Numbers count is : ";
	cout << CountEvenNumbersInArray(Array, ArrayLength) << endl;


}