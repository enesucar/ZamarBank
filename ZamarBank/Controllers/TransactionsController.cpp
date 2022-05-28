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

void TransactionsController::AddTransactionPost(TransactionAddModel model, Customer customer, string message) {
	Account account = AccountAccess::GetByAccountID(model.FromAccountID);
	
	if (account.CustomerID != customer.ID)
	{
		return AddTransactionGet(model.Type, customer, "Lütfen geçerli bir hesap ID'si giriniz.");
	}
	
	string result = TransactionAccess::Add(model);
	
	if (result == "1")
	{
		ProcessController processController;
		return processController.ProcessGet(customer, "Ýþlem baþarýyla gerçekleþti!");
	}
	else
	{
		return AddTransactionGet(model.Type, customer, result);
	}
}