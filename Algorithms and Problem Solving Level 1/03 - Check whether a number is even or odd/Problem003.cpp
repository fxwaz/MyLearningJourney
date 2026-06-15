// Write a program that asks the user to enter a number if it is odd or an even number if it is even
#include <iostream>
using namespace std;


enum enNumberType { Even = 1, Odd};



int AskUserToEnterNumber()
{
	int UserNumber;

	cout << "Please enter a number : ";
	cin >> UserNumber;

	return UserNumber;
}


enNumberType CheckNumberType(int UserNumber)
{
	int Result = UserNumber % 2;
	if (Result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::Odd;
	}
}


void PrintNumberType(enNumberType NumberType)
{

	if (NumberType == enNumberType::Even)
	{
		cout << "\n\n Your number is Even buddy! \n\n";
	}
	else
	{
		cout << "\n\n Your number is Odd buddy! \n\n";
	}


}





int main()
{

	PrintNumberType(CheckNumberType(AskUserToEnterNumber()));

}
