// Write a program to calculate factorial on N.
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

int FactorialOfN(int UserNumber)
{

	int FactorialBox = 1;

	for (int i = UserNumber; i >= 1; i--)
	{
		FactorialBox = FactorialBox * i;
	}

	return FactorialBox;
}

void PrintResult(int Result)
{
	cout << "The Result is : " << Result << endl;
}

int main()
{

	PrintResult(FactorialOfN(ReadPositiveNumber("Please enter a positive number: ")));


}