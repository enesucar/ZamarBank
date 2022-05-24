#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Models/Customer.h"
#include "../ViewModels/CustomerViewModel.h"
#include "../../Helpers/Database/Database.h"
#include "../../Helpers/Random/Random.h"
#include "../../Helpers/DateTime/DateTime.h"

class CustomerAccess
{
	public:
		static Customer Get(int ID);
		static Customer GetByIdentificationNumber(string identificationNumber);
		static vector<Customer> GetList();
		static int Add(CustomerRegisterViewModel model);
};