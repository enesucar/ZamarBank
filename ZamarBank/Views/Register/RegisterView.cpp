#include "RegisterView.h"

void RegisterView(string message) {
	_PartialHeaderView(message);

	CustomerRegisterViewModel registerModel;
	CustomersController customerController;
	cout << "�ifreniz sadece 6 adet rakamdan olu�mal�d�r.\n�ifreniz 0 ile ba�lamamal�d�r.\n\n";

	cout << "�sim: ";
	cin >> registerModel.FirstName;

	cout << "Soy isim: ";
	cin >> registerModel.LastName;
	
	cout << "TC Kimlik Numaras�: ";
	cin >> registerModel.IdentificationNumber;

	cout << "�ifre: ";
	cin >> registerModel.Password;

	cout << "Sifre Tekrar: ";
	cin >> registerModel.PasswordAgain;

	return customerController.RegisterPost(registerModel);
}