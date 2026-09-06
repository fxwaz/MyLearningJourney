// Write a program to read a string then Trim Left, Right, All
#include <iostream>
#include <string>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
}

string TrimLeft(string Text)
{

	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(i, Text.length() - i);
		}
	}

	return "";

}

string TrimRight(string Text)
{
	for (int i = Text.length() - 1; i >= 0; i--)
	{
		if (Text[i] != ' ')
		{
			return Text.substr(0, i + 1);
		}
	}

	return "";

}

string Trim(string Text)
{
	return (TrimLeft(TrimRight(Text)));
}



int main()
{
	string String = "     Fawaz Alzahrani    ";

	cout << "String : " << String << endl;
	cout << "Trim : " << Trim(String) << endl;
	cout << "Trim Left : " << TrimLeft(String) << endl;
	cout << "Trim Right : " << TrimRight(String) << endl;

}