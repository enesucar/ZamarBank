#include "Database.h"

int Database::ExecuteSQL(string sql) {
	const char* path = GetDatabaseFolderPath();

	sqlite3* DB;
	char* messageError;

	int exit = sqlite3_open(path, &DB);
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	sqlite3_close(DB);

	if (exit != SQLITE_OK) {
		return 0;
	}
	
	return 1;
}

const char* Database::GetDatabaseFolderPath() {
	const char* path = R"(Databases\ZamarBankDB.db)";
	return path;
}