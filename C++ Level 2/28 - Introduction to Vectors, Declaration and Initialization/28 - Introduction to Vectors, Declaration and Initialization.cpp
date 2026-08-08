#include <iostream>
#include <vector>
using namespace std;



int main()
{
	vector <int> vNumbers = { 10, 20 , 50 };


	// Without "&" each element is copied into number
	// With "&" Number refers directly to the original element without making a copy
	for (int &Number : vNumbers)
	{
		cout << Number << endl;
	}
		
}