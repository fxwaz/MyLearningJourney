#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



void SaveVectorToFile(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (string &i : vFileContent)
		{

			MyFile << i << endl;

		}

		MyFile.close();
	}
}


int main()
{
	vector <string> vFileContent = { "Fawaz", "Saeed", "Abdullah", "Alzahrani" };

	SaveVectorToFile("Text.txt", vFileContent);

}