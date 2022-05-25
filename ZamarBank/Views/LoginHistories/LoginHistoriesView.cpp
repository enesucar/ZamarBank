#include "LoginHistoriesView.h"

void LoginHistoriesView(vector<LoginHistory> loginHistories, Customer customer, string message) {
	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}
	
	for (LoginHistory loginHistory : loginHistories)
	{
		cout << loginHistory.ID << " " << loginHistory.IsLoginSuccessful << " " << loginHistory.CreateDate << endl;
	}
	
	int choise;
	cout << "Geri d�nmek i�in �nce 0 tu�una ard�ndan enter tu�una bas�n�z." << endl;
	cin >> choise;

	if (choise == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}