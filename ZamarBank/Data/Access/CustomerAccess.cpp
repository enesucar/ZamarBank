#include "CustomerAccess.h"

Customer CustomerAccess::GetByCustomerID(int customerID)
{
	Customer customer;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From Customer Where ID = "  + to_string(customerID) + " And IsDeleted = 0";
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);
	
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		customer.ID = sqlite3_column_int(stmt, 0);
		customer.FirstName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		customer.LastName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		customer.IdentificationNumber = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		customer.CustumerNumber = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		customer.Password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		customer.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		customer.IsDeleted = sqlite3_column_int(stmt, 7);
	}

	if (customer.FirstName == "")
	{
		customer.ID = 0;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return customer;
}

Customer CustomerAccess::GetByIdentificationNumber(string identificationNumber) 
{
	Customer customer;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From Customer Where IdentificationNumber = '" + identificationNumber + "' And IsDeleted = 0;";
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		customer.ID = sqlite3_column_int(stmt, 0);
		customer.FirstName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		customer.LastName = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		customer.IdentificationNumber = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		customer.CustumerNumber = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		customer.Password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		customer.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		customer.IsDeleted = sqlite3_column_int(stmt, 7);
	}

	if (customer.FirstName == "")
	{
		customer.ID = 0;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return customer;
}

void CustomerAccess::Add(CustomerRegisterModel model)
{
	string customerNumber = RandomHelper::GenerateRandomNumbers(8);
	string createDate = DateTimeHelper::GetCurrentDateTime();
	int isDeleted = 0;

	string sql = "Insert Into Customer (FirstName, LastName, IdentificationNumber, CustomerNumber, Password, CreateDate, IsDeleted) ";
	sql += "Values('" + model.FirstName + "', '" + model.LastName + "', '" + model.IdentificationNumber + "', '" + customerNumber + "', " + model.Password + ", '" + createDate + "', " + to_string(isDeleted) + ");";
					
	Database::ExecuteSQL(sql);
}
