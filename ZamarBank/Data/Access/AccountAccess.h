#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../Models/Account.h"
#include "../Models/Customer.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"
#include "../../Helpers/Random/Random.h"
#include "../../Helpers/String/String.h"

class AccountAccess
{
	public:
		static Account GetByAccountID(int accountID);
		static Account GetByIBAN(string IBAN);
		static vector<Account> GetListByCustomerID(int customerID);
		static void Add(AccountType type, int customerID);
		static void UpdateBalance(int accountID, double balance);
};