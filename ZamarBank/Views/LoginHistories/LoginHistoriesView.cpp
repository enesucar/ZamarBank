#include "LoginHistoriesView.h"

void LoginHistoriesView(vector<LoginHistory> loginHistories, Customer customer, string message) {
	_PartialHeaderView(customer, message);
	

	cout << left << setw(10) << "ID" << left << setw(30)
		<< "Giriþ Baþarý Durumu" << left << setw(30) << "Tarih ve Saat" << endl;

	for (LoginHistory loginHistory : loginHistories)
	{
		string isLoginStatus = (loginHistory.IsLoginSuccessful) ? "Baþarýlý" : "Baþarsýz";
		cout << left << setw(10) << loginHistory.ID << left << setw(30)
			 << isLoginStatus << left << setw(30) << loginHistory.CreateDate << endl;
	}
	
	int choice;
	cout << endl <<"Geri dönmek için önce 0 tuþuna ardýndan enter tuþuna basýnýz: ";
	cin >> choice;

	if (choice == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}