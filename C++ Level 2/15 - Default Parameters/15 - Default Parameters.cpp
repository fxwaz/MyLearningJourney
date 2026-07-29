#include <iostream>
using namespace std;



// Default Parameters
// Default parameters allow a function parameter to have a default value
// If the caller does not provide a value for that parameter the default value will be used automatically.
int Sum(int a, int b, int c = 0, int d = 0)
{
	return (a + b + c + d);
}



int main()
{

	// c and d are not provided so their default values (0 and 0) are used
	cout << Sum(10, 20) << endl;

	// d is not provided, so its default value (0) is used
	cout << Sum(10, 20, 30) << endl;

	// All values are provided so no default values are used
	cout << Sum(10, 20, 30 , 40) << endl;

}