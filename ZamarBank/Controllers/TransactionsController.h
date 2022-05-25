#pragma once
#include <string>
#include "../Data/Models/Customer.h"
#include "../Views/Transactions/DepositView.h"
#include "../Views/Transactions/WithdrawView.h"
#include "../Views/Transactions/TransferView.h"
#include "../Data/ViewModels/TransactionViewModel.h"
#include "../Data/Access/TransactionAccess.h"
#include "ProcessController.h"

using namespace std;

class TransactionsController
{
	public:
		void AddTransactionGet(TransactionType type,Customer customer, string message = "");
		void AddTransactionPost(TransactionViewModel model, Customer customer, string message = "");
};