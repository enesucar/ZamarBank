#include "ProcessView.h"

void ProcessView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	int choice;

	cout << "1: Hesaplarým" << endl;
	cout << "2: Hesap Oluþtur" << endl;
	cout << "3: Para Transferi" << endl;
	cout << "4: Para Çekme" << endl;
	cout << "5: Para Yatýrma" << endl;
	cout << "6: Giriþ Kayýtlarým" << endl;
	cout << "7: Çýkýþ" << endl;
	cout << "\nSeçiminiz: ";
	cin >> choice;

	if (choice == 1)
	{
		AccountsController accountsController;
		accountsController.AccountsGet(customer);
	}
	else if (choice == 2)
	{
		AccountsController accountsController;
		accountsController.AddAccountGet(customer);
	}
	else if (choice == 3)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Transfer, customer);
	}
	else if (choice == 4)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Withdraw, customer);
	}
	else if (choice == 5)
	{
		TransactionsController transactionsController;
		transactionsController.AddTransactionGet(TransactionType::Deposit, customer);
	}
	else if (choice == 6)
	{
		CustomersController customersController;
		customersController.LoginHistoryGet(customer);
	}
	else if (choice == 7)
	{
		HomeController homeController;
		return homeController.HomeGet();
	}
	else
	{
		ProcessController processController;
		processController.ProcessGet(customer, "Lütfen geçerli bir rakam giriniz.");
	}
}