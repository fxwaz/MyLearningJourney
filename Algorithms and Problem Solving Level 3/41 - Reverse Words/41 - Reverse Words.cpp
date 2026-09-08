// Write a program to read string and reverse its words.
#include <iostream>
#include <string>
#include <vector>
using namespace std;



string ReadString()
{
	string UserString;

	cout << "Please enter your string : ";
	getline(cin, UserString);

	return UserString;
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

string ReverseString(string Text)
{
	vector <string> vString = SplitStringToVector(Text, " ");
	vector <string>::iterator iter = vString.end();
	string Reverse = "";

	
	while (iter != vString.begin())
	{
		iter--;
		Reverse = Reverse + *iter + " ";
	}

	return Reverse.substr(0, Reverse.length() - 1);
}



int main()
{
	string UserString = ReadString();


	cout << "\nString after reversing words : \n";
	cout << ReverseString(UserString) << endl;
}