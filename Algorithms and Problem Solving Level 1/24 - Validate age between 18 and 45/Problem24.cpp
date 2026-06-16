// Write a program to ask the user to enter Age, if age is between 18 and 45 print "Valid age" otherwise print "Invalid age"
#include <iostream>
using namespace std;


int ReadUserAge()
{
	int UserAge;

	cout << "Please enter your age : ";
	cin >> UserAge;

	return UserAge;
}

bool IsAgeInRange(int userage, int from, int to)
{
	return (userage >= from && userage <= to);
}

void PrintResult(int userage)
{
	if (IsAgeInRange(userage, 18, 45))
		cout << "\n " << userage << " is Valid age \n";
	else
		cout << "\n " << userage << " is Invalid age \n";
}

int main()
{
	PrintResult(ReadUserAge());
}