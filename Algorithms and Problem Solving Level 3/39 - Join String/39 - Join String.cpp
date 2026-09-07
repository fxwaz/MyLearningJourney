// Write a program to join vector of strings into a one string with separators
#include <iostream>
#include <string>
#include <vector>
using namespace std;



string JoinString(vector <string> &vString, string Delimiter)
{

	string NewString;

	for (string &String : vString)
	{
		NewString = NewString + String + Delimiter;
	}

	return NewString.substr(0, NewString.length() - Delimiter.length());
}



int main()
{
	vector <string> String = { "Fawaz", "Saeed", "Alzahrani" };
	string Result;

	cout << "Vector after join : \n";
	Result = JoinString(String, "-");
	cout << Result << endl;
}