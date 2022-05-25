#include "AddAccountView.h"

void AddAccountView(Customer customer, string message) {
	int choice;

	_PartialHeaderView(customer, message);

	cout << "1: TL Hesab�" << endl;
	cout << "2: Dolar Hesab�" << endl;
	cout << "3: Euro Hesab�" << endl;
	cout << "4: Alt�n Hesab�" << endl;
	cout << "Se�iminiz: ";
	cin >> choice;

	AccountType type = (AccountType)(choice - 1);
	AccountsController accountsController;
	return accountsController.AddAccountPost(type, customer);
}