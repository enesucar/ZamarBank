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
	setlocale(LC_ALL, "Turkish");

	Application app;
	app.Run();
}