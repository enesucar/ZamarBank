#pragma once
#include <vector>
#include "HomeController.h"
#include "ProcessController.h"
#include "../Data/Models/Customer.h"
#include "../Data/ViewModels/CustomerViewModel.h"
#include "../Data/Access/CustomerAccess.h"
#include "../Data/Access/LoginHistoryAccess.h"
#include "../Views/Register/RegisterView.h"
#include "../Views/Login/LoginView.h"
#include "../Views/LoginHistories/LoginHistoriesView.h"

using namespace std;

class CustomersController
{
	public:
		void LoginGet();
		void LoginPost(CustomerLoginModel model);
		void RegisterGet();
		void RegisterPost(CustomerRegisterModel model);
		void LoginHistoryGet(Customer customer);

	private:
		bool isCustomerExists(string number);
		bool isPasswordLengthEqualSix(string password);
		bool isPasswordBeginWithZero(string password);
		bool isPasswordHasAnyCharacter(string password);
		bool isPasswordsSame(string password, string passwordAgain);
};
