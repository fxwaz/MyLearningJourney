// Write a program to join vector/array of strings into one string with separators using function overloading
#include <iostream>
#include <string>
#include <vector>
using namespace std;



string JoinString(vector <string>& vString, string Delimiter)
{

	string NewString;

	for (string& String : vString)
	{
		NewString = NewString + String + Delimiter;
	}

	return NewString.substr(0, NewString.length() - Delimiter.length());
}

string JoinString(string arrString[], int ArrayLength, string Delimiter)
{

	string NewString;

	for (int i = 0; i < ArrayLength; i++)
	{
		NewString = NewString + arrString[i] + Delimiter;
	}

	return NewString.substr(0, NewString.length() - Delimiter.length());
}



int main()
{
	vector <string> String = { "Fawaz", "Saeed", "Alzahrani" };
	string arrString[3] = { "Fawaz", "Saeed", "Alzahrani" };

	
	cout << "Vector after join : \n";
	cout << JoinString(String, "-") << endl;

	cout << "\nArray after join : \n";
	cout << JoinString(arrString, 3, " ") << endl;
}