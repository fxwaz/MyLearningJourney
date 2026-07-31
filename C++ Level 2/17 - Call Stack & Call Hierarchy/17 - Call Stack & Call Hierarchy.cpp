#include <iostream>
using namespace std;



void Function4()
{
	cout << "Hi I'm function4" << endl;
}

void Function3()
{
	Function4();
}

void Function2()
{
	Function3();
}

void Function1()
{
	Function2();
}



int main()
{

	// The Call Stack keeps track of function calls during program execution
	// Every function call adds a new Stack Frame to the top of the Call Stack
	// The last function added is the first function removed
	// This is called LIFO (Last In First Out)


	// Adding a function call to the Call Stack is called Push
	// Removing a function call from the Call Stack is called Pop

	Function1();

}
