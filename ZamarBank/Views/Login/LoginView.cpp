#include "LoginView.h"

void LoginView(string message) {
	_PartialHeaderView(message);

	CustomerLoginModel loginModel;
	CustomersController customerController;

	cout << "TC Kimlik Numaras�: ";
	cin >> loginModel.IdentificationNumber;

	cout << "�ifre: ";
	cin >> loginModel.Password;

	return customerController.LoginPost(loginModel);
}