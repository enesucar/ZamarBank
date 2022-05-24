#pragma once
#include <string>

using namespace std;

class LoginHistory
{
	public:
		int ID;
		int CustomerID;
		bool IsLoginSuccessful;
		string CreateDate;
};