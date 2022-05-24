#pragma once
#include <string>
#include "../Enums/AccountType.h"

using namespace std;

class Account
{
	public:
		int ID;
		int CustomerID;
		AccountType Type;
		string IBAN;
		double Balance;
		string CreateDate;
		bool IsDeleted;
};