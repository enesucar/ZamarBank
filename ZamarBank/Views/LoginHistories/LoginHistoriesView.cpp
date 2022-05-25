#include "LoginHistoriesView.h"

void LoginHistoriesView(vector<LoginHistory> loginHistories, Customer customer, string message) {
	_PartialHeaderView(customer, message);
	

	cout << left << setw(10) << "ID" << left << setw(30)
		<< "Giri� Ba�ar� Durumu" << left << setw(30) << "Tarih ve Saat" << endl;

	for (LoginHistory loginHistory : loginHistories)
	{
		string isLoginStatus = (loginHistory.IsLoginSuccessful) ? "Ba�ar�l�" : "Ba�ars�z";
		cout << left << setw(10) << loginHistory.ID << left << setw(30)
			 << isLoginStatus << left << setw(30) << loginHistory.CreateDate << endl;
	}
	
	int choice;
	cout << endl <<"Geri d�nmek i�in �nce 0 tu�una ard�ndan enter tu�una bas�n�z: ";
	cin >> choice;

	if (choice == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}