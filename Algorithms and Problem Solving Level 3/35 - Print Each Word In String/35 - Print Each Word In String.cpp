// Write a program to read a string then print each word in that string.
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

void PrintEachWordInString(string Text)
{
	string Space = " ";
	string StringWord;
	int SpacePosition = 0;

	//Fawaz  Alzahrani
	while ((SpacePosition = Text.find(Space)) != string::npos)
	{
		StringWord = Text.substr(0, SpacePosition);

		if (StringWord != "")
		{
			cout << StringWord << endl;
		}

		Text.erase(0, SpacePosition + Space.length());
	}

	if (Text != "")
	{
		cout << Text << endl;
	}
}



int main()
{
	string Stringg = ReadString();

	PrintEachWordInString(Stringg);
}