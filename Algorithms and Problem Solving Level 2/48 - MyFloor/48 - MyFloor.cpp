// Write a program to print floor of numbers , don't use built in floor function.
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

int myfloor(float Usernumber)
{
	float Fract = GetFract(Usernumber);

	if (Usernumber > 0)
		return int(Usernumber);

	if (Fract != 0) 
		return int(Usernumber) - 1;
	else
		return int(Usernumber);
}


int main()
{
	float Usernumber = ReadUserNumber("Please enter a number : ");

	cout << "\nMy floor function : " << endl;
	cout << myfloor(Usernumber) << endl;

	cout << "C++ floor function : " << endl;
	cout << floor(Usernumber) << endl;

}