#include "AccountAccess.h"

vector<Account> AccountAccess::GetListByCustomerID(int customerID)
{
	vector<Account> accounts;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From Account Where CustomerID = " + to_string(customerID) + " And IsDeleted = 0";
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		Account account;
		account.ID = sqlite3_column_int(stmt, 0);
		account.CustomerID = customerID;
		account.Type = (AccountType)sqlite3_column_int(stmt, 2);
		account.IBAN = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		account.Balance = sqlite3_column_double(stmt, 4);
		account.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		account.IsDeleted = sqlite3_column_int(stmt, 6);
		accounts.push_back(account);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return accounts;
}

int AccountAccess::Add(AccountType type, int customerID) {
	Account account;
	account.CustomerID = customerID;
	account.Type = type;
	account.IBAN = "TR" + RandomHelper::GenerateRandomNumbers(2) + " " + RandomHelper::GenerateRandomNumbers(4) 
						+ " " + RandomHelper::GenerateRandomNumbers(4) + " " + RandomHelper::GenerateRandomNumbers(4) 
						+ " " + RandomHelper::GenerateRandomNumbers(4) + " " + RandomHelper::GenerateRandomNumbers(2);
	account.Balance = 0;
	account.CreateDate = DateTimeHelper::GetCurrentDateTime();
	account.IsDeleted = 0;

	//Balance'ý stringe çevirdiðimizde virgüllü oluyor. (Örn: 15,5600) Bu yüzden sql sorgusunun çalýþmamasýna neden oluyor.
	string accountBalanceString = to_string(account.Balance);
	accountBalanceString = StringHelper::ReplaceAll(accountBalanceString, ",", ".");

	//string veri tipi baþka herhangi bir tiple  toplanmýyor. Bu nedenle tüm deðikenleri to_string() metodu ile stringe çevirmek zorundayýz.
	string sql = "Insert Into Account (CustomerID, Type, IBAN, Balance, CreateDate, IsDeleted) ";
	sql += "Values(" + to_string(account.CustomerID) + ", " + to_string((int)account.Type) + ", '" 
		+ account.IBAN + "', " + accountBalanceString + ", '" + account.CreateDate + "', " 
		+ to_string(account.IsDeleted) + ");";

	int result = Database::ExecuteSQL(sql);
	return result;
}
