#include "CustomersController.h"

void CustomersController::LoginGet()
{
	return LoginView();
}

void CustomersController::LoginPost(CustomerLoginViewModel model)
{
	Customer customer = CustomerAccess::GetByIdentificationNumber(model.IdentificationNumber);
	if (customer.ID == 0 || customer.Password != model.Password)
	{
		return LoginView("TC Kimlik Numaras� veya �ifre yanl��.");
	}

	
}

void CustomersController::RegisterGet() {
	return RegisterView();
}

void CustomersController::RegisterPost(CustomerRegisterViewModel model)
{
	if (isCustomerExist(model.IdentificationNumber))
	{
		return RegisterView("Sistemde b�yle bir kullan�c� zaten mevcut.");
	}
	else if (!isPasswordsSame(model.Password, model.PasswordAgain) ||
			 !isPasswordLengthEqualSix(model.Password) ||
			 isPasswordBeginWithZero(model.Password) ||
			 isPasswordHaveAnyCharacter(model.Password))
	{
		return RegisterView("�ifreniz ge�ersiz.");
	}

	int result = CustomerAccess::Add(model);
	if (!result)
	{
		return RegisterView("Kullan�c� kayd� yap�lamad�, l�tfen tekrar deneyiniz.");
	}

	HomeController homeController;
	return homeController.HomeGet("Kullan�c� sisteme ba�ar�yla eklendi.");
}

void CustomersController::ChangePasswordGet()
{

}

void CustomersController::ChangePasswordPost(CustomerChangePasswordViewModel model)
{

}

bool CustomersController::isCustomerExist(string number) { // s takas�na bak
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