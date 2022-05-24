#include "ProcessView.h"

void ProcessView(string message) {
	int choise;

	_PartialHeaderView();

	if (message != "")
	{
		cout << "!!!!!!" << message << "!!!!!!" << endl;
	}

	cout << "1: Hesaplarým" << endl;
	cout << "2: Hesap Oluþtur" << endl;
	cout << "3: Para Transferi" << endl;
	cout << "4: Para Çekme" << endl;
	cout << "5: Para Yatýrma" << endl;
	cout << "6: Þifre Deðiþtir" << endl;
	cout << "7: Çýkýþ" << endl;
	cout << "\nSeçiminiz: ";
	cin >> choise;

	if (true)
	{

	}
	else if (choise == 7)
	{
		HomeController homeController;
		return homeController.HomeGet();
	}
	

	//return customerController.LoginPost(loginModel);
}