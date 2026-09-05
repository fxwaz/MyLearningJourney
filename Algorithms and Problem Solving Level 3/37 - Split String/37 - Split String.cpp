// Write a program to read a string then make a function to split each word in vector.
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

void PrintStringVector(vector <string> &vS)
{
	for (string &Word : vS)
	{
		cout << Word << endl;
	}
}



int main()
{
	vector <string> vString;
	string UserString;

	UserString = ReadString();
	vString = SplitStringToVector(UserString, " ");

	cout << "\nTokens = " << vString.size() << endl;
	PrintStringVector(vString);
}