#include "WithdrawView.h"

void WithdrawView(Customer customer, string message) {
	_PartialHeaderView(customer);

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	TransactionViewModel model;
	model.Type = TransactionType::Withdraw;

	cout << "Çekmek istediðiniz miktar: ";
	cin >> model.Balance;

	cout << "Çekmek istediðiniz hesabýn ID'si: ";
	cin >> model.FromAccountID;

	cout << "Açýklama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}