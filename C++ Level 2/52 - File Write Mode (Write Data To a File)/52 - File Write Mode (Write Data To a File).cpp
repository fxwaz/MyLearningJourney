#include <iostream>
#include <fstream>
using namespace std;



int main()
{
	fstream Myfile;


	// Opens the file in write mode
	//           FileName     Mode
	Myfile.open("Text.txt", ios::out);


	// Checks if the file was opened successfully
	if (Myfile.is_open())
	{

		// WWrites data to the file
		Myfile << "Hello It's my first time writing to a file!!\n";
		Myfile << "Fawaz";


		// Closes the file after finishing
		Myfile.close();
	}

}