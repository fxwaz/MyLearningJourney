// Write a program that asks the user to enter a number from 1 to 7, then prints the corresponding day of the week.
#include <iostream>
using namespace std;


enum enDays {Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};


int ReadNumberRange(int from, int to)
{
	int UserNumber;

	do
	{
		cout << "Please enter a number from " << from << " to " << to << " : ";
		cin >> UserNumber;

		if (UserNumber < from || UserNumber > to)
		{
			cout << "\nInvalid number! try again bro.\n";
		}

	} while (UserNumber < from || UserNumber > to);

	return UserNumber;
}


enDays GetDayNumber(int usernumber)
{
	return enDays(usernumber);
}


string GetDayName(enDays usernumber)
{

	switch (usernumber)
	{
	case enDays::Sunday: 
		return "It's Sunday";

	case enDays::Monday:
		return "It's Monday";

	case enDays::Tuesday:
		return "It's Tuesday";

	case enDays::Wednesday:
		return "It's Wednesday";

	case enDays::Thursday:
		return "It's Thursday";

	case enDays::Friday:
		return "It's Friday";

	case enDays::Saturday:
		return "It's Saturday";

	default:
		return "Invalid number";
	}
}

void PrintResult(string result)
{
	cout << "\n" << result << endl;
}

int main()
{
	PrintResult(GetDayName(GetDayNumber(ReadNumberRange(1, 7))));
}
