#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	fstream Myfile;


	// Opens the file in append mode
	// New data will always be added to the end of the file
	Myfile.open("Text.txt", ios::app);
	
	// We can also combine file modes using the | operator
	// ios::out allows writing to the file
	// ios::app makes every write happen at the end of the file
	// Example:
	// myfile.open("Text.txt, ios::out | ios:app);


	
	if (Myfile.is_open())
	{

		// Appends new data without deleting the existing content
		Myfile << "\nNew text added by append mode";


		
		Myfile.close();
	}

}