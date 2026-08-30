// Write a program to read a string then print the first letter of each word in that string.
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

void PrintFirstLetterOfEachWord(string Type)
{
	cout << "\nFirst Letters of this string : \n";

	bool IsFirstLetter = true;

	for (int i = 0; i < Type.length() ; i++)
	{
		if (Type[i] != ' ' && IsFirstLetter)
		{
			
			cout << Type[i] << endl;
			
		}

		IsFirstLetter = (Type[i] == ' ') ? true : false;
	}
}


int main()
{
	PrintFirstLetterOfEachWord(ReadString());
}