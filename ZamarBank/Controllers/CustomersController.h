#pragma once
#include <vector>
#include "HomeController.h"
#include "../Data/Models/Customer.h"
#include "../Data/ViewModels/CustomerViewModel.h"
#include "../Data/Access/CustomerAccess.h"
#include "../Views/Register/RegisterView.h"
#include "../Views/Login/LoginView.h"

using namespace std;

class CustomersController
{
	public:
		void LoginGet();
		void LoginPost(CustomerLoginViewModel model);
		void RegisterGet();
		void RegisterPost(CustomerRegisterViewModel model);
		void ChangePasswordGet();
		void ChangePasswordPost(CustomerChangePasswordViewModel model);

	private:
		bool isCustomerExist(string number);
		bool isPasswordLengthEqualSix(string password);
		bool isPasswordBeginWithZero(string password);
		bool isPasswordHaveAnyCharacter(string password);
		bool isPasswordsSame(string password, string passwordAgain);
};
