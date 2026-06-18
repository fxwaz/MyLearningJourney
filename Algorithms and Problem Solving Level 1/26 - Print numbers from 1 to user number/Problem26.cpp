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

void PrintNumbersFrom1ToN_UsingForLoop(int UserNumber)
{

	for (int i = 1; i <= UserNumber; i++)
	{
		cout << i << endl;
	}

}

void PrintNumbersFrom1ToN_UsingWhileLoop(int UserNumber)
{

	int i = 1;

	while (i <= UserNumber)
	{
		cout << i << endl;
		i++;
	}
		
}

void PrintNumbersFrom1ToN_UsingDoWhileLoop(int UserNumber)
{

	int i = 1;

	do
	{

		cout << i << endl;
		i++;

	} while (i <= UserNumber);

}

int main()
{
	PrintNumbersFrom1ToN_UsingForLoop(ReadNumber());
	PrintNumbersFrom1ToN_UsingWhileLoop(ReadNumber());
	PrintNumbersFrom1ToN_UsingDoWhileLoop(ReadNumber());
}