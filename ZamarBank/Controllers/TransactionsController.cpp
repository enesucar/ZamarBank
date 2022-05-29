#include "TransactionsController.h"

void TransactionsController::TransactionsGet(int accountID, Customer customer, string message) {
	Account account = AccountAccess::GetByAccountID(accountID);

	if (account.CustomerID != customer.ID) // kullanýcýya ait olmayan hesap
	{
		vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
		return AccountsView(accounts, customer, "ID'yi yanlýþ girdiniz.");
	}

	vector<Transaction> transactions = TransactionAccess::GetListByAccountID(accountID);
	return TransactionsView(transactions, customer, message);
}

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

void TransactionsController::CreateTransactionPdfGet(int transactionID, Customer customer, string message)
{
	Transaction transaction = TransactionAccess::GetByTransactionID(transactionID);
	Account fromAccount = AccountAccess::GetByAccountID(transaction.FromAccountID);
	Account toAccount = AccountAccess::GetByAccountID(transaction.ToAccountID);

	if (fromAccount.CustomerID != customer.ID && toAccount.CustomerID != customer.ID) // kullanýcýya ait olmayan hesap
	{
		AccountsController accountsController;
		return accountsController.AccountsGet(customer, "Hesap hareketleri ID'sini yanlýþ girdiniz.");
	}

	vector<string> text;
	text.push_back("Müsteri Adi ve Soy Adi: " + customer.FirstName + " " + customer.LastName + "\r\n");
	text.push_back("Müsteri Numarasi: " + customer.CustumerNumber + "\r\n");
	text.push_back("Islem Tarihi: " + transaction.CreateDate + "\r\n");
	text.push_back("\r\n");

	if (transaction.Type == TransactionType::Withdraw)
	{
		text.push_back("Islem Tipi: Hesaptan Para Cekme\r\n");
		text.push_back("Para Cekilen Hesabin IBAN Adresi: " + fromAccount.IBAN + "\r\n");
		text.push_back("Cekilen Miktar: " + to_string(transaction.Balance) + "\r\n");
	}
	else if (transaction.Type == TransactionType::Deposit)
	{
		text.push_back("Islem Tipi: Hesaba Para Yukleme\n");
		text.push_back("Para Yatirilan Hesabin IBAN Adresi: " + fromAccount.IBAN + "\r\n");
		text.push_back("Yatirilan Miktar: " + to_string(transaction.Balance) + "\r\n");
	}
	else if (transaction.Type == TransactionType::Transfer)
	{
		text.push_back("Islem Tipi: Baska Bir Hesaba Para Aktarma (EFT)\r\n");
		text.push_back("Para Gönderen Hesabin IBAN Adresi: " + fromAccount.IBAN + "\r\n");
		text.push_back("Para Gönderilen Hesabin IBAN Adresi: " + toAccount.IBAN + "\r\n");
		text.push_back("\r\n");
		text.push_back("Yatirilan Miktar: " + to_string(transaction.Balance) + "\r\n");
	}

	text.push_back("Aciklama: " + transaction.Description + "\r\n");

	PdfFileHelper pdfFileHelper;
	pdfFileHelper.CreatePdfFile(text, "dekont_" + to_string(transaction.ID) + ".pdf");

	if (transaction.Type == TransactionType::Transfer)
	{
		if (fromAccount.CustomerID == customer.ID)
		{
			return TransactionsGet(fromAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
		}
		else
		{
			return TransactionsGet(toAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
		}
	}

	return TransactionsGet(fromAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
}
