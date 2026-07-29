#include <iostream>
using namespace std;


int ReadNumber()
{
	int UserNumber;

	cout << "Please enter a number : ";
	cin >> UserNumber;

	// if the user enters a value that cannot be converted to an int the cin state will be cin.fail() == true
	
	while (cin.fail())
	{

		cin.clear();             // Clear the cin.fail() state so cin can be used again
		cin.ignore(10000, '\n'); // Remove all remaining characters from the input buffer until '\n' is reached or 10000 characters are removed
		cout << "You have to enter only numbers!" << endl;
		cout << "Please enter a number : ";

		cin >> UserNumber;

	}

	return UserNumber;

}

int main()
{
	int userNumber = ReadNumber();
	cout << "Your number is : " << userNumber;
}



