// Write a program to read a string then uppercase the first letter of each word in that string.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
}

string UpperCaseFirstLetterOfEachWord(string Type)
{
	bool IsFirstLetter = true;

	for (int i = 0; i < Type.length(); i++)
	{
		if (Type[i] != ' ' && IsFirstLetter)
		{
			Type[i] = toupper(Type[i]);
		}

		IsFirstLetter = (Type[i] == ' ') ? true : false;
	}

	return Type;
}


int main()
{
	string UserType = ReadString();

	cout << "\nString after conversion : \n";
	UserType = UpperCaseFirstLetterOfEachWord(UserType);

	cout << UserType << endl;

}