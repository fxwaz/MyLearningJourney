#include <iostream>
using namespace std;



int main()
{

	char Name[] = "Fawaz Alzahrani";
	char SchoolName[] = "ProgrammingAdvices";

	// Print Strings using char arrays
	printf("Hey, Good Morning Mr.%s \n", Name);
	printf("\nWelcome to the %s \n", SchoolName);

	char A = 'F';


	// Width Specification
	// %*c prints a char with a specified width
	// Example:
	// %*c with width 4 prints : "   F"
	printf("\nSetting the width of A : %*c \n", 1, A);
	printf("Setting the width of A : %*c \n", 2, A);
	printf("Setting the width of A : %*c \n", 3, A);
	printf("Setting the width of A : %*c \n", 4, A);
	
}