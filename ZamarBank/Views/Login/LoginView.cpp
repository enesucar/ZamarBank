#include "LoginView.h"

void LoginView(string message) {
	_PartialHeaderView();

	CustomerLoginViewModel loginModel;
	CustomersController customerController;

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "TC Kimlik Numarasý: ";
	cin >> loginModel.IdentificationNumber;

	cout << "Þifreniz: ";
	cin >> loginModel.Password;

	return customerController.LoginPost(loginModel);
}