#include "Home.h"

void HomeView(string message) {
	_PartialHeaderView(message);
	
	CustomersController customerController;
	int choice;

	cout << "1: Müþteri giriþi" << endl;
	cout << "2: Müþteri kaydý" << endl;
	cout << "3: Uygulamayý kapat" << endl;
	cout << "\nSeçiminiz: ";

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
		return HomeView("Lütfen geçerli bir rakam giriniz.");
	}
}