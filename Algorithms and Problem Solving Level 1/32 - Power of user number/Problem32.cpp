// Write a program that asks the user to enter two numbers. The second number will be the power of the first number.
#include <iostream>
using namespace std;



int ReadNumber()
{
	int UserNumber;

	cout << "Please enter your number : ";
	cin >> UserNumber;

	return UserNumber;
}


int ReadPower()
{
	int UserPower;

	cout << "Please enter your power number : ";
	cin >> UserPower;

	return UserPower;
}


int PowerOf(int UserNumber, int PowerNumber)
{
	int PowerBox = 1;

	for (int i = 1; i <= PowerNumber; i++)
	{
		PowerBox = PowerBox * UserNumber;
	}

	return PowerBox;
}

void PrintResult(int result)
{
	cout << "The result is : " << result << endl;
}


int main()
{
	PrintResult(PowerOf(ReadNumber(), ReadPower()));
}