#include "TransactionsController.h"

void TransactionsController::AddTransactionGet(TransactionType type, Customer customer, string message) {
	if (type == TransactionType::Deposit)
	{
		return DepositView(customer, message);
	}
	else if (type == TransactionType::Withdraw)
	{
		return WithdrawView(customer, message);
	}
	else if (type == TransactionType::Transfer)
	{
		return TransferView(customer, message);
	}
}

void TransactionsController::AddTransactionPost(TransactionViewModel model, Customer customer, string message) {
	Account account = AccountAccess::GetByID(model.FromAccountID);
	
	if (account.CustomerID != customer.ID)
	{
		return AddTransactionGet(model.Type, customer, "L�tfen ge�erli bir hesap ID'si giriniz.");
	}
	
	string result = TransactionAccess::Add(model);
	
	if (result == "1")
	{
		ProcessController processController;
		return processController.ProcessGet(customer, "��lem ba�ar�yla ger�ekle�ti!");
	}
	else
	{
		return AddTransactionGet(model.Type, customer, result);
	}
}