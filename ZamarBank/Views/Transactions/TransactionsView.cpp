#include "TransactionsView.h"

void TransactionsView(vector<Transaction> transactions, Customer customer, string message) {
	_PartialHeaderView(customer, message);

	if (transactions.size() == 0)
	{
		cout << "Mesaj: Hesabýnýza ait iþlem geçmiþi bulunamadý.";
	}
	else
	{
		cout << left << setw(10) << "ID" << left << setw(30)
			 << "Ýþlem Tipi" << left << setw(20) << "Bakiye" << left << setw(35) << "IBAN" 
			 << "Açýklama" << endl;
	
		for (Transaction transaction : transactions)
		{
			Account fromAccount = AccountAccess::GetByAccountID(transaction.FromAccountID);
			Account toAccount = AccountAccess::GetByAccountID(transaction.ToAccountID);

			string transactionType = TransactionTypeToString(transaction.Type);
			string balance = "";
			string IBAN;

			if (transaction.Type == TransactionType::Transfer)
			{
				if (fromAccount.CustomerID == customer.ID) // parayý kullanýcý gönderdi
				{
					balance = "-" + to_string(transaction.Balance);
					IBAN = toAccount.IBAN;
				}
				else // kullanýcýnýn hesabýna para yattý
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
				 << transactionType << left << setw(20) << balance
				 << left << setw(35) << IBAN <<	transaction.Description << endl;
		}
	}

	int choice;
	cout << endl << endl << "Geri dönmek isterseniz 0, dekont indirmek isterseniz iþlem ID'sini yazýnýz: ";
	cin >> choice;

	if (choice == 0)
	{
		AccountsController accountsController;
		return accountsController.AccountsGet(customer);
	}
	else
	{
		TransactionsController transactionsController;
		return transactionsController.CreateTransactionPdfGet(choice, customer);
	}
}