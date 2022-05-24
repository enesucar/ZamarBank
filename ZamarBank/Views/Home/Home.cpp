#include "Home.h"

void HomeView(string message) {
	CustomersController customerController;
	int choise;

	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!" << message << "!!!!!" << endl;
	}

	cout << "1: Kullanýcý giriþi" << endl;
	cout << "2: Kullanýcý kaydý" << endl;
	cout << "3: Þifremi unuttum" << endl;
	cout << "\nSeçiminiz: ";

	cin >> choise;

	if (choise == 1)
	{
		return customerController.LoginGet();
	}
	else if (choise == 2)
	{
		return customerController.RegisterGet();
	}
	else if (choise == 3)
	{
		return customerController.ChangePasswordGet();
	}
}