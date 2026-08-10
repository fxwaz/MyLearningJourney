#include <iostream>
using namespace std;


int main()
{

    // Dereferencing means: Accessing the value stored at the address that the pointer points to
    // Example:
    // int a = 10;
    // int *p = &a;  ->  p stores the address of a
    // *p            ->  Access the value stored at that address, which is exactly what Dereferencing does

	int a = 10;
	cout << "a value = " << a << endl;
	cout << "a address = " << &a << endl;


	int *p = &a;
	cout << "\nPointer Value = " << p << endl;
	cout << "The value stored at the address that p points to = " << *p << endl;

	*p = 20;
    cout << "\na after changing it through the pointer = " << a << endl;
	cout << "The value stored at the address that p points to = " << *p << endl;

	a = 30;
	cout << "\na value = " << a << endl;
	cout << "The value stored at the address that p points to = " << *p << endl;


   // cout << *p;   // Dereference + Read

   // *p = 20;      // Dereference + Modify

    /*
     
    Memory idea:

    a
    +------+
    |  30  |
    +------+
    Address: 0x100

    p
    +-------+
    | 0x100 | --------> a
    +-------+
    Address: 0x200


    a   = 30       // Value stored in a
    &a  = 0x100    // Address of a

    p   = 0x100    // Address stored inside p
    &p  = 0x200    // Address of p itself

    *p  = 30       // Value stored at the address that p points to


    *p = 20;

    means:

    Go to the address stored inside p (0x100)
    and change the value there to 20

    Since 0x100 is the address of a
    changing *p also changes a

*/

}