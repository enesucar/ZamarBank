#pragma once
#include <iostream>
#include "AccountAccess.h"
#include "../Models/Transaction.h"
#include "../ViewModels/TransactionViewModel.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"

class TransactionAccess
{
	public:
		static vector<Transaction> GetByAccountID(int accountID);
		static string Add(TransactionViewModel model);
};	