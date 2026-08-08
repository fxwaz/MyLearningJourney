#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	vNumbers.push_back(40);
	vNumbers.push_back(50);


	cout << "First element = " << vNumbers.front() << endl;
	cout << "Last element = " << vNumbers.back() << endl;
	cout << "Size of vector = " << vNumbers.size() << endl;
	cout << "Capaty of vector = " << vNumbers.capacity() << endl;
	cout << "IsEmpty : " << vNumbers.empty() << endl;

	cout << endl;

	// Here I can see how the capacity grows when the vector becomes full
	
	for (int i = 1; i <= 10; i++)
	{
		vNumbers.push_back(i);

		cout << "Size = " << vNumbers.size() << "   | Capacity = " << vNumbers.capacity() << endl;
	}

}

/*


            Size of Vector  = 5
          <-------------------->
         ┌────┬────┬────┬────┬────┬────┬────┬────┐
Vector   │ 10 │ 20 │ 30 │ 40 │ 50 │    │    │    │
         └────┴────┴────┴────┴────┴────┴────┴────┘
          <--------------------------------------->
                    Capacity of Vector = 8  


	Size = How many elements are currently in the vector
	Capacity = How many elements the vector can currently hold

	If Size < Capacity:
	There is free space so the vector can add a new element directly

	If Size == Capacity:
	The vector is full so it needs to allocate more memory before adding a new element
*/

