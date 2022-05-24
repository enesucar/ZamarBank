#include "CustomerAccess.h"

Customer CustomerAccess::Get(int ID)
{
	Customer customer;
	return customer;
}

Customer CustomerAccess::GetByIdentificationNumber(string identificationNumber)
{
	Customer customer;
	return customer;
}

vector<Customer> CustomerAccess::GetList()
{
	return vector<Customer>();
}

void CustomerAccess::Add(CustomerRegisterViewModel model)
{
	string customerNumber = RandomHelper::GenerateRandomNumbers(8);
	string createDate = DateTimeHelper::GetCurrentDateTime();
	int isDeleted = 0;

	string sql = "Insert Into Customer (FirstName, LastName, IdentificationNumber, CustomerNumber, Password, CreateDate, IsDeleted) ";
	sql += "Values('" + model.FirstName + "', '" + model.LastName + "', '" + model.IdentificationNumber + "', '" + customerNumber + "', " + model.Password + ", '" + createDate + "', " + to_string(isDeleted) + ");";
					
	int result = Database::ExecuteSQL(sql);
	int b = 0;
}
