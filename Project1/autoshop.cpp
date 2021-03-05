#include "autoshop.h"

void AutoShop::mainMenu()
{
	int option = 0;
	do {
		std::cout << "	Main Menu:\n - 1. Create car\n - 2. Create motorcycle\n - 3. Create bicycle\n - 0. Exit.\n";
		std::cin >> option;
		switch (option)
		{
		case 1: 
			m_car = Car(*this);
			m_car.menu();
			break;
		case 2: 
			m_moto = Moto(*this);
			m_moto.menu();
			break;
		case 3: 
			m_bike = Bike(*this);
			m_bike.menu();
			break;
		}
	} while (option != 0);
}