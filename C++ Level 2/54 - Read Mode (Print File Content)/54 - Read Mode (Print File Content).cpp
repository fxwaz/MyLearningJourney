#include <iostream>
#include <fstream>
#include <string>
using namespace std;



void PrintFileContent(string FileName)
{
	fstream MyFile;
                        // Read Mode
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{

		string Line;

        //    getline doesn't directly return true or false see thhe explanation below
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}

		MyFile.close();
	}
}


int main()
{
	fstream Test;

	Test.open("Text.txt", ios::out);

	if (Test.is_open())
	{
		Test << "Hello, Here we go again\n";
		Test << "Sb7an Allah\n";

		Test.close();
	}

	PrintFileContent("Text.txt");
}

/*
 
    getline() does not directly return true or false
    It returns the input stream (MyFile)

    The while condition checks the state of the stream:
    If getline() successfully reads a line the stream is treated as true
    If getline() fails to read a line such as reaching the end of the file the stream is treated as false



    getline(MyFile, Line)
            │
            ├── Reads one line from MyFile
            ├── Stores the line in Line
            └── Returns MyFile itself
                        │
                        ▼
              while checks its state
                        │
                        ▼
            Was the line read successfully?
                 /                  \
               Yes                   No
                │                     │
                ▼                     ▼
         MyFile is Good        MyFile is Failed
                │                     │
                ▼                     ▼
              true                  false
                │                     │
                ▼                     ▼
         ┌──────────────┐        Exit while
         │ cout << Line │
         └──────┬───────┘
                │
                ▼
       Try to read the next line
                │
                └──────────────► getline(MyFile, Line)

*/
