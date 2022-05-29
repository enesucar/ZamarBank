#include "AccountsView.h"

void AccountsView(vector<Account> accounts, Customer customer, string message) {
	_PartialHeaderView(customer, message);

	if (accounts.size() == 0)
	{
		cout << "Banka hesab�n�za ait mevduat hesab� bulunmamaktad�r.";
	}
	else
	{
		cout << left << setw(10) << "ID" << left << setw(20) 
			 << "Hesap Tipi" << left << setw(20) << "Bakiye" << left << setw(40) << "IBAN" << endl;

		for (Account account : accounts)
		{
			cout << left << setw(10) << account.ID << left << setw(20) 
				 << AccountTypeToString(account.Type) << left << setw(20) << account.Balance
				 << left << setw(40) << account.IBAN << endl;
		}
	}

	int choice;
	cout << endl << endl << "Geri d�nmek istersiniz 0, hesap detaylar�n� g�rmek isterseniz hesap ID'sini giriniz: ";
	cin >> choice;

	if (choice == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
	else
	{
		TransactionsController transactionsController;
		return transactionsController.TransactionsGet(choice, customer);
	}
}