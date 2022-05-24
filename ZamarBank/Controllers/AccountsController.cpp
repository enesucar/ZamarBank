#include "AccountsController.h"

void AccountsController::AccountsGet(Customer customer, string message)
{
	vector<Account> accounts = AccountAccess::GetListByCustomerID(customer);
	return AccountsView(accounts, customer);
}

void AccountsController::AddAccountGet(Customer customer, string message)
{
	return AddAccountView(customer, message);
}

void AccountsController::AddAccountPost(AccountType type, Customer customer, string message)
{
	int result = AccountAccess::Add(type, customer);
	if (!result)
	{
		return AddAccountGet(customer, "Hesap oluþturulamadý, lütfen tekrar deneyiniz.");
	}

	ProcessController processController;
	return processController.ProcessGet(customer, "Hesap baþarýyla oluþturuldu.");
}