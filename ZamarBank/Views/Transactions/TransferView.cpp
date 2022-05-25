#include "TransferView.h"

void TransferView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionViewModel model;
	model.Type = TransactionType::Transfer;

	cout << "Yat�rmak istedi�iniz miktar: ";
	cin >> model.Balance;

	cout << "Hesap ID'sini giriniz: ";
	cin >> model.FromAccountID;

	cout << "Yat�rmak istedi�iniz hesab�n IBAN adresi: ";
	getline(std::cin >> ws, model.ToAccountIBAN);

	cout << "A��klama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}