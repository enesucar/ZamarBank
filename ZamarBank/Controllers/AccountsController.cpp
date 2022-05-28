#include "AccountsController.h"

void AccountsController::AccountsGet(Customer customer, string message)
{
	vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
	return AccountsView(accounts, customer, message);
}

void AccountsController::AddAccountGet(Customer customer, string message)
{
	return AddAccountView(customer, message);
}

void AccountsController::AddAccountPost(AccountType type, Customer customer, string message)
{
	AccountAccess::Add(type, customer.ID);

	ProcessController processController;
	return processController.ProcessGet(customer, "Hesap baþarýyla oluþturuldu.");
}