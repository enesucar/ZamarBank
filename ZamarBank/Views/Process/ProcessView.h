#pragma once
#include <string>
#include <iomanip>
#include "../Shared/Partials/_Header.h"
#include "../../Controllers/ProcessController.h"
#include "../../Controllers/HomeController.h"
#include "../../Controllers/AccountsController.h"
#include "../../Controllers/TransactionsController.h"

using namespace std;

void ProcessView(Customer customer, string message = "");