#include "../Shared/Partials/_Header.h"
#include "../../Controllers/CustomersController.h"
#include "RegisterView.h"

void RegisterView(string message) {
	_PartialHeaderView();

	CustomerRegisterViewModel registerModel;
	CustomersController customerController;
	
	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "Isminiz: ";
	cin >> registerModel.FirstName;

	cout << "Soyisminiz: ";
	cin >> registerModel.LastName;
	
	cout << "Kimlik Numaraniz: ";
	cin >> registerModel.IdentificationNumber;

	cout << "Sifre: ";
	cin >> registerModel.Password;

	cout << "Sifre Tekrar: ";
	cin >> registerModel.PasswordAgain;

	return customerController.RegisterPost(registerModel);
}