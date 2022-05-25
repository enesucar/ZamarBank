#include "AddAccountView.h"

void AddAccountView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	int choice;

	cout << "1: TL Hesabý" << endl;
	cout << "2: Dolar Hesabý" << endl;
	cout << "3: Euro Hesabý" << endl;
	cout << "4: Altýn Hesabý" << endl;
	cout << "Seçiminiz: ";
	cin >> choice;

	AccountType type = (AccountType)(choice - 1);
	AccountsController accountsController;
	return accountsController.AddAccountPost(type, customer);
}