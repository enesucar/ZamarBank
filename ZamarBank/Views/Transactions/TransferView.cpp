#include "TransferView.h"

void TransferView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionViewModel model;
	model.Type = TransactionType::Transfer;

	cout << "Yatýrmak istediðiniz miktar: ";
	cin >> model.Balance;

	cout << "Hesap ID'sini giriniz: ";
	cin >> model.FromAccountID;

	cout << "Yatýrmak istediðiniz hesabýn IBAN adresi: ";
	getline(std::cin >> ws, model.ToAccountIBAN);

	cout << "Açýklama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}