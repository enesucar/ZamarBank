#pragma once
#include "../../Controllers/ProcessController.h"
#include "../Shared/Partials/_Header.h"
#include "../../Data/Models/LoginHistory.h"
#include <string>
#include <vector>

using namespace std;

void LoginHistoriesView(vector<LoginHistory> loginHistories, Customer customer, string message = "");