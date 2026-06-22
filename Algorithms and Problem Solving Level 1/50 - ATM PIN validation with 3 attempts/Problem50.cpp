// Write a program to allow only 3 ATM PIN attempts, display the account balance if the PIN is correct, otherwise lock the card.
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
	int times = 0;

	do
	{
		times++; 

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

		

	} while (PINcode != "1234" && times < 3);

	return false;

}

void PrintResult()
{

	if (Login())
	{
		system("color 2F");
		cout << "Your balance is 7500" << endl;
	}
	else
	{
		cout << "\nYour Card is locked!!\n";
	}

}

int main()
{
	PrintResult();
}