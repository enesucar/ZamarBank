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
		static Customer GetByID(int ID);
		static Customer GetByIdentificationNumber(string identificationNumber);
		static int Add(CustomerRegisterViewModel model);
};