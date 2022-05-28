#include "AccountsController.h"

void AccountsController::AccountsGet(Customer customer, string message)
{
	vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
	return AccountsView(accounts, customer, message);
}

void AccountsController::AddAccountGet(Customer customer, string message)
{
	return AddAccountView(customer, message);
}

void AccountsController::AddAccountPost(AccountType type, Customer customer, string message)
{
	AccountAccess::Add(type, customer.ID);

	ProcessController processController;
	return processController.ProcessGet(customer, "Hesap baþarýyla oluþturuldu.");
}

void AccountsController::AccountActivitiesGet(int accountID, Customer customer, string message) {
	Account account = AccountAccess::GetByAccountID(accountID);

	if (account.CustomerID != customer.ID) // kullanýcýya ait olmayan hesap
	{	
		vector<Account> accounts = AccountAccess::GetListByCustomerID(customer.ID);
		return AccountsView(accounts, customer, "ID'yi yanlýþ girdiniz.");
	}

	vector<Transaction> transactions = TransactionAccess::GetListByAccountID(accountID);
	return AccountActivitiesView(transactions, customer, message);
}

void AccountsController::CreateAccountActivityPdfGet(int transactionID, Customer customer, string message)
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
			return AccountActivitiesGet(fromAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
		}
		else
		{
			return AccountActivitiesGet(toAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
		}
	}

	return AccountActivitiesGet(fromAccount.ID, customer, "Dekont masaüstüne baþarýyla oluþturuldu.");
}
