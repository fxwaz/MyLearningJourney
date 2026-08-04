#include <iostream>
using namespace std;


void MyFunc()
{
	// Static Variables
	// The static variable is created only once
	// It keeps its value every time the function is called
	// It can only be accessed inside the scope where it was declared

	static int Number = 1;

	cout << "Value of Number is : " << Number << endl;

	Number++;

}

int main()
{
	MyFunc();
	MyFunc();
	MyFunc();
}