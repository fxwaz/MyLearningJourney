#include <iostream>
using namespace std;



// Function Declaration
// The compiler reads the source code from top to bottom
// Since the function definition is below main(), the compiler does not know that the function exists yet
// So we declare the function to tell the compiler that the function will be defined later
void Sum(int, int);

// Without the function declaration the program will not compile


int main()
{
	Sum(10, 20);
}


// Function definition
void Sum(int a, int b)
{
	cout << a + b << endl;
}