#include <iostream>
using namespace std;



int main()
{
	// Pointer is a variable that stores the memory address of another variable
	// Example:
	// Here I stored the address of a inside the pointer x

	

	int a = 10;
	cout << "a value = " << a << endl;
	cout << "a address = " << &a << endl;

	int* x = &a;
	cout << "\nPointer x value = " << x << endl;
	cout << "Pointer x address = " << & x << endl;


    /*
     
       Memory idea:

       a
       +------+
       |  10  |
       +------+
       Address: 0x100

       x
       +-------+
       | 0x100 | --------> a
       +-------+
       Address: 0x200


       a   = 10       // Value stored in a
       &a  = 0x100    // Address of a

       x   = 0x100    // Address stored inside x
       &x  = 0x200    // Address of x itself

   */
}