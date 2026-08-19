#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();
	}
}

void SaveVectorToFile(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{

		for (string& Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}

		}

		MyFile.close();
	}
}

void UpdateRecordInFile(string FileName, string OldWord, string NewWord)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == OldWord)
		{
			Line = NewWord;
		}
	}

	SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName)
{
	fstream Myfile;

	Myfile.open(FileName, ios::in);

	if (Myfile.is_open())
	{
		string Line;

		while (getline(Myfile, Line))
		{
			cout << Line << endl;
		}

		Myfile.close();
	}
}


int main()
{
	cout << "File Content Before Update :" << endl;
	PrintFileContent("Text.txt");


	UpdateRecordInFile("Text.txt", "Alzahrani", "AAALLZZZAAAHHRRAANNNII");


	cout << "\nFile Content After Update :" << endl;
	PrintFileContent("Text.txt");
}