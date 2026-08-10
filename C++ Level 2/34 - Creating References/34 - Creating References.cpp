#include <iostream>
using namespace std;



int main()
{

	int a = 10;
	int& x = a;

	// The compiler dosen't allocate a new memory location for x
	// x is just an alias "another name" for a

	/*
		So it's like this: both refer to the same value in memory

	a ──┐
			├──> [ 10 ]
	x ──┘

	
	*/


	// Same value
	cout << a << endl;
	cout << x << endl;

	// Same memory address
	cout << &a << endl;
	cout << &x << endl;

}