/*
Enes U�ar 21040101029
M�hendislik Fak�ltesi - Bilgisayar M�hendisli�i B�l�m� - 1. S�n�f 2. D�nem
26.05.2022
*/

#include <iostream>
#include <locale.h>
#include "Views/Shared/Partials/_Header.h"
#include "Controllers/HomeController.h"

using namespace std;

class Application
{
	public:
		void Run() {
			HomeController homeController;
			homeController.HomeGet();
		}
};

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Turkish"); // T�rk�e karakterlere izin ver

	Application app;
	app.Run();
}