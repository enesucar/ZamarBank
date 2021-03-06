#include "CustomersController.h"

void CustomersController::LoginGet()
{
	return LoginView();
}

void CustomersController::LoginPost(CustomerLoginModel model)
{
	Customer customer = CustomerAccess::GetByIdentificationNumber(model.IdentificationNumber);
	LoginHistory loginHistory;

	if (customer.ID == 0)
	{
		return LoginView("T.C. Kimlik numaras? yanl??.");
	}
	else if (customer.Password != model.Password)
	{
		loginHistory.CustomerID = customer.ID;
		loginHistory.IsLoginSuccessful = false;
		LoginHistoryAccess::Add(loginHistory);

		return LoginView("?ifre yanl??.");
	}

	loginHistory.CustomerID = customer.ID;
	loginHistory.IsLoginSuccessful = true;
	LoginHistoryAccess::Add(loginHistory);

	ProcessController processController;
	processController.ProcessGet(customer);
}

void CustomersController::RegisterGet() {
	return RegisterView();
}

void CustomersController::RegisterPost(CustomerRegisterModel model)
{
	if (isCustomerExists(model.IdentificationNumber))
	{
		return RegisterView("Sistemde b?yle bir kullan?c? zaten mevcut.");
	}
	else if (!isPasswordsSame(model.Password, model.PasswordAgain) ||
			 !isPasswordLengthEqualSix(model.Password) ||
			 isPasswordBeginWithZero(model.Password) ||
			 isPasswordHasAnyCharacter(model.Password))
	{
		return RegisterView("?ifreniz ge?ersiz.");
	}

	CustomerAccess::Add(model);

	HomeController homeController;
	return homeController.HomeGet("Kullan?c? sisteme ba?ar?yla eklendi.");
}

void CustomersController::LoginHistoryGet(Customer customer) {
	vector<LoginHistory> loginHistories = LoginHistoryAccess::GetListByCustomerID(customer.ID);
	return LoginHistoriesView(loginHistories, customer);
}

bool CustomersController::isCustomerExists(string number) { // s takas?na bak
	Customer customer = CustomerAccess::GetByIdentificationNumber(number);
	return (customer.ID == 0) ? false : true;
}

bool CustomersController::isPasswordsSame(string password, string passwordAgain) {
	return (!password.compare(passwordAgain)) ? true : false;
}

bool CustomersController::isPasswordLengthEqualSix(string password) {
	return (password.length() == 6) ? true : false;
}

bool CustomersController::isPasswordBeginWithZero(string password) {
	return (password[0] == '0') ? true : false;
}

bool CustomersController::isPasswordHasAnyCharacter(string password) {
	string numbers = "0123456789";
	
	for (char number : password)
	{
		if (numbers.find(number) == string::npos)
		{
			return true;
		}
	}

	return false;
}