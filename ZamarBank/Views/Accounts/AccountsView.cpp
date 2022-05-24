#include "AccountsView.h"

void AccountsView(vector<Account> accounts, Customer customer, string message) {
	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	if (accounts.size() == 0)
	{
		cout << "Banka hesab�n�za ait mevduat hesab� bulunmamaktad�r.";
	}
	else
	{
		for (Account account : accounts)
		{
			cout << account.ID << " " << (int)account.Type << " " << account.Balance << " " << account.IBAN << endl;
		}
	}

	int choise;
	cout << "Geri d�nmek i�in �nce 0 tu�una ard�ndan enter tu�una bas�n�z." << endl;
	cin >> choise;

	if (choise == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}