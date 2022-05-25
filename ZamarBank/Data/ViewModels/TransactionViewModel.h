#pragma once
#include <string>
#include "../Enums/TransactionType.h"

using namespace std;

class TransactionViewModel {
	public:
		int FromAccountID;
		string ToAccountIBAN;
		TransactionType Type;
		double Balance;
		string Description;
		string CreateDate;
};

