#include <iostream>
using namespace std;


int MySum(int a, int b)
{
	int s = 0;
	s = a + b;

	return s;
}


int main()
{
	int arr1[5] = { 200,100,50,25,30 };
	int a, b, c;

	a = 10;
	b = 20;
	a++;
	++b;

	c = a + b;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	for (int i = 1; i <= 5; i++)
	{
		cout << i << endl;
		a = a + a * i;
	}

	c = MySum(a, b);

	cout << c;


	// Step Into executes the code line by line and enters function calls.
	// Step Over executes the current line without entering called functions.
	// Step Out finishes the current function and returns to the caller.
	

}