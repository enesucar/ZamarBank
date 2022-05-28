#include "LoginView.h"

void LoginView(string message) {
	_PartialHeaderView(message);

	CustomerLoginModel loginModel;
	CustomersController customerController;

	cout << "TC Kimlik Numarasý: ";
	cin >> loginModel.IdentificationNumber;

	cout << "Þifre: ";
	cin >> loginModel.Password;

	return customerController.LoginPost(loginModel);
}