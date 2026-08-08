#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}

	// It will show us how many elements are in this vector
	cout << "\nVector size before the pop = " << vNumbers.size() << endl;


	// Manually pop
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();
	vNumbers.pop_back();


	// vNumbers.clear();
	// It will clear all elements in the vector 

	cout << "Vector size after the pop = " << vNumbers.size() << endl;

	// vNumbers.empty()
	// It will return true if the vector is empty and false if it's not
	cout << "IsEmpty : " << vNumbers.empty();

}