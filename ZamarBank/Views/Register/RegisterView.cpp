#include "RegisterView.h"

void RegisterView(string message) {
	_PartialHeaderView(message);

	CustomerRegisterViewModel registerModel;
	CustomersController customerController;

	cout << "Ýsim: ";
	cin >> registerModel.FirstName;

	cout << "Soy isim: ";
	cin >> registerModel.LastName;
	
	cout << "TC Kimlik Numarasý: ";
	cin >> registerModel.IdentificationNumber;

	cout << "Þifre: ";
	cin >> registerModel.Password;

	cout << "Sifre Tekrar: ";
	cin >> registerModel.PasswordAgain;

	return customerController.RegisterPost(registerModel);
}