#include "WithdrawView.h"

void WithdrawView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionViewModel model;
	model.Type = TransactionType::Withdraw;

	cout << "�ekmek istedi�iniz miktar: ";
	cin >> model.Balance;

	cout << "�ekmek istedi�iniz hesab�n ID'si: ";
	cin >> model.FromAccountID;

	cout << "A��klama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}