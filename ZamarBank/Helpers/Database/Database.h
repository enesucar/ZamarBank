#pragma once
#include <string>
#include "sqlite3.h"

using namespace std;

class Database
{
	public:
		static int ExecuteSQL(string sql);
		static const char* GetDatabaseFolderPath();
};