/*
Enes Uçar 21040101029
Mühendislik Fakültesi - Bilgisayar Mühendisliði Bölümü - 1. Sýnýf 2. Dönem
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
	setlocale(LC_ALL, "Turkish"); // Türkçe karakterlere izin ver

	Application app;
	app.Run();
}