#include "AccountsController.h"

void AccountsController::AccountsGet(Customer customer, string message)
{
	vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
	return AccountsView(accounts, customer);
}

void AccountsController::AddAccountGet(Customer customer, string message)
{
	return AddAccountView(customer, message);
}

void AccountsController::AddAccountPost(AccountType type, Customer customer, string message)
{
	int result = AccountAccess::Add(type, customer.ID);

	if (!result)
	{
		return AddAccountGet(customer, "Hesap oluþturulamadý, lütfen tekrar deneyiniz.");
	}

	ProcessController processController;
	return processController.ProcessGet(customer, "Hesap baþarýyla oluþturuldu.");
}

void AccountsController::AccountActivitiesGet(int accountID, Customer customer, string message) {
	Account account = AccountAccess::GetByID(accountID);
	if (account.CustomerID != customer.ID) // kullanýcýya ait olmayan hesap
	{	
		return ProcessView(customer, "Hesap ID'sini yanlýþ girdiniz.");
	}

	vector<Transaction> transactions = TransactionAccess::GetByAccountID(accountID);
	return AccountActivitiesView(transactions, customer);
}