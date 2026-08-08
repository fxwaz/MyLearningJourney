// Write a program to ask user to enter as many numbers as wants, each time a number tnered add it to your vector, and ask the user if he wants to add more numbers until he says No, then print all vector elements on the screen.
#include <iostream>
#include <vector>
using namespace std;



int ReadNumberFromUser()
{

	int UserNumber = 0;
	
	cout << "Please enter a number : ";
	cin >> UserNumber;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');

		cout << "\nYou have to enter only numbers! \n";
		cout << "Please enter a number : ";
		cin >> UserNumber;
	}

	return UserNumber;

}

void AddElemntToVector(vector <int> &vNumbers, int UserNumber)
{
	vNumbers.push_back(UserNumber);
}

void AddElementsToVector(vector <int> &vNumbers)
{
	char Continue = 'Y';

	do
	{
		AddElemntToVector(vNumbers, ReadNumberFromUser());
		cout << "\nDo u want to add more numbers? [Y] Yes, [N] No : ";
		cin >> Continue;

	} while (Continue != 'N' && Continue != 'n');
}

void PrintVector(vector <int> &vNumbers)
{
	cout << "\nYour Numbers in Vector is : " << endl;

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}
}



int main()
{
	vector <int> vNumbers;

	AddElementsToVector(vNumbers);
	PrintVector(vNumbers);
}


//vector <int> vNumbers;


//vNumbers.push_back(10);
//vNumbers.push_back(20);
//vNumbers.push_back(30);
//vNumbers.push_back(40);

//cout << "Numbers Vector : " << endl;

//for (int& Number : vNumbers)
//{
//	cout << Number << endl;
//}
