// Write a program to print all words from AAA to ZZZ
#include <iostream>
using namespace std;


void PrintWords()
{
	for (int i = 65; i <= 70; i++)
	{

		for (int j = 65; j <= 70; j++)
		{
	

			for (int x = 65; x <= 70; x++)
			{
				cout << char(i) << char(j) << char(x) << endl;
			}


		}
		
		
	}
}

int main()
{
	PrintWords();
}
