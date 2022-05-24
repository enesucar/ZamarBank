#pragma once
#include <string>

using namespace std;

class Customer
{
	public:
		int ID;
		string FirstName;
		string LastName;
		string IdentificationNumber;
		string CustumerNumber;
		string Password;
		string CreateDate;
		bool IsDeleted;
};