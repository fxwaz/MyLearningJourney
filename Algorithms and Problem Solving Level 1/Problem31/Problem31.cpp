// Write a program to ask the user to enter a number then print the number^2, number^3, number^4
#include <iostream>
using namespace std;


int ReadNumber()
{
	int UserNumber;

	cout << "Please etner a number : ";
	cin >> UserNumber;

	return UserNumber;
}

void PowerOf(int usernumber, int power)
{
	int PowerBox = 1;

	for (int i = 1; i <= power; i++)
	{

		PowerBox = PowerBox * usernumber;
		
	}

	cout << usernumber << " Power of " << power << " is = " << PowerBox << endl;
}

int main()
{
	int UserNumber = ReadNumber();

	PowerOf(UserNumber, 2);
	PowerOf(UserNumber, 3);
	PowerOf(UserNumber, 4);

}