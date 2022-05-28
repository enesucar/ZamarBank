#include "TransactionAccess.h"

Transaction TransactionAccess::GetByTransactionID(int transactionID)
{
	Transaction transaction;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From \"main\".\"Transaction\" Where ID = " + to_string(transactionID);
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		transaction.ID = sqlite3_column_int(stmt, 0);
		transaction.FromAccountID = sqlite3_column_int(stmt, 1);
		transaction.ToAccountID = sqlite3_column_int(stmt, 2);
		transaction.Type = (TransactionType)sqlite3_column_int(stmt, 3);
		transaction.Balance = sqlite3_column_double(stmt, 4);
		transaction.Description = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		transaction.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return transaction;
}

vector<Transaction> TransactionAccess::GetListByAccountID(int accountID)
{
	vector<Transaction> transactions;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From \"main\".\"Transaction\" Where (FromAccountID = " + to_string(accountID) + " Or ToAccountID = " + to_string(accountID) + ")";
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		Transaction transaction;
		transaction.ID = sqlite3_column_int(stmt, 0);
		transaction.FromAccountID = sqlite3_column_int(stmt, 1);
		transaction.ToAccountID = sqlite3_column_int(stmt, 2);
		transaction.Type = (TransactionType)sqlite3_column_int(stmt, 3);
		transaction.Balance = sqlite3_column_double(stmt, 4);
		transaction.Description = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		transaction.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		transactions.push_back(transaction);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return transactions;
}

string TransactionAccess::Add(TransactionViewModel model)
{
	string createDate = DateTimeHelper::GetCurrentDateTime();
	string accountBalanceString = to_string(model.Balance);
	accountBalanceString = StringHelper::ReplaceAll(accountBalanceString, ",", ".");
	string sql = "";

	Account fromAccount = AccountAccess::GetByID(model.FromAccountID);

	if (model.Type == TransactionType::Withdraw)
	{
		if (fromAccount.Balance < model.Balance) // hesabýnda bulunan paradan fazlasýna çekmek isterse
		{
			return "Hesabýnýzdaki yeterli miktarda para bulunmamaktadýr.";
		}

		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance * - 1);
		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	}
	else if (model.Type == TransactionType::Deposit)
	{
		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance);
		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	}
	else if (model.Type == TransactionType::Transfer)
	{
		Account toAccount = AccountAccess::GetByIBAN(model.ToAccountIBAN);

		if (fromAccount.Type != toAccount.Type) // Para göndereceði hesap tipi ayný olmalý.
		{
			return "Para göndereceðiniz hesabýn tipi sizin hesabýnýzla ayný olmalýdýr.";
		}
		if (toAccount.ID == 0) // Para aktarýlacak hesap bulunamadý.
		{
			return "Para aktarýlacak hesap bulunamadý.";
		}
		if (fromAccount.Balance < model.Balance) // Hesabýnda bulunan paradan fazlasýný göndermek isterse
		{
			return "Hesabýnýzdaki yeterli miktarda para bulunmamaktadýr.";
		}

		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance * -1);
		AccountAccess::UpdateBalance(toAccount.ID, model.Balance);

		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, ToAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string(toAccount.ID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	} 

	int result = Database::ExecuteSQL(sql);
	if (result > 0)
	{
		return "1";
	}
	return "Ýþlem gerçekleþtirilemedi.";
}
