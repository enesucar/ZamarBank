#pragma once
#include <string>

using namespace std;

class CustomerLoginViewModel {
	public:
		string Number; // this is IdentificationNumber or CustomerNumber
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

class CustomerChangePasswordViewModel {

};
