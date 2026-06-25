// Write a program to check if the number is perfect number or not 
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

bool IsPerfectNumber(int UserNumber)
{
	int SumBox = 0;

	for (int i = 1; i < UserNumber; i++)
	{
		if (UserNumber % i == 0)
			SumBox = SumBox + i;
	}

	return SumBox == UserNumber;
}

void PrintResult(int UserNumber)
{

	if (IsPerfectNumber(UserNumber))
		cout << "\n" << UserNumber << " is perfect" << endl;
	else
		cout << "\n" << UserNumber << " is not perfect" << endl;

}


int main()
{

	PrintResult(ReadPositiveNumber("Please enter a positive number : "));

}

