#include "ProcessView.h"

void ProcessView(Customer customer, string message) {
	int choise;

	_PartialHeaderView(customer);

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