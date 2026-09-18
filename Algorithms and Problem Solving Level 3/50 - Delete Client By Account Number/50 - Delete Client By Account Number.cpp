// Write a program to delete client by AccountNumber.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


const string DataFileName = "Clients.txt";

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};


string ReadAccountNumber()
{
	string UserString;

	cout << "Please Enter Account Number : ";
	getline(cin, UserString);

	return UserString;
}

vector <string> SplitString(string Text, string Delimiter)
{
	vector <string> vString;
	string StringWord;
	int DelimiterPosition = 0;


	while ((DelimiterPosition = Text.find(Delimiter)) != string::npos)
	{
		StringWord = Text.substr(0, DelimiterPosition);

		if (StringWord != "")
		{
			vString.push_back(StringWord);
		}

		Text.erase(0, DelimiterPosition + Delimiter.length());
	}

	if (Text != "")
	{
		vString.push_back(Text);
	}


	return vString;
}

string ConvertClientToLine(stClientData cData, string deli = "#//#")
{
	return cData.AccountNumber + deli + cData.PinCode + deli + cData.Name + deli + cData.Phone + deli + to_string(cData.AccountBalance);
}

stClientData ConvertLineToClient(string Text, string deli)
{
	stClientData stClient;
	vector <string> vClientData = SplitString(Text, deli);

	stClient.AccountNumber = vClientData[0];
	stClient.PinCode = vClientData[1];
	stClient.Name = vClientData[2];
	stClient.Phone = vClientData[3];
	stClient.AccountBalance = stod(vClientData[4]);

	return stClient;
}

vector <stClientData> LoadClientsFromFile(string FileName)
{
	fstream MyFile;
	vector <stClientData> vClients;


	MyFile.open(FileName, ios::in);


	if (MyFile.is_open())
	{
		string Line;
		stClientData Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToClient(Line, "#//#");
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;

}

void PrintClient(stClientData &stClient)
{
	cout << "Account Number   :" << stClient.AccountNumber << endl;
	cout << "Pin Code         :" << stClient.PinCode << endl;
	cout << "Name             :" << stClient.Name << endl;
	cout << "Phone            :" << stClient.Phone << endl;
	cout << "Account Balance  :" << stClient.AccountBalance << endl;
}

bool FindClientByAccountNumber(string &AccountNumber, stClientData &Data)
{
	vector <stClientData> vClient = LoadClientsFromFile(DataFileName);

	for (stClientData& stClient : vClient)
	{
		if (stClient.AccountNumber == AccountNumber)
		{
			Data = stClient;
			return true;
		}
	}

	return false;
}

void AppendClientToFile(string FileName, stClientData &vData)
{
	fstream myfile;

	myfile.open(FileName, ios::app);

	if (myfile.is_open())
	{
		string Line;


		Line = ConvertClientToLine(vData);
		myfile << Line << endl;


		myfile.close();
	}
}

void DeleteClientFromFile(string &AccountNumber)
{
	vector <stClientData> vClient = LoadClientsFromFile(DataFileName);
	fstream myfile;


	myfile.open(DataFileName, ios::out);
	myfile.close();


	for (stClientData& C : vClient)
	{
		if (C.AccountNumber != AccountNumber)
		{
			AppendClientToFile(DataFileName, C);
		}
	}
}

void DeleteClientByAccountNumber(string &AccountNumber)
{
	stClientData ClientData;
	char Continue;

	if (FindClientByAccountNumber(AccountNumber, ClientData))
	{
		cout << endl;
		PrintClient(ClientData);
		cout << "\n\nSure u want delete this account number ? Y/N ";
		cin >> Continue;

		if (Continue == 'Y' || Continue == 'y')
		{
			DeleteClientFromFile(AccountNumber);
			cout << "\n\nAccount number has been deleted successfully.\n";
		}
			
	}
	else
	{
		cout << "\nAccount Number (" << AccountNumber << ") is not found!" << endl;
	}
}


int main()
{
	string AccountNumber = ReadAccountNumber();
	
	DeleteClientByAccountNumber(AccountNumber);

}