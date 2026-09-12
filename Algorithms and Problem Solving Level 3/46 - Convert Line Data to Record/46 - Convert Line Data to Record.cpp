// Write a program to convert line data to record and print it.
#include <iostream>
#include <string>
#include <vector>
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

	cout << "Enter Account Balance : ";
	cin >> UserData.AccountBalance;

	return UserData;
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

string ConvertRecordToLine(stClientData cData, string deli = "#//#")
{
	return cData.AccountNumber + deli + cData.PinCode + deli + cData.Name + deli + cData.Phone + deli + to_string(cData.AccountBalance);
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

void PrintClientData(stClientData Client)
{
	cout << "\n\nThe following is the extracted client record :\n\n";
	cout << "Account number  : " << Client.AccountNumber << endl;
	cout << "Pin Code        : " << Client.PinCode << endl;
	cout << "Name            : " << Client.Name << endl;
	cout << "Phone           : " << Client.Phone << endl;
	cout << "Account Balance : " << Client.AccountBalance << endl;

	cout << endl;
}


int main()
{
	cout << "Please enter client data : \n\n";
	stClientData ClientData = ReadNewClient();


	cout << "\n\nClient Record for saving is : \n";
	string Line = ConvertRecordToLine(ClientData);
	cout << Line << endl;

	cout << endl;

	stClientData Client = ConvertLineToRecord(Line, "#//#");

	PrintClientData(Client);

}