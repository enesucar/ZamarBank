#include "ProcessView.h"

void ProcessView(Customer customer, string message) {
	int choise;

	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "1: Hesaplarým" << endl;
	cout << "2: Hesap Oluþtur" << endl;
	cout << "3: Para Transferi" << endl;
	cout << "4: Para Çekme" << endl;
	cout << "5: Para Yatýrma" << endl;
	cout << "6: Giriþ Kayýtlarým" << endl;
	cout << "7: Þifre Deðiþtir" << endl;
	cout << "8: Çýkýþ" << endl;
	cout << "\nSeçiminiz: ";
	cin >> choise;

	if (choise == 1)
	{
		AccountsController accountsController;
		accountsController.AccountsGet(customer);
	}
	else if (choise == 2)
	{
		AccountsController accountsController;
		accountsController.AddAccountGet(customer);
	}
	else if (choise == 6)
	{
		CustomersController customerController;
		customerController.LoginHistoryGet(customer);
	}
	else if (choise == 8)
	{
		HomeController homeController;
		return homeController.HomeGet();
	}
}