#include "TransferView.h"

void TransferView(Customer customer, string message) {
	_PartialHeaderView(customer);

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	TransactionViewModel model;
	model.Type = TransactionType::Transfer;

	cout << "Yat�rmak istedi�iniz miktar: ";
	cin >> model.Balance;

	cout << "Hesab ID'sini giriniz: ";
	cin >> model.FromAccountID;

	cout << "Yat�rmak istedi�iniz hesab�n IBAN adresi: ";
	getline(std::cin >> ws, model.ToAccountIBAN);

	cout << "A��klama: ";
	getline(std::cin >> ws, model.Description);

	TransactionsController transactionsController;
	transactionsController.AddTransactionPost(model, customer);
}