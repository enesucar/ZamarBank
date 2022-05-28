#include "DepositView.h"

void DepositView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionAddModel model;
	model.Type = TransactionType::Deposit;

	cout << "Yat�rmak istedi�iniz miktar: ";
	cin >> model.Balance;

	cout << "Yat�rmak istedi�iniz hesab�n ID'si: ";
	cin >> model.FromAccountID;

	cout << "A��klama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}