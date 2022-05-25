#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"
#include "../../Helpers/Random/Random.h"
#include "../../Helpers/String/String.h"
#include "../Models/Account.h"
#include "../Models/Customer.h"

class AccountAccess
{
	public:
		static vector<Account> GetListByCustomerID(int customerID);
		static int Add(AccountType type, int customerID);
};