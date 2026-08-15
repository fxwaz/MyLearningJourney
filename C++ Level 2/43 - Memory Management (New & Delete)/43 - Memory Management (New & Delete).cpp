#include <iostream>
using namespace std;



int main()
{

	// Declare pointers
	int* pointInt;
	float* pointFloat;


	// Dynamically allocate memory at runtime
	pointInt = new int;
	pointFloat = new float;


	// Assign values to the dynamically allocated memory
	*pointInt = 100;
	*pointFloat = 45.45;

	cout << *pointInt << endl;
	cout << *pointFloat << endl;


	// Deallocate the memory when It's no longer needed
	delete pointInt;
	delete pointFloat;


	// Dynamic memory allows us to allocate memory at runtime and release it when we no longer need it


}