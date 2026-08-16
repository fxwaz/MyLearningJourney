#include <iostream>
#include <vector>
using namespace std;



int main()
{

	vector <int> Numbers = { 10, 40, 70 };


	// Try block contains code thay ma cause an exception
	try
	{
		// This code will throw an exception because the index out of range
		cout << Numbers.at(4);
	}

    // Catch block handles the exception and prevents the program from crashing 
	catch(...)
	{
        // Here is what will be shown as output when an exception is caught
		cout << "You can't do this" << endl;
	}


	// TryCatch should be used for exceptional situations
    // not as a replacement for normal program logic


	/*
		     try
              │
              ▼
      ┌─────────────────┐
      │  Numbers.at(4)  │
      └────────┬────────┘
               │
       Is there an error?
          /          \
        No            Yes
        │              │
        ▼              ▼
    Continue         Exception
                       │
                       ▼
                  ┌─────────┐
                  │ catch() │
                  └────┬────┘
                       │
                       ▼
              "You can't do this"
	
	*/
	
}