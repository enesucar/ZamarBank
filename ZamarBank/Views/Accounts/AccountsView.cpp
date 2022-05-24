#include "AccountsView.h"

void AccountsView(vector<Account> accounts, Customer customer, string message) {
	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	if (accounts.size() == 0)
	{
		cout << "Banka hesabýnýza ait mevduat hesabý bulunmamaktadýr.";
	}
	else
	{
		for (Account account : accounts)
		{
			cout << account.ID << " " << (int)account.Type << " " << account.Balance << " " << account.IBAN << endl;
		}
	}

	int choise;
	cout << "Geri dönmek için önce 0 tuþuna ardýndan enter tuþuna basýnýz." << endl;
	cin >> choise;

	if (choise == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}