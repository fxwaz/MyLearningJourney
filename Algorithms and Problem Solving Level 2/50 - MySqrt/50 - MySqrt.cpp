// Write a program to print sqrt of numbers , don't use built in function.
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

float mysqrt(float Usernumber)
{
	return pow(Usernumber, 0.5);
}


int main()
{
	float Usernumber = ReadUserNumber("Please enter a number : ");

	cout << "\nMy sqrt function : " << endl;
	cout << mysqrt(Usernumber) << endl;

	cout << "C++ sqrt function : " << endl;
	cout << sqrt(Usernumber) << endl;

}