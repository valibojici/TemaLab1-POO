#include "engine.h"
#include "autoshop.h"


std::string Engine::diagnose()
{
	if (m_hasExtremeDamage)
	{
		return "Destroyed";
	}
	std::string diagnostic = "";
	if (m_lowOilLevel)
	{
		diagnostic += "low oil level; ";
	}
	if (m_engineIsMelted)
	{
		diagnostic += "engine is melted; ";
	}
	if (m_isDirty)
	{
		diagnostic += "engine is dirty; ";
	}
	if (m_batteryIsDischarghed)
	{
		diagnostic += "discharged battery; ";
	}
	return diagnostic == "" ? "No problems" : diagnostic;
}

float Engine::getRepairCost(const AutoShop& shop)
{
	if (m_hasExtremeDamage)
	{
		return 0;
	}
	float cost = 0;
	if (m_engineIsMelted)
	{
		cost += shop.get_manHourCost() * 2.5f;
		cost += shop.get_oilCost() * 2;
		cost += shop.get_screwCost() * 20;
		cost += shop.get_rivetCost() * 10;
		cost += shop.get_steelCost() * 10;
		cost += shop.get_lubricantCost() * 2;
	}

	if (m_lowOilLevel)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_oilCost();
		cost += shop.get_screwCost() * 4;
	}

	if (m_batteryIsDischarghed)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_aluminiumCost() * 3;
		cost += shop.get_screwCost() * 10;
		cost += shop.get_wireCost() * 5;
	}

	if (m_isDirty)
	{
		cost += shop.get_manHourCost() * 1.5f;
		cost += shop.get_cleaningProductsCost() * 2;
		cost += shop.get_screwCost() * 6;
		cost += shop.get_lubricantCost() * 2;
	}
	return round(cost * 100.0f) / 100;
}

void Engine::wear()
{
	m_lowOilLevel = rand() % 2;
	m_engineIsMelted = rand() % 2;
	m_isDirty = rand() % 2;
	m_batteryIsDischarghed = rand() % 2;
	m_hasExtremeDamage = !bool(rand() % 10);
}

void Engine::menu()
{
	int option = 0;
	do {
		std::cout << "	Engine Menu\n";
		std::cout << " - 1. Lower oil level\n - 2. Melt engine\n - 3. Make engine dirty\n - 4. Discharge battery\n - 5. Destroy engine\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1: m_lowOilLevel = true;
			break;
		case 2: m_engineIsMelted = true;
			break;
		case 3: m_isDirty = true;
			break;
		case 4: m_batteryIsDischarghed = true;
			break;
		case 5: m_hasExtremeDamage = true;
			break;
		}
	} while (option != 0);
}