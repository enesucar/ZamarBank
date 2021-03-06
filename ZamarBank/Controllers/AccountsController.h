#pragma once
#include <string>
#include <vector>
#include "ProcessController.h"
#include "../Data/Models/Account.h"
#include "../Data/Access/AccountAccess.h"
#include "../Data/Models/Transaction.h"
#include "../Views/Accounts/AccountsView.h"
#include "../Views/Accounts/AddAccountView.h"

using namespace std;

class AccountsController
{
	public:
		void AccountsGet(Customer customer, string message = "");
		void AddAccountGet(Customer customer, string message = "");
		void AddAccountPost(AccountType type, Customer customer, string message = "");
};
