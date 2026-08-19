#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void LoadDataFromFileToVector(string FileName, vector <string> &vFileContent)
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

void SaveVectorToFile(string FileName, vector <string> &vFileContent)
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

void DeleteRecordFromFile(string FileName, string Search)
{
	vector <string> vFileContent;

	LoadDataFromFileToVector(FileName, vFileContent);

	for (string &Line : vFileContent)
	{
		if (Line == Search)
		{
			Line = "";
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
	cout << "File Content Before Delete :" << endl;
	PrintFileContent("Text.txt");


	DeleteRecordFromFile("Text.txt", "Alzahrani");


	cout << "\nFile Content After Delete :" << endl;
	PrintFileContent("Text.txt");
}