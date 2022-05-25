#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AccountAccess.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"
#include "../ViewModels/TransactionViewModel.h"
#include "../Models/Transaction.h"

class TransactionAccess
{
	public:
		static vector<Transaction> GetByAccountID(int accountID);
		static string Add(TransactionViewModel model);
};