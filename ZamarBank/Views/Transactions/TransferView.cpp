#include "TransferView.h"

void TransferView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionAddModel model;
	model.Type = TransactionType::Transfer;

	cout << "G�ndermek istedi�iniz miktar: ";
	cin >> model.Balance;

	cout << "Hesap ID'sini giriniz: ";
	cin >> model.FromAccountID;

	cout << "Para g�ndermek istedi�iniz hesab�n IBAN adresi: ";
	getline(std::cin >> ws, model.ToAccountIBAN);

	cout << "A��klama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}