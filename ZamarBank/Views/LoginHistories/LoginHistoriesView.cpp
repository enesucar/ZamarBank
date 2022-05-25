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
	cout << "Geri dönmek için önce 0 tuþuna ardýndan enter tuþuna basýnýz." << endl;
	cin >> choise;

	if (choise == 0)
	{
		ProcessController processController;
		return processController.ProcessGet(customer);
	}
}