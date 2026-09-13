// Write a program to ask you to enter clients and save them to file.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
	stClientData ClientData;

	cout << "Enter Account Number : ";
	getline(cin, ClientData.AccountNumber);

	cout << "Enter PinCode : ";
	getline(cin, ClientData.PinCode);

	cout << "Enter Name : ";
	getline(cin, ClientData.Name);

	cout << "Enter Phone : ";
	getline(cin, ClientData.Phone);

	cout << "Enter Account Balance : ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

string ConvertRecordToLine(stClientData cData, string deli = "#//#")
{
	return cData.AccountNumber + deli + cData.PinCode + deli + cData.Name + deli + cData.Phone + deli + to_string(cData.AccountBalance);
}

void AddDataLineToFile(string ClientData)
{
	fstream MyFile;

	MyFile.open("Client.txt", ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << ClientData << endl;


		MyFile.close();
	}
}

void AddNewClient()
{
	stClientData Client = ReadNewClient();
	string RecordToLine = ConvertRecordToLine(Client);
	AddDataLineToFile(RecordToLine);
}

void AddClients()
{
	char Continue = 'Y';

	do
	{
		system("cls");

		cout << "Adding new client : \n\n";

		AddNewClient();

		cout << "\n\nClient Added Successfully, do u want to add more clients? Y/N : ";
		cin >> Continue;
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	} while (toupper(Continue) == 'Y');

}


int main()
{
	AddClients();
}