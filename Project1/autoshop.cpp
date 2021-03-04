#include "autoshop.h"

float AutoShop::getCostCar()
{
	float cost = 0;
	cost += m_car.get_wheelFL().getRepairCost(*this, true);
	cost += m_car.get_wheelFR().getRepairCost(*this, true);
	cost += m_car.get_wheelRL().getRepairCost(*this, false);
	cost += m_car.get_wheelRR().getRepairCost(*this, false);
	cost += m_car.get_emissions().getRepairCost(*this);
	cost += m_car.get_headlightFL().getRepairCost(*this);
	cost += m_car.get_headlightFR().getRepairCost(*this);
	cost += m_car.get_brakelightRL().getRepairCost(*this);
	cost += m_car.get_brakelightRR().getRepairCost(*this);
	cost += m_car.get_engine().getRepairCost(*this);
	cost += m_car.get_body().getRepairCost(*this);
	return cost;
}


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