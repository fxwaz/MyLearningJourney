// Write a program to dynamically read numbers and save them in array max size of array is 100, allocate simi-dynamic array length.
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

void AddArrayElements(int Number, int Array[], int &arrLength)
{
	arrLength++;
	Array[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int Array[], int& arrLength)
{
	bool AddMore = true;

	do
	{
		
		AddArrayElements(ReadPositiveNumber("Please enter a number : "), Array, arrLength);

		if (arrLength == 100)
		{
			cout << "\n Array is full.\n";
			break;
		}
			
		cout << "\nDo you want to add more numbers ? [1] Yes | [0] No" << endl;
		cin >> AddMore;


	} while (AddMore);
}

void PrintArray(int Array[], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
	{

		cout << Array[i] << " ";

	}

	cout << endl;

}


int main()
{
	int Array[100];
	int arrLength = 0;

	InputUserNumbersInArray(Array, arrLength);
	cout << "Array Length : " << arrLength;

	cout << "\nArray elements : ";
	PrintArray(Array, arrLength);

}



