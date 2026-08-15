#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector <int> Numbers = { 10, 20, 30, 40, 50 };


	cout << "Initial Vector: ";
	for (const int &i : Numbers)
	{
		cout << i << " ";
	}


	cout << "\n\nUpdated Vector: ";
	for (int& i : Numbers)
	{
		i = 20;

		cout << i << " ";
	}


	Numbers[1] = 40;
	Numbers.at(2) = 66;
	Numbers.at(0) = 104;


	cout << "\n\nUpdated Vector :";
	for (const int& i : Numbers)
	{
		cout << i << " ";
	}

	cout << endl;

}


