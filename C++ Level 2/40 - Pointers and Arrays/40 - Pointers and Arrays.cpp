#include <iostream>
using namespace std;



int main()
{
	int arr[4] = { 10, 20, 30, 40 };
	int* pointer = arr;

	// pointer is equivalent to &arr[0];
	// pointer + 1 is equivalent to &arr[1];
	// pointer + 2 is equivalent to &arr[2];
	// pointer + 3 is equivalent to &arr[3];

	cout << "Addresses are : " << endl;
	cout << pointer << endl;
	cout << pointer + 1 << endl;
	cout << pointer + 2 << endl;
	cout << pointer + 3 << endl;
	// I can do this also &pointer[i];

	cout << "\nValues are : " << endl;
	cout << *(pointer) << endl;
	cout << *(pointer + 1) << endl;
	cout << *(pointer + 2) << endl;
	cout << *(pointer + 3) << endl;
	// I can do this also pointer[i];


}