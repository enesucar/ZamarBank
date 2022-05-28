#pragma once
#include <string>
#include "ProcessController.h"
#include "../Data/ViewModels/TransactionViewModel.h"
#include "../Data/Access/TransactionAccess.h"
#include "../Data/Models/Customer.h"
#include "../Views/Transactions/DepositView.h"
#include "../Views/Transactions/WithdrawView.h"
#include "../Views/Transactions/TransferView.h"
#include "../Views/Transactions/TransactionsView.h"
#include "../Helpers/PdfFile/PdfFile.h"

using namespace std;

class TransactionsController
{
	public:
		void TransactionsGet(int accountID, Customer customer, string message = "");
		void AddTransactionGet(TransactionType type,Customer customer, string message = "");
		void AddTransactionPost(TransactionAddModel model, Customer customer, string message = "");
		void CreateTransactionPdfGet(int transactionID, Customer customer, string message = "");
};