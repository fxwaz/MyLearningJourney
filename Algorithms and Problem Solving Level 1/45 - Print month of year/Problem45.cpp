// Write a program that asks the user to enter a number from 1 to 12, then prints the corresponding month of the year.
#include <iostream>
using namespace std;

enum enMonths { January = 1, February , March , April, May, June, July, August, September, October, November, December };


int ReadNumberRange(int from, int to)
{
	int UserNumber;

	do
	{
		cout << "Please enter number from " << from << " to " << to << " : ";
		cin >> UserNumber;

		if (UserNumber < from || UserNumber > to)
		{
			cout << "Wrong number! try again\n";
		}

	} while (UserNumber < from || UserNumber > to);

	return UserNumber;
}


enMonths GetMonthNumber(int usernumber)
{
	return enMonths(usernumber);
}


string GetMonthName(enMonths usernumber)
{

	switch (usernumber)
	{
	case enMonths::January:
		return "It's January";
	case enMonths::February:
		return "It's February";
	case enMonths::March:
		return "It's March";
	case enMonths::April:
		return "It's April";
	case enMonths::May:
		return "It's May";
	case enMonths::June:
		return "It's June";
	case enMonths::July:
		return "It's July";
	case enMonths::August:
		return "It's August";
	case enMonths::September:
		return "It's September";
	case enMonths::October:
		return "It's October";
	case enMonths::November:
		return "It's November";
	case enMonths::December:
		return "It's December";
	default:	
		return "Wrong Month";
				
	}
}


void PrintResult(string result)
{
	cout << "\n" << result << endl;
}


int main()
{
	PrintResult(GetMonthName(GetMonthNumber(ReadNumberRange(1, 12))));
}