#include "DepositView.h"

void DepositView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionAddModel model;
	model.Type = TransactionType::Deposit;

	cout << "Yatýrmak istediðiniz miktar: ";
	cin >> model.Balance;

	cout << "Yatýrmak istediðiniz hesabýn ID'si: ";
	cin >> model.FromAccountID;

	cout << "Açýklama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}