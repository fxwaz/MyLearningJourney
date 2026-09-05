// Write a program to read a string then count each word in that string.
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

int CountEachWordInString(string Text)
{
	string Space = " ";
	string StringWord;
	int SpacePosition = 0;
	int Counter = 0;

	//Sb7an Allah
	while ((SpacePosition = Text.find(Space)) != string::npos)
	{
		StringWord = Text.substr(0, SpacePosition);

		if (StringWord != "")
		{
			Counter++;
		}

		Text.erase(0, SpacePosition + Space.length());

	}

	if (Text != "")
		Counter++;


	return Counter;
}



int main()
{
	string SS = ReadString();

	cout << "\nThe number of words in your string is : ";
	cout << CountEachWordInString(SS) << endl;
}
