// Write a program that reads the user age and license status, then prints "Hired" if the user is over 21 and has a driving license, otherwise prints "Rejected"
#include <iostream>
using namespace std;

struct stUserInfo
{
	int Age;
	bool HasDrivingLicense;
};

stUserInfo ReadUserInfo()
{
	stUserInfo UserInfo;

	cout << "Please enter your age : ";
	cin >> UserInfo.Age;

	cout << "Do you have a driver license? Enter 1 for Yes, 0 for No : " << endl;
	cin >> UserInfo.HasDrivingLicense;

	return UserInfo;
}

bool IsUserAccepted(stUserInfo UserInfo)
{

	return (UserInfo.Age > 21 && UserInfo.HasDrivingLicense);

}

void PrintUserResult(stUserInfo UserInfo)
{
	
	if (IsUserAccepted(UserInfo))
	{
		cout << "\n Hired !\n";
	}
	else
	{
		cout << "\n Rejected \n";
	}

}




int main()
{

	PrintUserResult(ReadUserInfo());

}