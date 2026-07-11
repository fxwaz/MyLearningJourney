// Write a program to print abs of numbers, don't use built in abs function.
#include <iostream>
#include <cmath>
using namespace std;


float ReadUserNumber(string Message)
{
	float UserNumber;

	cout << Message;
	cin >> UserNumber;

	return UserNumber;
}

float myabs(float UserNumber)
{
	if (UserNumber < 0)
		return -UserNumber;
	else
		return UserNumber;
}


int main()
{
	float UserNumber = ReadUserNumber("Please enter your number : ");

	
	cout << "\nMy abs result : " << myabs(UserNumber) << endl;
	cout << "C++ abs Result : " << abs(UserNumber) << endl;
}

