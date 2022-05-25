#include "CustomersController.h"

void CustomersController::LoginGet()
{
	return LoginView();
}

void CustomersController::LoginPost(CustomerLoginViewModel model)
{
	Customer customer = CustomerAccess::GetByIdentificationNumber(model.IdentificationNumber);
	LoginHistory loginHistory;

	if (customer.ID == 0)
	{
		return LoginView("TC Kimlik Numarasý yanlýþ.");
	}
	else if (customer.Password != model.Password)
	{
		loginHistory.CustomerID = customer.ID;
		loginHistory.IsLoginSuccessful = false;
		LoginHistoryAccess::Add(loginHistory);

		return LoginView("Þifre yanlýþ.");
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

void CustomersController::RegisterPost(CustomerRegisterViewModel model)
{
	if (isCustomerExist(model.IdentificationNumber))
	{
		return RegisterView("Sistemde böyle bir kullanýcý zaten mevcut.");
	}
	else if (!isPasswordsSame(model.Password, model.PasswordAgain) ||
			 !isPasswordLengthEqualSix(model.Password) ||
			 isPasswordBeginWithZero(model.Password) ||
			 isPasswordHaveAnyCharacter(model.Password))
	{
		return RegisterView("Þifreniz geçersiz.");
	}

	int result = CustomerAccess::Add(model);
	if (!result)
	{
		return RegisterView("Kullanýcý kaydý yapýlamadý, lütfen tekrar deneyiniz.");
	}

	HomeController homeController;
	return homeController.HomeGet("Kullanýcý sisteme baþarýyla eklendi.");
}

void CustomersController::ChangePasswordGet()
{

}

void CustomersController::ChangePasswordPost(CustomerChangePasswordViewModel model)
{

}

void CustomersController::LoginHistoryGet(Customer customer) {
	vector<LoginHistory> loginHistories = LoginHistoryAccess::GetListByCustomerID(customer.ID);
	return LoginHistoriesView(loginHistories, customer);
}

bool CustomersController::isCustomerExist(string number) { // s takasýna bak
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

bool CustomersController::isPasswordHaveAnyCharacter(string password) {
	string numbers = "0123456789";
	
	for (char number : password) // password should be to lower
	{
		if (numbers.find(number) == string::npos)
		{
			return true;
		}
	}

	return false;
}