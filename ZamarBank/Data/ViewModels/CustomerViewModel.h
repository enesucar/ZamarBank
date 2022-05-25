#pragma once
#include <string>

using namespace std;

class CustomerLoginViewModel {
	public:
		string IdentificationNumber;
		string Password;
};

class CustomerRegisterViewModel
{
	public:
		string FirstName;
		string LastName;
		string IdentificationNumber;
		string Password;
		string PasswordAgain;
};