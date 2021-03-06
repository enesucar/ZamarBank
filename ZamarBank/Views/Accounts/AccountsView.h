#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "../../Controllers/ProcessController.h"
#include "../Shared/Partials/_Header.h"
#include "../../Data/Models/Account.h"

using namespace std;

void AccountsView(vector<Account> accounts, Customer customer, string message = "");