#include "CustomersController.h"

void CustomersController::LoginGet()
{
}

void CustomersController::LoginPost(CustomerLoginViewModel model)
{
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
		return RegisterView("Þifreniz geçersiz, lütfen tekrar deneyiniz.");
	}

	CustomerAccess::Add(model);

	HomeController homeController;
	return homeController.HomeGet("Kullanýcý sisteme baþarýyla eklendi!");
}

void CustomersController::ChangePasswordGet()
{

}

void CustomersController::ChangePasswordPost(CustomerChangePasswordViewModel model)
{

}

bool CustomersController::isCustomerExist(string number) { // s takasýna bak
	Customer customer = CustomerAccess::GetByIdentificationNumber(number);
	return false;
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