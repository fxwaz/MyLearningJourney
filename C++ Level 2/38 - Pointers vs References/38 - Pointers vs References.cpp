#include <iostream>
using namespace std;



int main()
{
	// Reference:
	// Once it refers to a variable, it cannot refer to another variable

	int a = 10;
	int &b = a;

	int c = 20;

	// b is another name for a.
	// So if we do b = c, it does NOT make b refer to c
	// It copies the value of c into a because b is another name for a

	b = c;

	cout << "a address = " << &a << endl;
	cout << "b address = " << &b << endl;

	cout << "a value = " << a << endl;
	cout << "b value = " << b << endl;


	// Pointer:
	// A pointer can point to different variables during the program

	int* p = &a;

	cout << "\np value (address of a) = " << p << endl;
	cout << "Value p points to = " << *p << endl;
	cout << "p address = " << &p << endl;

	int d = 30;

	// Now p points to d instead of a
	p = &d;

	cout << "\nd address = " << &d << endl;
	cout << "p value (address of d) = " << p << endl;
	cout << "Value p points to = " << *p << endl;

	
}