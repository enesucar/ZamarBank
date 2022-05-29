#include "TransactionsController.h"

void TransactionsController::TransactionsGet(int accountID, Customer customer, string message) {
	Account account = AccountAccess::GetByAccountID(accountID);

	if (account.CustomerID != customer.ID) // kullan�c�ya ait olmayan hesap
	{
		vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
		return AccountsView(accounts, customer, "ID'yi yanl�� girdiniz.");
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

void TransactionsController::CreateTransactionPdfGet(int transactionID, Customer customer, string message)
{
	Transaction transaction = TransactionAccess::GetByTransactionID(transactionID);
	Account fromAccount = AccountAccess::GetByAccountID(transaction.FromAccountID);
	Account toAccount = AccountAccess::GetByAccountID(transaction.ToAccountID);

	if (fromAccount.CustomerID != customer.ID && toAccount.CustomerID != customer.ID) // kullan�c�ya ait olmayan hesap
	{
		AccountsController accountsController;
		return accountsController.AccountsGet(customer, "Hesap hareketleri ID'sini yanl�� girdiniz.");
	}

	vector<string> text;
	text.push_back("M�steri Adi ve Soy Adi: " + customer.FirstName + " " + customer.LastName + "\r\n");
	text.push_back("M�steri Numarasi: " + customer.CustumerNumber + "\r\n");
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
		text.push_back("Para G�nderen Hesabin IBAN Adresi: " + fromAccount.IBAN + "\r\n");
		text.push_back("Para G�nderilen Hesabin IBAN Adresi: " + toAccount.IBAN + "\r\n");
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
			return TransactionsGet(fromAccount.ID, customer, "Dekont masa�st�ne ba�ar�yla olu�turuldu.");
		}
		else
		{
			return TransactionsGet(toAccount.ID, customer, "Dekont masa�st�ne ba�ar�yla olu�turuldu.");
		}
	}

	return TransactionsGet(fromAccount.ID, customer, "Dekont masa�st�ne ba�ar�yla olu�turuldu.");
}
