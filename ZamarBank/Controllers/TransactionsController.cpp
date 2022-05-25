#include "TransactionsController.h"

void TransactionsController::AddTransactionGet(TransactionType type, Customer customer, string message) {
	if (type == TransactionType::Deposit)
	{
		return DepositView(customer);
	}
	else if (type == TransactionType::Withdraw)
	{
		return WithdrawView(customer);
	}
	else if (type == TransactionType::Transfer)
	{
		return TransferView(customer);
	}
}

void TransactionsController::AddTransactionPost(TransactionViewModel model, Customer customer, string message) {
	int result = TransactionAccess::Add(model);
	if (result > 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer, "��lem ba�ar�yla ger�ekle�ti!");
	}
	else
	{
		ProcessController processController;
		return processController.ProcessGet(customer, "��lem ger�ekle�tirilemedi!");
	}
}