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

bool IsSameAccountNumber(string Text, string Find, string deli)
{
	int DeliPosition = Text.find(deli);
	string AccountNumber = Text.substr(0, DeliPosition);

	if (AccountNumber == Find)
		return true;
	else
		return false;
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

vector <stClientData> LoadClientDataFromFile(string FileName, string AccountNumber)
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
			if (IsSameAccountNumber(Line,AccountNumber, "#//#"))
			{
				Client = ConvertLineToRecord(Line, "#//#");
				vClients.push_back(Client);
			}

		}

		MyFile.close();
	}

	return vClients;

}

void PrintClientData(vector <stClientData> &stClient)
{
	for (stClientData& Client : stClient)
	{
		cout << "Account Number   :" << Client.AccountNumber << endl;
		cout << "Pin Code         :" << Client.PinCode << endl;
		cout << "Name             :" << Client.Name << endl;
		cout << "Phone            :" << Client.Phone << endl;
		cout << "Account Balance  :" << Client.AccountBalance << endl;
	}
}



int main()
{
	string AccountNumber = ReadString();

	vector <stClientData> vData = LoadClientDataFromFile(DataFileName, AccountNumber);

	if (vData.empty())
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
	}
	else
	{
		cout << "\nthe following are the client details : \n\n";
		PrintClientData(vData);
	}


}