// Write a program to find client by AccountNumber and print it to the screen.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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


string ReadString()
{
	string UserString;

	cout << "Please Enter Account Number : ";
	getline(cin, UserString);

	return UserString;
}

vector <string> SplitStringToVector(string Text, string Delimiter)
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

stClientData ConvertLineToRecord(string Text, string deli)
{
	stClientData stClient;
	vector <string> vClientData = SplitStringToVector(Text, deli);

	stClient.AccountNumber = vClientData[0];
	stClient.PinCode = vClientData[1];
	stClient.Name = vClientData[2];
	stClient.Phone = vClientData[3];
	stClient.AccountBalance = stod(vClientData[4]);

	return stClient;
}

vector <stClientData> LoadClientsDataFromFile(string FileName)
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
			Client = ConvertLineToRecord(Line, "#//#");
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;

}

void PrintClientData(stClientData &stClient)
{
		cout << "Account Number   :" << stClient.AccountNumber << endl;
		cout << "Pin Code         :" << stClient.PinCode << endl;
		cout << "Name             :" << stClient.Name << endl;
		cout << "Phone            :" << stClient.Phone << endl;
		cout << "Account Balance  :" << stClient.AccountBalance << endl;
}

bool FindAccountNumberInData(string &AccountNumber, stClientData& Data)
{
	vector <stClientData> vClient = LoadClientsDataFromFile(DataFileName);

	for (stClientData &stClient : vClient)
	{
		if (stClient.AccountNumber == AccountNumber)
		{
			Data = stClient;
			return true;
		}
	}

	return false;
}


int main()
{
	string AccountNumber = ReadString();
	stClientData ClientData;


	if (FindAccountNumberInData(AccountNumber, ClientData))
	{
		cout << endl;
		PrintClientData(ClientData);
	}
	else
	{
		cout << "\nAccount Number (" << AccountNumber << ") is not found!" << endl;
	}


}