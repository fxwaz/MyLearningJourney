// Write a program to print numbers from 1 to user number.
#include <iostream>
using namespace std;


int ReadNumber()
{
	int UserNumber;

	cout << "Please enter a number : ";
	cin >> UserNumber;

	return UserNumber;
}

void PrintNumbersFrom1ToN(int UserNumber)
{
	for (int i = 1; i <= UserNumber; i++)
	{
		cout << i << endl;
	}
		
}

int main()
{
	PrintNumbersFrom1ToN(ReadNumber());
}