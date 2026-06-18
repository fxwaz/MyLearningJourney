// Write a program to sum even numbers from 1 to user number.
#include <iostream>
using namespace std;


enum enOddOrEven { Odd = 1, Even = 2 };


int ReadNumber()
{

	int UserNumber;

	cout << "Please enter your number : ";
	cin >> UserNumber;

	return UserNumber;

}


enOddOrEven CheckIfOddOrEven(int Number)
{
	if (Number % 2 != 0)
		return enOddOrEven::Odd;
	else
		return enOddOrEven::Even;
}

int SumEvenNumbersFrom1ToN(int UserNumber)
{
	int SumBox = 0;

	for (int i = 1; i <= UserNumber; i++)
	{
		if (CheckIfOddOrEven(i) == enOddOrEven::Even)
		{
			SumBox = SumBox + i;
		}
	}

	return SumBox;

}

void PrintResult(int Result)
{

	cout << "The sum of even numbers from 1 to your number is : " << Result << endl;

}


int main()
{
	PrintResult(SumEvenNumbersFrom1ToN(ReadNumber()));
}