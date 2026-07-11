// Write a program to print round of numbers , don't use built in round function.
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

int myround(float Usernumber)
{
	float Fract = GetFract(Usernumber);

	if (Usernumber > 0)
	{
		if (Fract >= 0.5)
			return int(Usernumber) + 1;
		else
			return int(Usernumber);
	}
	else
	{
		if (-Fract >= 0.5)
			return int(Usernumber) - 1;
		else
			return int(Usernumber);
	}
}


int main()
{
	float Usernumber = ReadUserNumber("Please enter a number : ");

	cout << "\nMy round function : " << endl;
	cout << myround(Usernumber) << endl;

	cout << "C++ round function : " << endl;
	cout << round(Usernumber) << endl;

}