// Write a program to replace words in string using custom function.
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


enum enMatchCase {Match = 1, NotMatch};


string ReadString(string Message)
{
	string UserString;

	cout << Message;
	getline(cin, UserString);

	return UserString;
}

string LowerAllString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}

	return Text;
}

vector <string> SplitStringToVector(string Text, string Delimiter)
{
	vector <string> vString;
	string StringWord;
	int DelimiterPosition = 0;


	while ((DelimiterPosition = Text.find(Delimiter)) != string::npos)
	{
		StringWord = Text.substr(0, DelimiterPosition);

		if (StringWord != "")
		{
			vString.push_back(StringWord);
		}

		Text.erase(0, DelimiterPosition + Delimiter.length());
	}

	if (Text != "")
	{
		vString.push_back(Text);
	}


	return vString;
}

string JoinString(vector <string>& vString, string Delimiter)
{

	string NewString;

	for (string& String : vString)
	{
		NewString = NewString + String + Delimiter;
	}

	return NewString.substr(0, NewString.length() - Delimiter.length());
}

string ReplaceWordInString(string Text, string Word, string NewWord, enMatchCase Case)
{
	vector <string> vString = SplitStringToVector(Text, " ");
	string LowerWord = LowerAllString(Word);

	for (string& sWord : vString)
	{
		if (Case == enMatchCase::Match)
		{
			if (sWord == Word)
			{
				sWord = NewWord;
			}
		}
		else
		{
			if (LowerAllString(sWord) == LowerWord)
			{
				sWord = NewWord;
			}
		}
	}

	return JoinString(vString, " ");

}



int main()
{
	string UserString = ReadString("Please enter your string : ");

	cout << "\nString before replace word : ";
	cout << UserString << endl;

	string WordToReplace = ReadString("\nPlease enter word you want to replace : ");
	string NewWord = ReadString("Please enter a new word u want replace to : ");

	cout << "\nString after replace word : ";
	cout << ReplaceWordInString(UserString, WordToReplace, NewWord, enMatchCase::NotMatch) << endl;


}