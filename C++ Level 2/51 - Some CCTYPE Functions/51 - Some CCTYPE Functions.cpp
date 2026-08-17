#include <iostream>
#include <string>
#include <cctype>
using namespace std;



int main()
{
	char x;
	char w;

	// Converts a lowercase letter to uppercase
	x = toupper('a');
	// Converts an uppercase letter to lowercase
	w = tolower('A');


	cout << "Convert a to A : " << x << endl;
	cout << "Convert A to a : " << w << endl;


	// If the char is uppercase returns a non zero value
	// Otherwise returns zero
	cout << "Isupper = " << isupper('A') << endl;
	// If the char is lowercase returns a non zero value
	// Otherwise, returns zero
	cout << "Islower = " << islower('a') << endl;


	// Checks if the char is a digit from 0 to 9
	// If true returns a non zero value
	// Otherwise returns zero
	cout << "Isdigit = " << isdigit('9') << endl;


	// punctuation chars are !@#$%^&*()_=.<?:"{}
	// Checks if the char is a punctuation character
	// If true returns a non zero value
	// Otherwise returns zero
	cout << "Ispunct = " << ispunct('!') << endl;

}