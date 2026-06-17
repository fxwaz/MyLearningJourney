// Write a program to ask the user to enter Age, if age is between 18 and 45 print "Valid age" otherwise print "Invalid age" and reask user to enter a valid age
#include <iostream>
using namespace std;


int ReadUserAge()
{

	int UserAge;

	cout << "Please enter your age : ";
	cin >> UserAge;

	return UserAge;

}

bool IsAgeInRange(int UserAge, int from, int to)
{

	return ( UserAge >= from && UserAge <= to );

}

int ReadUntilAgeBetween(int from, int to)
{
	int UserAge = 0;

	do
	{

		UserAge = ReadUserAge();

	} while (!IsAgeInRange(UserAge, from, to));

	return UserAge;
}

void PrintResult(int userage)
{
	if (IsAgeInRange(userage, 18, 45))
		cout << "\n Valid number \n";
	else
		cout << "\n Invalid number \n";
}

int main()
{
	PrintResult(ReadUntilAgeBetween(18, 45));
}