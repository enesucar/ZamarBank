#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Models/LoginHistory.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"

class LoginHistoryAccess
{
	public:
		static vector<LoginHistory> GetListByCustomerID(int customerID);
		static void Add(LoginHistory model);
};