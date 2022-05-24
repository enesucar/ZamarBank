#include "ProcessView.h"

void ProcessView(Customer customer, string message) {
	int choise;

	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "1: Hesaplar�m" << endl;
	cout << "2: Hesap Olu�tur" << endl;
	cout << "3: Para Transferi" << endl;
	cout << "4: Para �ekme" << endl;
	cout << "5: Para Yat�rma" << endl;
	cout << "6: �ifre De�i�tir" << endl;
	cout << "7: ��k��" << endl;
	cout << "\nSe�iminiz: ";
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
	else if (choise == 7)
	{
		HomeController homeController;
		return homeController.HomeGet();
	}
}