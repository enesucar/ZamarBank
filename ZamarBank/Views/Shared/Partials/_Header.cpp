#include "_Header.h"

void _PartialHeaderView() {
	system("cls");
	cout << "**************************" << endl;
	cout << "*****   Zamar Bank   *****" << endl;
	cout << "**************************" << endl;
}

void _PartialHeaderView(Customer customer) {
	system("cls");
	cout << "****************" << endl;
	cout << "**   Zamar Bank" << " -- " << customer.FirstName << " " << customer.LastName << " **" << endl;
	cout << "****************" << endl;
}