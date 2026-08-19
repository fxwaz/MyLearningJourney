#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
using namespace std;



int main()
{
	// time() gets the current time
	// It returns the time as a time_t value
	time_t CurrentTime = time(0);


	// ctime() converts the time_t value to a readable local date and time
	// It returns the address of the first char in the generated text
	char * ReadableTime = ctime(&CurrentTime);
	cout << "Local date and time is : " << ReadableTime << endl;


	// gmtime() converts the time_t value to UTC time
	// It stores the result in a tm struct and returns its address
	tm* UTCTime = gmtime(&CurrentTime);

	// asctime() converts the tm struct to readable text
	// It returns the address of the first char in the generated text
	ReadableTime = asctime(UTCTime);

	cout << "UTC date and time is : " << ReadableTime << endl;
}




/*
	
					 LOCAL TIME:
	

	1) time(0) returns the current time:

	CurrentTime
	+------------------+
	|    1787123456    |   <- time_t value
	+------------------+
		  0x100


	2) We pass the address of CurrentTime to ctime():

				  &CurrentTime
					   |
					   v
				+-------------+
				|   ctime()   |
				+------+------+
					   |
					   | creates readable text
					   | somewhere in memory
					   v

	0x500
	  |
	  v
	+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	| 'W' | 'e' | 'd' | ' ' | 'A' | 'u' | 'g' | ... |'\0'|
	+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	  ^
	  |
	  | points here
	  |
	+---------+
	|  0x500  |  ReadableTime
	+---------+

	ReadableTime contains 0x500, NOT the text itself



	
					   UTC TIME :
	

	3) We pass the same &CurrentTime to gmtime():

				  &CurrentTime
					   |
					   v
				+-------------+
				|  gmtime()   |
				+------+------+
					   |
					   | creates and fills
					   | a tm struct
					   v

	0x800
	  |
	  v
	+----------------------+
	|      tm struct       |
	+----------------------+
	| tm_sec   = ...       |
	| tm_min   = ...       |
	| tm_hour  = ...       |
	| tm_mday  = ...       |
	| tm_mon   = ...       |
	| tm_year  = ...       |
	+----------------------+
	  ^
	  |
	  | points here
	  |
	+---------+
	|  0x800  |  UTCTime
	+---------+

	UTCTime contains 0x800 the address of the tm struct


	4) Then we give UTCTime to asctime():

		 UTCTime
			|
			| 0x800
			v
	+----------------------+
	|      tm struct       |
	|    UTC time data     |
	+----------+-----------+
			   |
			   v
		 +-----------+
		 | asctime() |
		 +-----+-----+
			   |
			   | creates readable text
			   v

	0x900
	  |
	  v
	+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	| 'W' | 'e' | 'd' | ' ' | 'A' | 'u' | 'g' | ... |'\0'|
	+-----+-----+-----+-----+-----+-----+-----+-----+-----+
	  ^
	  |
	  | points here
	  |
	+---------+
	|  0x900  |  ReadableTime
	+---------+


	
						 cout:
	

	cout << ReadableTime;

	ReadableTime
		 |
		 | 0x900
		 v
		'W' -> 'e' -> 'd' -> ' ' -> 'A' -> ... -> '\0'
		 ^                                         ^
		 |                                         |
	   starts                                    stops

	Because ReadableTime is a char*, cout treats it as
	a C-style string and prints every char until '\0'

*/