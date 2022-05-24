#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/DateTime/DateTime.h"
#include "../Models/LoginHistory.h"

class LoginHistoryAccess
{
	public:
		static int Add(LoginHistory model);
};