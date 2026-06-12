// Write a program that ask the user to enter his first name and last name then print it as full name
#include <iostream>
using namespace std;


struct stUserInfo
{

	string FirstName;
	string LastName;

};

stUserInfo ReadName()
{

	stUserInfo userInfo;

	cout << "Please enter your first name : ";
	cin >> userInfo.FirstName;

	cout << "Please enter your last name : ";
	cin >> userInfo.LastName;

	return userInfo;

}

string GetFullName(stUserInfo userInfo)
{

	return userInfo.FirstName + " " + userInfo.LastName;

}

void PrintFullName(string FullName)
{
	cout << "Your full name is : " << FullName << endl;
}

int main()
{
	PrintFullName(GetFullName(ReadName()));
}