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
	
	if (fromAccount.CustomerID != customer.ID) // kullanýcýya ait olmayan hesap veya yanlýþ girilen hesap ID
	{
		return AddTransactionGet(model.Type, customer, "Lütfen geçerli bir hesap ID'si giriniz.");
	}
	
	if (model.Type == TransactionType::Withdraw)
	{
		if (fromAccount.Balance < model.Balance) // hesabýnda bulunan paradan fazlasýna çekmek isterse
		{
			return AddTransactionGet(model.Type, customer, "Hesabýnýzda yeterli miktarda para bulunmamaktadýr.");
		}
	}
	else if (model.Type == TransactionType::Transfer)
	{
		Account toAccount = AccountAccess::GetByIBAN(model.ToAccountIBAN);

		if (fromAccount.Type != toAccount.Type) // Para göndereceði hesap tipi ayný olmalý.
		{
			return AddTransactionGet(model.Type, customer, "Para göndereceðiniz hesabýn tipi sizin hesabýnýzla ayný olmalýdýr.");
		}
		else if (toAccount.ID == 0) // Para aktarýlacak hesap bulunamadý.
		{
			return AddTransactionGet(model.Type, customer, "Para aktarýlacak hesap bulunamadý.");
		}
		else if (fromAccount.Balance < model.Balance) // Hesabýnda bulunan paradan fazlasýný gönderemez.
		{
			return AddTransactionGet(model.Type, customer, "Hesabýnýzdaki yeterli miktarda para bulunmamaktadýr.");
		}
	}

	TransactionAccess::Add(model);
	
	ProcessController processController;
	return processController.ProcessGet(customer, "Ýþlem baþarýyla gerçekleþti!");

}