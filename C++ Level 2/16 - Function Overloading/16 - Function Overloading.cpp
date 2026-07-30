#include <iostream>
using namespace std;



double Sum(double first, double second)
{
	return first + second;
}

int Sum(int first, int second)
{
	return first + second;
}

int Sum(int first, int second, int third)
{
	return first + second + third;
}

int Sum(int first, int second, int third, int fourth)
{
	return first + second + third + fourth;
}



int main()
{
	// Function Overloading
    // Multiple functions can share the same name
	// The compiler selects the correct function by matching the function call to the function signature.
	// A function signature is like a function id
	// Every function has its own unique signature
	// For example when I call Sum(10, 20) the compiler looks for a matching signature
	// Sum(int, int)

	cout << Sum(10, 20) << endl; 
	cout << Sum(10, 20, 30)	<< endl;
	cout << Sum(10, 20, 30, 40) << endl;
	cout << Sum(50.5, 50.3) << endl;
}