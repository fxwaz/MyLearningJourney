#include <iostream>
#include <string>
using namespace std;


int main()
{
	string S1 = "My Name is Fawaz Alzahrani, Alhamdullah for Everything";


	// Prints the length of the string
	cout << "Length of the string = " << S1.length() << endl;


	// Prints the char at position 3
	cout << "The char in the position 3 = " << S1.at(3) << endl;


	// Adds this text to the end of string
	cout << S1.append(" @fxwaz") << endl;


	// Adds this text to the string at position 17
	cout << S1.insert(17, "Saeed ") << endl;


	// Prints part of the string starting from position 16 with a length of 8 chars
	cout << S1.substr(16, 8) << endl;


	// Adds one char to the end of the string
	S1.push_back('.');
	cout << S1 << endl;


	// Removes one char from the end of the string
	S1.pop_back();
	cout << S1 << endl;


	// Searches for the string and returns its position
	cout << S1.find("Saeed") << endl;


	// Searches for the string and returns its position
	cout << S1.find("saeed") << endl;


	// If not found 
	if (S1.find("saeed") == S1.npos)
	{
		cout << "saeed is not found";

	}


	// Clears all string
	S1.clear();

	cout << S1 << endl;



	/*
	 
				substr(StartPosition, Length)
						│              │
						│              └── How many characters to take
						│
						└───────────────── Where to start



			Example:

			string Name = "Fawaz Alzahrani";

			Name.substr(6, 9);


			Index:   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
					 F a w a z   A l z a h  r  a  n  i
								 ↑
							  Start = 6
								 │
								 └─────────────────────────┐
														   │
								 A l z a h r a n i         │
								 └─────────────────┘       │
									  Length = 9           │
														   │
														   ▼
												   Result: "Alzahrani"


			Important:

			substr(6, 9)

			6 = Starting position
			9 = Number of characters to take

			The second number is NOT the ending position


	*/
}