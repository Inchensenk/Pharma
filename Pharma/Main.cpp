#include "Pharmacy.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Pharmacy phar = Pharmacy("data.txt");
	phar.menu();

}