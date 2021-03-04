#include "light.h"
#include "autoshop.h"


float Light::getRepairCost(const AutoShop& shop)
{
	float cost = 0;
	if (m_isBroken)
	{
		cost += shop.get_lightbulbCost();
		cost += shop.get_screwCost() * 8;
	}
	if (m_isDisconnected)
	{
		cost += shop.get_wireCost() * 4;
		cost += shop.get_screwCost() * 5;
	}
	return float(cost * 100) / 100;
}

std::string Light::diagnose()
{
	std::string diagnostic = "lamp";
	if (m_isBroken)
	{
		diagnostic = "broken " + diagnostic;
	}
	if (m_isDisconnected)
	{
		diagnostic = "disconnected " + diagnostic;
	}
	return diagnostic == "lamp" ? "No problems" : diagnostic;
}

void Light::wear() {
	m_isBroken = rand() % 2;
	m_isDisconnected = rand() % 2;
}


void Light::menu()
{
	int option = 0;
	do {
		std::cout << "	Light Menu:\n - 1. Break lightbulb\n - 2. Disconnect\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: m_isBroken = true;
			break;
		case 2: m_isDisconnected = true;
			break;
		}
	} while (option != 0);
}