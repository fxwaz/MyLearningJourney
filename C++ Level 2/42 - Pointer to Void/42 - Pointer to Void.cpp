#include <iostream>
using namespace std;



int main()
{
	// A void pointer can store the address of any data type
	// but it cannot be dereferenced directly because It's dosent know the data type
	void* pointer;
	float floatNumber = 10.5;
	int intNumber = 5;

	cout << "Float value :" << endl;
	pointer = &floatNumber;
	cout << pointer << endl;
	// Convert the void pointer to float pointer then dereference it to get the value
	cout << *(static_cast<float*>(pointer)) << endl;

	cout << "\nInt value :" << endl;
	pointer = &intNumber;
	cout << pointer << endl;
	// Convert the void pointer to int pointer then dereference it to get the value
	cout << *(static_cast<int*>(pointer)) << endl;
}