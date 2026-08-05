#include <iostream>
#include <iomanip>
using namespace std;



int main()
{

	// Setw Manipulator
	// It sets the width of the next output only
	// Example:
	// cout << setw(10) << "Hi";
	// Prints "Hi" in a field with a width of 10 characters

	cout << "--------------------------------------------------------------|" << endl;
	cout << "   Code  |                   Name                   |   Mark  |" << endl;
	cout << "--------------------------------------------------------------|" << endl;
	cout << left << setw(9) << "CS101" << "|" << setw(42) << "Introduction to Programming 01" << "|" << setw(9) << "100" << "|" << endl;
	cout << setw(9) << "C102" << "|" << setw(42) << "Computer Hardware" << "|" << setw(9) << "54" << "|" << endl;
	cout << setw(9) << "SLM101" << "|" << setw(42) << "Introduction to Islam skills 01" << "|" << setw(9) << "90" << "|" << endl;
	cout << "---------------------------------------------------------------" << endl;

}