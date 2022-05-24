#include "LoginView.h"

void LoginView(string message) {
	_PartialHeaderView();

	CustomerLoginViewModel loginModel;
	CustomersController customerController;

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "TC Kimlik Numaras�: ";
	cin >> loginModel.IdentificationNumber;

	cout << "�ifreniz: ";
	cin >> loginModel.Password;

	return customerController.LoginPost(loginModel);
}