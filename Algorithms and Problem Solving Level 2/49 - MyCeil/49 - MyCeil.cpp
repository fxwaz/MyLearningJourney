// Write a program to print ceil of numbers , don't use built in function.
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

float GetFract(float Usernumber)
{
	float Fract = Usernumber - int(Usernumber);

	return Fract;
}

int myceil(float Usernumber)
{
	float Fract = GetFract(Usernumber);

	if (Fract == 0)
		return int(Usernumber);

	if (Usernumber > 0)
		return int(Usernumber) + 1;
	else
		return int(Usernumber);

}


int main()
{
	float Usernumber = ReadUserNumber("Please enter a number : ");

	cout << "\nMy ceil function : " << endl;
	cout << myceil(Usernumber) << endl;

	cout << "C++ ceil function : " << endl;
	cout << ceil(Usernumber) << endl;

}