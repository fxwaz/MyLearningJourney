// Write a program to ask the user to enter pennies, nickels, dimes, quarters, and dollars, then calculate and print the total pennies and total dollars.
#include <iostream>
using namespace std;

struct stPiggyBank
{
	int Pennies, Nickels, Dimes, Quarters, Dollars;
};


stPiggyBank ReadNumbers()
{
	stPiggyBank PiggyCoins;

	cout << "Enter your Penny : ";
	cin >> PiggyCoins.Pennies;

	cout << "Enter your Nickel : ";
	cin >> PiggyCoins.Nickels;

	cout << "Enter your Dime : ";
	cin >> PiggyCoins.Dimes;

	cout << "Enter your Quarter : ";
	cin >> PiggyCoins.Quarters;

	cout << "Enter your Dollar : ";
	cin >> PiggyCoins.Dollars;

	return PiggyCoins;
}

int CalculateTotalPennies(stPiggyBank PiggyCoins)
{

	return 1 * PiggyCoins.Pennies + 5 * PiggyCoins.Nickels + 10 * PiggyCoins.Dimes + 25 * PiggyCoins.Quarters + 100 * PiggyCoins.Dollars;

}

void PrintResult(int TotalPennies)
{
	cout << "\nYour Pennies is : " << TotalPennies << endl;
	cout << "Your Dollars is : " << float(TotalPennies) / 100 << endl;
}


int main()
{

	PrintResult(CalculateTotalPennies(ReadNumbers()));

}