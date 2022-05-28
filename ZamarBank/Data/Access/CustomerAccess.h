#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Models/Customer.h"
#include "../Models/LoginHistory.h"
#include "../ViewModels/CustomerViewModel.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/Random/Random.h"
#include "../../Helpers/DateTime/DateTime.h"

class CustomerAccess
{
	public:
		static Customer GetByCustomerID(int customerID);
		static Customer GetByIdentificationNumber(string identificationNumber);
		static void Add(CustomerRegisterModel model);
};