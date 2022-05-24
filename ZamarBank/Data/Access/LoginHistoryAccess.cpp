#include "LoginHistoryAccess.h"

int LoginHistoryAccess::Add(LoginHistory model)
{
	string createDate = DateTimeHelper::GetCurrentDateTime();

	string sql = "Insert Into LoginHistory (CustomerID, IsLoginSuccessful, CreateDate) ";
	sql += "Values(" + to_string(model.CustomerID) + ", " + to_string(model.IsLoginSuccessful) + ", '" + createDate + "');";

	int result = Database::ExecuteSQL(sql);
	return result;
}

