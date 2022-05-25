#include "ProcessView.h"

void ProcessView(Customer customer, string message) {
	int choise;

	_PartialHeaderView(customer);

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "1: Hesaplar�m" << endl;
	cout << "2: Hesap Olu�tur" << endl;
	cout << "3: Para Transferi" << endl;
	cout << "4: Para �ekme" << endl;
	cout << "5: Para Yat�rma" << endl;
	cout << "6: Giri� Kay�tlar�m" << endl;
	cout << "7: �ifre De�i�tir" << endl;
	cout << "8: ��k��" << endl;
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
	else if (choise == 3)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Transfer, customer);
	}
	else if (choise == 4)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Withdraw, customer);
	}
	else if (choise == 5)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Deposit, customer);
	}
	else if (choise == 6)
	{
		CustomersController customersController;
		customersController.LoginHistoryGet(customer);
	}
	else if (choise == 8)
	{
		HomeController homeController;
		return homeController.HomeGet();
	}
}