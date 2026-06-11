// Write a program that asks the user to enter his name and prints it on the screen
#include <iostream>
#include <string>
using namespace std;


string ReadNameFromUser()
{
	string username;
	cout << "Please enter your name : ";
	getline(cin, username);

	return username;
}

void PrintUserName(string username)
{
	cout << "Your name is : " << username << endl;
}

int main()
{


	PrintUserName(ReadNameFromUser());


}