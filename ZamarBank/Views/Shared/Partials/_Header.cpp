#include "_Header.h"

void _PartialHeaderView(string message) {
	system("cls"); // Ekrandaki tüm yazıları siler
	cout << "___________________________" << endl << endl;
	cout << "\tZamar Bank" << endl;
	cout << "___________________________" << endl << endl << endl;

	if (message != "")
	{
		cout << "Mesaj: " << message << "" << endl << endl;
	}
}

void _PartialHeaderView(Customer customer, string message) {
	system("cls"); // Ekrandaki tüm yazıları siler
	cout << "___________________________" << endl << endl;
	cout << "\tZamar Bank " << endl;
	cout << "    " << customer.FirstName << " " << customer.LastName << " - " << customer.CustumerNumber << endl;
	cout << "___________________________" << endl << endl << endl;

	if (message != "")
	{
		cout << "Mesaj: " << message << "" << endl << endl;
	}
}