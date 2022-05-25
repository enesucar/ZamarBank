#include "LoginHistoryAccess.h"

vector<LoginHistory> LoginHistoryAccess::GetListByCustomerID(int customerID)
{
	vector<LoginHistory> loginHistories;

	const char* path = Database::GetDatabaseFolderPath();
	sqlite3_stmt* stmt;
	sqlite3* DB;

	sqlite3_open(path, &DB);

	string sql = "Select * From LoginHistory Where CustomerID = " + to_string(customerID);
	int rc = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		LoginHistory loginHistory;
		loginHistory.ID = sqlite3_column_int(stmt, 0);
		loginHistory.CustomerID = customerID;
		loginHistory.IsLoginSuccessful = sqlite3_column_int(stmt, 2);
		loginHistory.CreateDate = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		loginHistories.push_back(loginHistory);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return loginHistories;
}

int LoginHistoryAccess::Add(LoginHistory model)
{
	string createDate = DateTimeHelper::GetCurrentDateTime();

	string sql = "Insert Into LoginHistory (CustomerID, IsLoginSuccessful, CreateDate) ";
	sql += "Values(" + to_string(model.CustomerID) + ", " + to_string(model.IsLoginSuccessful) + ", '" + createDate + "');";

	int result = Database::ExecuteSQL(sql);
	return result;
}
