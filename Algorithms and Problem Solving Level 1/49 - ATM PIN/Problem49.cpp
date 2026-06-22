// Write a program to ask the user for an ATM PIN code, keep asking until the correct PIN is entered, then display the account balance.
#include <iostream>
using namespace std;



string ReadPinCode()
{

	string PINcode;

	cout << "Please enter your ATM PIN : ";
	cin >> PINcode;

	return PINcode;

}


bool Login()
{
	string PINcode;

	do
	{
		PINcode = ReadPinCode();

		if (PINcode == "1234")
		{
			return true;
		}
		else
		{
			system("color 4F");
			cout << "Wrong number, try again!\n";
		}
		
	} while (PINcode != "1234");

}

void PrintResult()
{

	if (Login())
	{
		system("color 2F");
		cout << "Your balance is 7500" << endl;
	}

}

int main()
{
	PrintResult();
}