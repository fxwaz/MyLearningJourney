#include <iostream>
using namespace std;



int main()
{

	int x = 10;
	int *p;

	// Wrong!
	// p = x;
	// p stores an address, but x contains a value

	// Correct!
	p = &x;
	// &x is the address of x, so p can store it

	// Wrong!
	// *p = &x;
	// *p represents the value at the address p points to
	// but &x is an address

	// Correct!
	*p = x;
	// *p is a value, and x is also a value

	cout << "Address of x stored inside p = " << p << endl;
	cout << "The value of x that the pointer points to = " << *p << endl;

}