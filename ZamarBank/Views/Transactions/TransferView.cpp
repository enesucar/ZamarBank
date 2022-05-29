#include "TransferView.h"

void TransferView(Customer customer, string message) {
	_PartialHeaderView(customer, message);

	TransactionAddModel model;
	model.Type = TransactionType::Transfer;

	cout << "Göndermek istediðiniz miktar: ";
	cin >> model.Balance;

	cout << "Hesap ID'sini giriniz: ";
	cin >> model.FromAccountID;

	cout << "Para göndermek istediðiniz hesabýn IBAN adresi: ";
	getline(std::cin >> ws, model.ToAccountIBAN);

	cout << "Açýklama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}