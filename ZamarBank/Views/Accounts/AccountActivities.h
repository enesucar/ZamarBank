#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "../../Controllers/ProcessController.h"
#include "../Shared/Partials/_Header.h"
#include "../../Data/Models/Account.h"
#include "../../Data/Models/Transaction.h"

using namespace std;

void AccountActivitiesView(vector<Transaction>, Customer customer, string message = "");