#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "AccountAccess.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"
#include "../ViewModels/TransactionViewModel.h"

class TransactionAccess
{
	public:
		static int Add(TransactionViewModel model);
};