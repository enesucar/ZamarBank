#pragma once
#include "../../Controllers/ProcessController.h"
#include "../Shared/Partials/_Header.h"
#include "../../Data/Models/Account.h"
#include <string>
#include <vector>

using namespace std;

void AccountsView(vector<Account> accounts, Customer customer, string message = "");