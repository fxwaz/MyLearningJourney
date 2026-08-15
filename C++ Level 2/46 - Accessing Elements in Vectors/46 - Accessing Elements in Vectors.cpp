#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector <int> Numbers = { 10, 20, 40, 40, 50 };

	// There are two ways to access elements in a vector
	

	// First way is using the [] operator
	cout << "Using VectorName[i] :" << endl;
	cout << "Element at index 0 = " << Numbers[0] << endl;
	cout << "Element at index 2 = " << Numbers[2] << endl;
	cout << "Element at index 4 = " << Numbers[4] << endl;
	// The [] operator does not check if the index is valid
	// Accessing an invalid index causes undefined behavior
	// It may return garbage data or cause the program to crash


	// Second way is using the at() function
	cout << "\n\nUsing VectorName.at(i) :" << endl;
	cout << "Element at index 0 = " << Numbers.at(0) << endl;
	cout << "Element at index 2 = " << Numbers.at(2) << endl;
	cout << "Element at index 4 = " << Numbers.at(4) << endl;
	// The at() function checks if the index is valid
	// Accessing an invalid index throws an out_of_range exception


 
	// Difference:
	// []   does not check if the index is valid
	// at() checks if the index is valid before accessing the element



}