#include <iostream>
using namespace std;



void Swap(int *first, int *second)
{

	int temp = *first;

	*first = *second;
	*second = temp;


}


int main()
{
	int First = 10;
	int Second = 5;

	//int* first = &First;
	//int* second = &Second;

	cout << "Before swap : " << endl;
	cout << First << endl;
	cout << Second << endl;


	Swap(&First, &Second);
	cout << endl;


	cout << "After swap : " << endl;
	cout << First << endl;
	cout << Second;

}