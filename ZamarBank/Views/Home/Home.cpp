#include "Home.h"

void HomeView(string message) {
	CustomersController customerController;
	int choise;

	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!" << message << "!!!!!" << endl;
	}

	cout << "1: Kullan�c� giri�i" << endl;
	cout << "2: Kullan�c� kayd�" << endl;
	cout << "3: �ifremi unuttum" << endl;
	cout << "\nSe�iminiz: ";

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