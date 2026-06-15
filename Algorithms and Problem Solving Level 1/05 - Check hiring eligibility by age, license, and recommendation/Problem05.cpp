// Write a program that asks the user to enter their age and license status and recommendation status, then prints "Hired" if they have a recommendation or if they are over 21 and have a driving license, otherwise prints "Rejected".
#include <iostream>
using namespace std;


struct stUserInfo
{
	int Age;
	bool HasDrivingLicense;
	bool HasRecommendation;
};



stUserInfo ReadUserInfo()
{
	stUserInfo UserInfo;

	cout << "Please enter your age : ";
	cin >> UserInfo.Age;

	cout << "Please enter if you have License, 1 for yes, 0 for no : ";
	cin >> UserInfo.HasDrivingLicense;

	cout << "Please enter if you have Recommendation, 1 for yes, 0 for no : ";
	cin >> UserInfo.HasRecommendation;

	return UserInfo;
}

bool IsUserAccepted(stUserInfo userInfo)
{

	if (userInfo.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (userInfo.Age > 21 && userInfo.HasDrivingLicense);
	}

}

void PrintResult(stUserInfo userInfo)
{

	if (IsUserAccepted(userInfo))
	{
		cout << "\n Hired \n";
	}
	else
	{
		cout << "\n Rejected \n";
	}

}

int main()
{


	PrintResult(ReadUserInfo());




}