// Write a program to print numbers from user number to 1.
#include <iostream>
using namespace std;


int ReadNumber()
{
	int UserNumber;

	cout << "Please enter a number : ";
	cin >> UserNumber;

	return UserNumber;
}

void PrintNumbersFromNto1_UsingForLoop(int UserNumber)
{
	for (int i = UserNumber; i > 0; i--)
	{
		cout << i << endl;
	}
}

void PrintNumbersFromNto1_UsingWhileLoop(int UserNumber)
{
	int i = UserNumber;

	while (i > 0)
	{
		cout << i << endl;
		i--;
	}
}

void PrintNumbersFromNto1_UsingDoWhileLoop(int UserNumber)
{
	int i = UserNumber;

	do
	{
		cout << i << endl;
		i--;
	} while (i > 0);
}

int main()
{
	PrintNumbersFromNto1_UsingForLoop(ReadNumber());
	PrintNumbersFromNto1_UsingWhileLoop(ReadNumber());
	PrintNumbersFromNto1_UsingDoWhileLoop(ReadNumber());
}