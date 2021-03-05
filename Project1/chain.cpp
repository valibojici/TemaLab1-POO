#include "chain.h"
#include "autoshop.h"

std::string Chain::diagnose()
{
	if (m_isMissing)
	{
		return "missing chain";
	}
	std::string diagnose = "chain";
	if (m_isBroken)
	{
		diagnose = "broken " + diagnose;
	}
	if (m_isWornOut)
	{
		diagnose = "worn out " + diagnose;
	}
	return diagnose == "chain" ? "No problems" : diagnose;
}

float Chain::getRepairCost(const AutoShop& shop, bool isBicycle)
{
	float cost = 0;
	if (m_isWornOut || m_isMissing)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += isBicycle * shop.get_bikeChainCost() + !isBicycle * shop.get_motoChainCost();
		cost += shop.get_lubricantCost();
	}
	else if (m_isBroken)
	{
		cost += shop.get_manHourCost() * 0.5f;
		cost += shop.get_rivetCost() * 5 + shop.get_screwCost() * 10;
		cost += shop.get_lubricantCost();
	}
	return round(cost * 100) / 100;
}

void Chain::wear()
{
	m_isBroken = rand() % 2;
	m_isWornOut = rand() % 2;
	m_isMissing = !bool(rand() % 5);
}

void Chain::menu()
{
	
	int option = 0;
	do {
		std::cout << "	Chain menu:\n";
		std::cout << " - 1. Break chain\n - 2. Wear out chain\n - 3. Missing chain\n - 0. Back\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			m_isBroken = true;
			break;
		case 2:
			m_isWornOut = true;
			break;
		case 3:
			m_isMissing = true;
			break;
		}
	} while (option != 0);
}