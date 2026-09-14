// Write a program to read clients file and show them on the screen.
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

vector <stClientData> TakeLineFromFileToDataVector(string FileName)
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

void PrintClientData(vector <stClientData> &DataInfo)
{

	for (stClientData &sData : DataInfo)
	{
		cout << "| " << left << setw(20) << sData.AccountNumber;
		cout << "| " << left << setw(20) << sData.PinCode;
		cout << "| " << left << setw(30) << sData.Name;
		cout << "| " << left << setw(20) << sData.Phone;
		cout << "| " << left << setw(20) << sData.AccountBalance;
		cout << endl;
	}

}

void PrintClientsData(vector <stClientData> &DataInfo)
{
	cout << "\t\t\t\t\t\t\tClient List(" << DataInfo.size() << ") Clients(s)." << endl;

	cout << string(150, '-') << endl;


	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(20) << "Pin Code";
	cout << "| " << left << setw(30) << "Client Name";
	cout << "| " << left << setw(20) << "Phone";
	cout << "| " << left << setw(20) << "Balance" << endl;


	cout << string(150, '-') << endl;
	cout << endl;


	PrintClientData(DataInfo);


	cout << endl;
	cout << string(150, '-') << endl;
}



int main()
{

	vector <stClientData> vData = TakeLineFromFileToDataVector(DataFileName);
	PrintClientsData(vData);

}