#include "TransactionsController.h"

void TransactionsController::AddTransactionGet(TransactionType type, Customer customer, string message) {
	if (type == TransactionType::Deposit)
	{
		return DepositView(customer, message);
	}
	else if (type == TransactionType::Withdraw)
	{
		return WithdrawView(customer, message);
	}
	else if (type == TransactionType::Transfer)
	{
		return TransferView(customer, message);
	}
}

void TransactionsController::AddTransactionPost(TransactionAddModel model, Customer customer, string message) {
	Account fromAccount = AccountAccess::GetByAccountID(model.FromAccountID);
	
	if (fromAccount.CustomerID != customer.ID) // kullan�c�ya ait olmayan hesap veya yanl�� girilen hesap ID
	{
		return AddTransactionGet(model.Type, customer, "L�tfen ge�erli bir hesap ID'si giriniz.");
	}
	
	if (model.Type == TransactionType::Withdraw)
	{
		if (fromAccount.Balance < model.Balance) // hesab�nda bulunan paradan fazlas�na �ekmek isterse
		{
			return AddTransactionGet(model.Type, customer, "Hesab�n�zda yeterli miktarda para bulunmamaktad�r.");
		}
	}
	else if (model.Type == TransactionType::Transfer)
	{
		Account toAccount = AccountAccess::GetByIBAN(model.ToAccountIBAN);

		if (fromAccount.Type != toAccount.Type) // Para g�nderece�i hesap tipi ayn� olmal�.
		{
			return AddTransactionGet(model.Type, customer, "Para g�nderece�iniz hesab�n tipi sizin hesab�n�zla ayn� olmal�d�r.");
		}
		else if (toAccount.ID == 0) // Para aktar�lacak hesap bulunamad�.
		{
			return AddTransactionGet(model.Type, customer, "Para aktar�lacak hesap bulunamad�.");
		}
		else if (fromAccount.Balance < model.Balance) // Hesab�nda bulunan paradan fazlas�n� g�nderemez.
		{
			return AddTransactionGet(model.Type, customer, "Hesab�n�zdaki yeterli miktarda para bulunmamaktad�r.");
		}
	}

	TransactionAccess::Add(model);
	
	ProcessController processController;
	return processController.ProcessGet(customer, "��lem ba�ar�yla ger�ekle�ti!");

}