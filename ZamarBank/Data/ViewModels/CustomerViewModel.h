#pragma once
#include <string>

class CustomerLoginModel {
	public:
		string IdentificationNumber;
		string Password;
};

class CustomerRegisterModel
{
	public:
		string FirstName;
		string LastName;
		string IdentificationNumber;
		string Password;
		string PasswordAgain;
};