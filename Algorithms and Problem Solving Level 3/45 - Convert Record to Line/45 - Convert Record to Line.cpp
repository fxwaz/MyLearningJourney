// Write a program to read bank client data record and covert it to one line.
#include <iostream>
#include <string>
using namespace std;


struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};


stClientData ReadNewClient()
{
	stClientData UserData;

	cout << "Enter Account Number : ";
	getline(cin, UserData.AccountNumber);

	cout << "Enter PinCode : ";
	getline(cin, UserData.PinCode);

	cout << "Enter Name : ";
	getline(cin, UserData.Name);

	cout << "Enter Phone : ";
	getline(cin, UserData.Phone);

	cout << "Enter AccountBlaance : ";
	cin >> UserData.AccountBalance;

	return UserData;
}

string ConvertRecordToLine(stClientData cData, string deli = "#//#")
{
    return cData.AccountNumber + deli + cData.PinCode + deli + cData.Name + deli + cData.Phone + deli + to_string(cData.AccountBalance);
}


int main()
{
	cout << "Please enter client data : \n\n";
	stClientData ClientData = ReadNewClient();

	cout << "\n\nClient Record for saving is : \n";
	cout << ConvertRecordToLine(ClientData) << endl;
}