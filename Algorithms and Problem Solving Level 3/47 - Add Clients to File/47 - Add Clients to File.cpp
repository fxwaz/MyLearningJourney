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

const string ClientsFileName = "Clients.txt";


stClientData ReadNewClient()
{
	stClientData ClientData;

	cout << "Enter Account Number : ";
	getline(cin >> ws, ClientData.AccountNumber);

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

void AddDataLineToFile(string FileName, string ClientData)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out | ios::app);

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
	AddDataLineToFile(ClientsFileName, RecordToLine);
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

	} while (toupper(Continue) == 'Y');

}


int main()
{
	AddClients();
}