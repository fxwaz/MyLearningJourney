#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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



int main()
{
	vector <string> vFileContent;

	LoadDataFromFileToVector("Test.txt", vFileContent);

	for (string& Line : vFileContent)
	{
		cout << Line << endl;
	}
}