#include "AccountActivities.h"

void AccountActivitiesView(vector<Transaction> transactions, Customer customer, string message) {
	_PartialHeaderView(customer, message);

	if (transactions.size() == 0)
	{
		cout << "Mesaj: Hesab�n�za ait i�lem ge�mi�i bulunamad�.";
	}
	else
	{
		cout << left << setw(10) << "ID" << left << setw(30)
			 << "��lem Tipi" << left << setw(30) << "Bakiye" << left << setw(50) << "IBAN" << endl;
	
		for (Transaction transaction : transactions)
		{
			Account fromAccount = AccountAccess::GetByID(transaction.FromAccountID);
			Account toAccount = AccountAccess::GetByID(transaction.ToAccountID);

			string transactionType = TransactionTypeToString(transaction.Type);
			string balance = "";
			string IBAN;

			if (transaction.Type == TransactionType::Transfer)
			{
				if (transaction.FromAccountID == customer.ID) // paray� kullan�c� g�nderdi
				{
					balance = "-" + to_string(transaction.Balance);
					IBAN = toAccount.IBAN;
				}
				else // kullan�c�n�n hesab�na para yatt�
				{
					balance = "+" + to_string(transaction.Balance);
					IBAN = fromAccount.IBAN;
				}
			}
			else if (transaction.Type == TransactionType::Deposit)
			{
				balance = "+" + to_string(transaction.Balance);
			}
			else if (transaction.Type == TransactionType::Withdraw)
			{
				balance = "-" + to_string(transaction.Balance);
			}

			cout << left << setw(10) << transaction.ID << left << setw(30)
				 << transactionType << left << setw(30) << balance
				 << left << setw(50) << IBAN << endl;
		}
	}

	int choice;
	cout << endl << endl << "Geri d�nmek i�in �nce 0 ard�ndan enter tu�unsa bas�n�z. ";
	cin >> choice;

	if (choice == 0)
	{
		AccountsController accountsController;
		return accountsController.AccountsGet(customer);
	}
}