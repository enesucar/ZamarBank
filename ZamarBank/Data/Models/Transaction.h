#pragma once
#include <string>
#include "../Enums/TransactionType.h"

using namespace std;

class Transaction
{
	public:
		int ID;
		int FromAccountID;
		int ToAccountID;
		TransactionType Type;
		double Balance;
		string Description;
		string CreateDate;
};