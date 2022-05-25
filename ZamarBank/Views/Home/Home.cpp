#include "Home.h"

void HomeView(string message) {
	_PartialHeaderView(message);
	
	CustomersController customerController;
	int choice;

	cout << "1: M��teri giri�i" << endl;
	cout << "2: M��teri kayd�" << endl;
	cout << "3: Uygulamay� kapat" << endl;
	cout << "\nSe�iminiz: ";

	cin >> choice;

	if (choice == 1)
	{
		return customerController.LoginGet();
	}
	else if (choice == 2)
	{
		return customerController.RegisterGet();
	}
	else if (choice == 3)
	{
		exit(0);
	}
	else
	{
		return HomeView("L�tfen ge�erli bir rakam giriniz.");
	}
}